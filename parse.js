function astring(s) {
  const b = Buffer.from(JSON.parse(s));
  let pred = "1";
  for (let i = 0; i < b.length; i++)
    pred += ` && s[${i}] == ${b[i] < 128 ? b[i] : ((256 - b[i]) * -1)}`;
  return `
G(Yellow) { if (${pred}) (o[a++] = ${s}), Yellow    (t, a, b, o, s + ${ b.length});
            else                          Maroon_ray(t, a, b, o, s); }
G(Green ) { if (${pred}) (o[a++] = ${s}), Green     (t, a, b, o, s + ${ b.length});
            else                          Navy_ray  (t, a, b, o, s); }
G(Red   ) {                               Red       (t, a, b, o, s); }
G(Blue  ) {                               Blue      (t, a, b, o, s); }
`
}
function anumber(s) {
  return `
G(Yellow) { o[a++] = "${s}"; Yellow(t, a, b, o, s); }
G(Green ) { o[a++] = "${s}"; Green (t, a, b, o, s); }
`
}
function aword(s) {
  return `
const char* arm_texts[${s.length}];
long        arm_index;
n_t         arm;
N(switch_arm    ) { long narm   = arm_index + 1;
                    long charge = narm / ${s.length};
                    arm_index   = narm - charge * ${s.length};
                    arm         = W(arm_texts[arm_index]);
                    o[--b]      = o[a - charge];
                    TAB_Purple(arm)(t, a - 1, b, o, s); }
N(Yellow_Green  ) { (o[a++] = Yellow), (o[a] = Green), switch_arm(t, a, b, o, s); }
N(Red_Blue      ) { (o[a++] = Red),    (o[a] = Blue),  switch_arm(t, a, b, o, s); }
n_t Tab0[4];
n_t Tab1[4];
n_t Tab2[4];
n_t Tab3[4];
const char*ss;
long sa;
N(Recharge_Navy ) { (o[--b] = Tab0), TAB_Yellow(arm)(t, sa,   b, o, ss); }
G(Yellow        ) { (o[--b] = Tab0), TAB_Yellow(arm)(t, sa=a, b, o, ss=s); }
G(Red           ) { Red_Blue                        (t, a,    b, o, s); }
G(Green         ) { (o[--b] = Tab2), TAB_Green (arm)(t, a,    b, o, s); }
G(Blue          ) { (o[--b] = Tab3), TAB_Blue  (arm)(t, a,    b, o, s); }
N(stop) { Printf("STOP!\\n"); }
G(Purple        ) { 
${s.map((a, i) => `  arm_texts[${i}] = "${a}";`).join('\n')}
  Tab0[0] = Yellow_Green; Tab0[1] = Red_Blue; Tab0[2] = Green;  Tab0[3] = Recharge_Navy;
  Tab2[0] = stop;         Tab2[1] = stop;     Tab2[2] = Green;  Tab2[3] = Blue;
  Tab3[0] = stop;         Tab3[1] = stop;     Tab3[2] = stop;   Tab3[3] = Blue;
  arm    = W(arm_texts[0]);
  o[--b] = Purple;
  TAB_Purple(arm)(t, a, b, o, s);
}
`
}
const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const {writeFile, readFile} = require("node:fs/promises");
const {join} = require("node:path");

parse()

