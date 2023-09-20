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
  const getNumberName = (s) => {
    const n = `N${hashCode(s)}`;
    if (anon[n])
      return n
      anon[n] = `G(Green) { P; o[a++] = ${s}; Green(t, a, b, o, s); }`
      return n;
  };
  const getStringName = (s) => {
    const n = `S${hashCode(s)}`;
    if (anon[n])
      return n;
    console.log(n, s);
    const b = Buffer.from(JSON.parse(s));
    let pred = "1";
    for (let i = 0; i < b.length; i++)
      pred = pred + ` && s[${i}] == ${b[i] < 128 ? b[i] : ((256 - b[i]) * -1)}`;
    anon[n] = `G(Green) { Printf("%s\\n", ${s}); if (${pred}) (o[a++] = ${
        s}), Green(t, a, b, o, s + ${b.length}); else Blue(t, a, b, o, s); }`
    return n;
  };
  const ensureId = w => {
    if (!awords[w])
      throw new Error(`not a word '${w}.'`);
    return w;
  };
  const turnToAWords = makeToAWordsFun(getNumberName, getStringName, ensureId);
  const new_awords =
      dkeys.map(n => ([ n, addBodyForTWord(d[n].map(turnToAWords)) ]))
  return Promise.all([
    ...Object.keys(anon).map(n => ([ n, anon[n] ])), ...new_awords
  ].map(add_missing_rays).map(compile))
}
function addBodyForTWord(atexts) {
  return `long        arm_index;
n_t         arm;
const char *atexts[${atexts.length}];
N(Olive_connect) {
  if (t) {
    long narm = arm_index + t;
    t = narm / ${atexts.length};
    arm_index = narm - t * ${atexts.length};
    arm = W(atexts[arm_index]);
    T(Maroon, Green, Maroon), (arm + 16)(t, a, b, o, s);
  } else {
    Green(t, a, b, o, s);
  }
}
const char*saved_s;
long saved_a;
N(Navy_connect ) {
  if (t) {
    // this arm is fully rotated lets try next arm with
    // saved state or conitinue with charged Blue
    if (arm_index < ${atexts.length - 1}) {
      arm = W(atexts[++arm_index]);
      T(Maroon, Green_ray, Maroon);
      (arm + 16)(t, saved_a, b, o, saved_s);
    } else {
      Blue(t, saved_a, b, o, saved_s);
    }
  } else {
    // we need to go in on next T charge or do
    // somthing else after OR junction recharges T
    Blue(t, saved_a, b, o, saved_s);
  }
}
G(Green        ) { P_;
  if (t) {
    saved_a = a;
    saved_s = s;
    T(Red, Olive_connect, Navy_connect);
  } else {
    T(Red, Green, Blue);
  }
  arm(t, a, b, o, s);
}
G(Purple      ) { P;
${atexts.map((atext, i) => `  atexts[${i}] = "tab ${atext}o";`).join('\n')}
  arm = W(atexts[0]);
  T(Maroon, Purple, Maroon), (arm + 16)(t, a, b, o, s);
}
`
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
  const deleteDefinedRays = (type) => {
    let p = b.indexOf(type + "(");
    while (-1 < p) {
      delete rays[b[p + 2]];
      p = b.indexOf(type + "(", p + 2);
    }
  };
  deleteDefinedRays("G");
  deleteDefinedRays("R");
  for (let k in rays)
    b = b + `\nG(${rays[k].padEnd(8, ' ')}) { ${
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
  return function parseAText(input) {
    input = input.trim()
    if (!input.length) return ""
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
