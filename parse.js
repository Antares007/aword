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
  return Promise.all(dkeys.map(n => {
    const atexts = d[n].map(s => s.split(/[\n ]/)
                                     .map(w => w.trim())
                                     .filter(Boolean)
                                     .map(w => {
                                       if (!awords[w])
                                         throw new Error(`not a word '${w}.'`);
                                       return w;
                                     })
                                     .join(' '));
    const initatexts = (atext, i) => `  atext[${i}] = W("tab ${
        atext} o");\n  (atext[${i}] + 16)(t, a, b, o, s);`

    const b = `
long arm;
n_t atext[${atexts.length}];
G(Purple) { P;
  arm = 0;
${atexts.map(initatexts).join('\n')}
  Purple(t, a, b, o, s);
}
N(Olive_connect) {
  long narm = arm + t;
  t = narm / ${atexts.length};
  arm = narm - t * ${atexts.length};
  Green(t, a, b, o, s);
}
N(Navy_connect) {
  Blue(t, a, b, o, s);
}
G(Green) { P;
  o[--s] = Red;
  o[--s] = Olive_connect;
  o[--s] = Navy_connect;
  atext[arm](t, a, b, o, s);
}
`
    return compile(add_missing_rays([ n, b ]))
  }))
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
  if (b.indexOf("Tword") != -1) {
    delete rays["G"];
    delete rays["P"];
  } else {
    const deleteDefinedRays = (type) => {
      let p = b.indexOf(type + "(");
      while (-1 < p) {
        delete rays[b[p + 2]];
        p = b.indexOf(type + "(", p + 2);
      }
    };
    deleteDefinedRays("G");
    deleteDefinedRays("R");
  }
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
