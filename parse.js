function astring(s) {
  const b = Buffer.from(JSON.parse(s));
  let pred = "1";
  for (let i = 0; i < b.length; i++)
    pred += ` && s[${i}] == ${b[i] < 128 ? b[i] : ((256 - b[i]) * -1)}`;
  return `
G(Yellow) {              (o[a++] = ${s}), Yellow(t, a, b, o, s); }
G(Green ) {              (o[a++] = ${s}), Green (t, a, b, o, s); }
G(Red   ) { if (${pred}) (o[a++] = ${s}), Red   (t, a, b, o, s + ${b.length});
            else                          Olive (t, a, b, o, s); }
G(Blue  ) { if (${pred}) (o[a++] = ${s}), Blue  (t, a, b, o, s + ${b.length});
            else                          Lime  (t, a, b, o, s); }
`
}
function anumber(s) {
  return `
G(Yellow) { o[a++] = ${s}; Yellow(t, a, b, o, s); }
G(Green ) { o[a++] = ${s}; Green (t, a, b, o, s); }
`
}
function aword(s) {
  return `
const char *arm_texts[${s.length}];
long        arm_index;
n_t         arm;
N(switch_arm    ) { long narm   = arm_index + 1;
                    long charge = narm / ${s.length};
                    arm_index   = narm - charge * ${s.length};
                    arm         = W(arm_texts[arm_index]);
                    o[--b]      = charge + 1;
                    TAB_Purple(arm)(t, a, b, o, s); }
N(Yellow_Navy   ) { Blue(t, a, b, o, s); }
N(Yellow_Lime   ) { Green(t, a, b, o, s); }
N(Yellow_Maroon ) { (o[--b] = Red),    (o[--b] = Blue),  switch_arm(t, a, b, o, s); }
N(Yellow_Olive  ) { (o[--b] = Yellow), (o[--b] = Green), switch_arm(t, a, b, o, s); }
G(Yellow        ) { o[--b]  = Yellow_Navy;
                    o[--b]  = Yellow_Lime;
                    o[--b]  = Yellow_Maroon;
                    o[--b]  = Yellow_Olive;
                    TAB_Yellow(arm)(t, a, b, o, s); }
N(Green_Navy    ) { Blue(t, a, b, o, s); }
N(Green_Lime    ) { Green(t, a, b, o, s); }
N(Green_Maroon  ) { Printf("Stop!\\n"); }
N(Green_Olive   ) { Printf("Stop!\\n"); }
G(Green         ) { o[--b]  = Green_Navy;
                    o[--b]  = Green_Lime;
                    o[--b]  = Green_Maroon;
                    o[--b]  = Green_Olive;
                    TAB_Green(arm)(t, a, b, o, s); }
long saved_a; char*saved_s;
N(Red_Navy      ) { Blue(t, a, b, o, s); }
N(Red_Lime      ) { Green(t, saved_a, b, o, saved_s); }
N(Red_Maroon    ) { (o[--b] = Red),    (o[--b] = Blue),  switch_arm(t, a, b, o, s); }
N(Red_Olive     ) { (o[--b] = Yellow), (o[--b] = Green), switch_arm(t, saved_a, b, o, saved_s); }
G(Red           ) { o[--b]  = Red_Navy;
                    o[--b]  = Red_Lime;
                    o[--b]  = Red_Maroon;
                    o[--b]  = Red_Olive;
                    TAB_Red(arm)(t, saved_a = a, b, o, saved_s = s); }
N(Blue_Navy     ) { Blue(t, a, b, o, s); }
N(Blue_Lime     ) { Green(t, saved_a, b, o, saved_s); }
N(Blue_Maroon   ) { Printf("Stop!\\n"); }
N(Blue_Olive    ) { Printf("Stop!\\n"); }
G(Blue          ) { o[--b]  = Blue_Navy;
                    o[--b]  = Blue_Lime;
                    o[--b]  = Blue_Maroon;
                    o[--b]  = Blue_Olive;
                    TAB_Blue(arm)(t, saved_a = a, b, o, saved_s = s); }
G(Purple        ) {
${s.map((a, i) => `  arm_texts[${i}] = "${a}";`).join('\n')}
  arm     = W(arm_texts[0]);
  o[--b]  = Purple;
  o[--b]  = Purple;
  o[--b]  = 1;
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
  for (let k of Object.keys(rays))
    if (b.indexOf("G(" + rays[k]) + b.indexOf("R(" + rays[k]) === -2)
      b += `\nR(${rays[k].padEnd(8, ' ')}) { ${
          rays[k].padEnd(8, ' ')}(t, a, b, o, s); }`;
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
    const n = "A" + hashCode(s);
    if (anon[n])
      return n;
    anon[n] = f(s);
    return n;
  }
}
