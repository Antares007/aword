function astring(s) {
  const b = Buffer.from(JSON.parse(s));
  let pred = "1";
  for (let i = 0; i < b.length; i++)
    pred += ` && s[t + ${i}] == ${b[i] < 128 ? b[i] : ((256 - b[i]) * -1)}`;
  return `
G(Yellow) { if ((${pred})) (o[a++] = ${s}), Yellow(t + ${b.length}, a, b, o, s);
            else            Red(t, a, b, o, s); }
G(Green ) { if ((${pred})) (o[a++] = ${s}), Green(t + ${b.length}, a, b, o, s);
            else            Blue(t, a, b, o, s); }
`
}
function anumber(s) {
  return `
G(Yellow) { o[a++] = "${s}"; Yellow(t, a, b, o, s); }
G(Green ) { o[a++] = "${s}"; Green (t, a, b, o, s); }
`
}
function tword(s, id) {
  return `
n_t Tab_Yellow[6];
n_t Tab_Green [6];
n_t Tab_Red   [6];
n_t Tab_Blue  [6];
long arms_count = ${s.length};
n_t arms[${s.length}];
const char *arm_texts[${s.length}];
long ai;
N(Switch_arm) {
  long narm   = ai + 1;
  long charge = narm / arms_count;
           ai = narm - charge * arms_count;
  ((n_t)o[a - charge])(t, a - 1, b, o, s);
}
N(tab) {
  long color  = ((long*)o[b])[5];
  if(arms[ai])
    (arms[ai] + color)(t, a, b, o, s);
  else
    (arms[ai] = Bark(arm_texts[ai])),
    (o[--b]   = (void*)__FILE__),
    (o[--b]   = arms[ai] + color),
    (arms[ai](t, a, b, o, s));
}
char fruitful[${s.length}];
char is_open;
G(Yellow            ) { is_open = 1; (o[--b] = Tab_Yellow), tab(t, a, b, o, s); }
G(Green             ) { is_open = 1; (o[--b] = Tab_Green),  tab(t, a, b, o, s); }
G(Red               ) { if (is_open) (o[--b] = Tab_Red),    tab(t, a, b, o, s); else Red(t, a, b, o, s); }
G(Blue              ) { if (is_open) (o[--b] = Tab_Blue),   tab(t, a, b, o, s); else Blue(t, a, b, o, s); }


N(Yellow_tab_Olive) { fruitful[ai] = 1; (o[a++] = Yellow), (o[a] = Green), Switch_arm(t, a, b, o, s); }
N(Yellow_tab_Lime ) { fruitful[ai] = 1; Green(t, a, b, o, s); }
N(Red_trim        ) { if (1 < arms_count) arms_count--,
                                          Unbark(arms[arms_count], ((long*)arms[arms_count])[1]),
                                          Red(t, a, b, o, s);
                      else maroon(t, a, b, o, s); }
N(Blue_trim       ) { arms_count--;
                      ai--;
                      Unbark(arms[ai], ((long*)arms[ai])[1]);
                      for (long i     = ai; i < arms_count; i++) {
                        arms[i]       = arms[i + 1];
                        arm_texts[i]  = arm_texts[i + 1];
                        fruitful[i]   = fruitful[i + 1];
                      }
                      Blue(t, a, b, o, s); }
N(Yellow_tab_Maroon
                  ) { if (fruitful[ai]) (o[a++] = Red), (o[a] = Blue);
                      else (o[a++] = Red_trim), (o[a] = Blue_trim);
                      Switch_arm(t, a, b, o, s); }
N(Yellow_tab_Navy ) { Blue(t, a, b, o, s); }

N(Green_tab_Olive ) { P; }
N(Green_tab_Lime  ) { fruitful[ai] = 1; Green(t, a, b, o, s); }
N(Green_tab_Maroon) { P; }
N(Green_tab_Navy  ) { Blue(t, a, b, o, s); }

N(Red_tab_Olive     ) { P; }
N(Red_tab_Lime      ) { P; }
N(Red_tab_Maroon    ) { (o[a++] = Red), (o[a] = Blue), Switch_arm(t, a, b, o, s); }
N(Red_tab_Navy      ) { Blue(t, a, b, o, s); }

N(Blue_tab_Olive  ) { P; }
N(Blue_tab_Lime   ) { P; }
N(Blue_tab_Maroon ) { P; }
N(Blue_tab_Navy   ) { Blue(t, a, b, o, s); }

G(Purple) {
  is_open       = 0;
${s.map((a, i) => `  arm_texts[${i}] = "${a}"; fruitful[${i}] = 0;`).join('\n')}
  Tab_Yellow[0] = Yellow_tab_Olive;
  Tab_Yellow[1] = Yellow_tab_Lime;
  Tab_Yellow[2] = Yellow_tab_Maroon;
  Tab_Yellow[3] = Yellow_tab_Navy;
  Tab_Yellow[4] = (void*)__FILE__;
  Tab_Yellow[5] = (void*)0x20;

  Tab_Green [0] = Green_tab_Olive;
  Tab_Green [1] = Green_tab_Lime;
  Tab_Green [2] = Green_tab_Maroon;
  Tab_Green [3] = Green_tab_Navy;
  Tab_Green [4] = (void*)__FILE__;
  Tab_Green [5] = (void*)0x40;

  Tab_Red   [0] = Red_tab_Olive;
  Tab_Red   [1] = Red_tab_Lime;
  Tab_Red   [2] = Red_tab_Maroon;
  Tab_Red   [3] = Red_tab_Navy;
  Tab_Red   [4] = (void*)__FILE__;
  Tab_Red   [5] = (void*)0x60;

  Tab_Blue  [0] = Blue_tab_Olive;
  Tab_Blue  [1] = Blue_tab_Lime;
  Tab_Blue  [2] = Blue_tab_Maroon;
  Tab_Blue  [3] = Blue_tab_Navy;
  Tab_Blue  [4] = (void*)__FILE__;
  Tab_Blue  [5] = (void*)0x80;

  Purple(t, a, b, o, s);
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
      dkeys.map((n, i) => ([ n, tword(d[n] = d[n].map(turnToAWords), i) ]))
  const compiled =
      await Promise
          .all([...Object.keys(anon).map(n => ([ n, anon[n] ])), ...new_awords ]
                   .map(add_missing_rays)
                   .map(compile))
              await Promise.all(dkeys.map(
                  n => exec(
                      'cd abin && cat b r o > "b r o" && cat b o > "b o"  && ' +
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
    P : "Purple",   p : "purple",
    Y : "Yellow",   y : "yellow",
    G : "Green",    g : "green",
    R : "Red",      r : "red",
    B : "Blue",     b : "blue",
    N : "Navy",     n : "navy",
    M : "Maroon",   m : "maroon",
    L : "Lime",     l : "lime",
    O : "Olive",    o : "olive",
    F : "Fuchsia",  f : "fuchsia",
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
  abin = abin.slice(5 * 32);
  abin = abin.slice(0, abin.length - 5 * 32 - 4);
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