async function parse_awords(cwords) {
  const input = (await readFile("awords.tab")).toString();
  const rez =
      input.split(/\.[\n ]/).map((l) => l.trim()).filter((l) => l.length)
  let name;
  const d = {};
  for (let i = 0; i < rez.length; i++) {
    const s = rez[i];
    const pos = s.indexOf("\n");
    if (pos === -1)
      d[name].push(s);
    else
      d[name = s.slice(0, pos)] = [ s.slice(pos + 1) ]
  }
  const dkeys = Object.keys(d)
  const awords = ([...dkeys, ...cwords ]).reduce((d, s) => {
    if (d[s])
      throw new Error("dublicate");
    d[s] = s
    return d;
  }, {})
  const anon = {};
  const turnToAWords =
      makeToAWordsFun(anonize(anumber, anon), anonize(astring, anon), w => {
        if (!awords[w])
          throw new Error(`not a word '${w}.'`);
        return w;
      });
  const new_awords =
      dkeys.map(n => ([ n, aword(d[n] = d[n].map(turnToAWords)) ]))
  const compiled =
      await Promise
          .all([...Object.keys(anon).map(n => ([ n, anon[n] ])), ...new_awords ]
                   .map(add_missing_rays)
                   .map(compile))
              await Promise.all(dkeys.map(
                  n => exec('cd abin && cat b r o > "b r o" && ' +
                            d[n].map(s => `cat ${s} > "${s}"`).join(" && "))))
  return compiled
}
async function parse() {
  await exec(`rm -rf abin`);
  await exec(`mkdir abin`);
  await exec(`cp aword.h aw.h abin/`);
  const cwords = await parse_and_compile_cwords();
  const awords = await parse_awords(cwords);
  console.log([...cwords, ...awords ])
}
async function parse_and_compile_cwords() {
  const input = (await readFile("cwords.tab")).toString();
  const rez = input.split(/\.\n/).map((l) => l.trim()).filter((l) => l.length)

  const awords = (await Promise.all(
      rez.map(split_name_and_body).map(add_missing_rays).map(compile)));
  return (awords);
}
function split_name_and_body(def) {
  const p = def.indexOf("{");
  if (p === -1)
    throw new Error("cant find {");
  const n = def.slice(0, p);
  const l = def.lastIndexOf("}");
  if (l === -1)
    throw new Error("cant find }");
  const b = def.slice(p + 1, def.lastIndexOf("}"));
  return [ n.trim(), b.trim() ];
}
function add_missing_rays([ n, b ]) {
  b = '#include "aw.h"\n\n' + b;
  const rays = {
    Y : "Yellow",
    P : "Purple",
    R : "Red",
    G : "Green",
    B : "Blue",
    N : "Navy",
    L : "Lime",
    M : "Maroon",
    F : "Fuchsia",
    O : "Olive",
  };
  let pos;
  let i = 0;
  for (let k of Object.keys(rays))
    if (b.indexOf("G(" + rays[k]) + b.indexOf("R(" + rays[k]) === -2)
      b += `\nG(${rays[k]}) { ${rays[k]}(t, a, b, o, s); }`;
  return [ n, b ];
}
async function compile([ n, b ]) {
  await writeFile(n + ".c", b);
  await exec(
      `gcc -std=gnu17 -Wall -O3 -c ${n}.c -o ${n}.o` +
      " -ffreestanding -fno-stack-clash-protection -fno-stack-protector" +
      " && " +
      `ld -T rainbow.ld ${n}.o -o ${n}.elf` +
      " && " +
      `objcopy -O binary -j .text.* -j .text -j .data ${n}.elf ${n}.bin`);
  let abin = await readFile(`${n}.bin`);
  abin = abin.slice(5 * 16);
  abin = abin.slice(0, abin.length - 5 * 16 - 4);
  await writeFile(`abin/${n}`, abin);
  await exec(`mv ${n}.c abin`);              //
  await exec(`rm ${n}.elf ${n}.o ${n}.bin`); //
  return n;
}
function makeToAWordsFun(getNumberName, getStringName, ensureId) {
  return s => parseAText(`tab ${s}`);
  function parseAText(input) {
    input = input.trim()
    if (!input.length) return "o"
    const num = parseNumber(input)
    if (num) return getNumberName(num) + " " +
        parseAText(input.slice(num.length))
    const str = parseQuotedString(input)
    if (str) return getStringName(str) + " " +
        parseAText(input.slice(str.length))
    const id = parseNonWhitespace(input)
    if (id) return ensureId(id) + " " + parseAText(input.slice(id.length))
    else throw new Error();
  };
  function parseQuotedString(input) {
    const regex = /^"([^"]*)"/;
    const match = input.match(regex);
    return match && match[0];
  }
  function parseNumber(input) {
    const regex = /^[-+]?(\d+(\.\d*)?|\.\d+)([eE][-+]?\d+)?/;
    const match = input.match(regex);
    return match && match[0];
  }
  function parseNonWhitespace(input) {
    const regex = /^[^\s]+/;
    const match = input.match(regex);
    return match && match[0];
  }
}
function hashCode(s) {
  let h = 0 | 0;
  for (let i = 0; i < s.length; i++)
    h = 31 * h + s.charCodeAt(i) | 0;
  return h;
}
function anonize(f, anon) {
  return function anonized(s) {
    const n = "aw_" +
              (JSON.parse(s) === "" ? "ε" : JSON.parse(s)); //"A" + hashCode(s);
    if (anon[n])
      return n;
    anon[n] = f(s);
    return n;
  }
}
