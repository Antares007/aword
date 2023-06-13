const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const { writeFile, readFile } = require("node:fs/promises");
const { join } = require("node:path");
const colors = {Olive:  0, 
                Fuchsia:1,
                Maroon: 2,
                Lime:   3,
                Navy:   4,
                Blue:   5,
                Green:  6,
                Red:    7,
                Purple: 8,
                Yellow: 9};
parse(process.argv[2]);
async function parse(file = "awords.tab") {
  const input = (await readFile(file)).toString();
  await exec(`rm -rf abin`);
  await exec(`mkdir abin`);
  const rez = await Promise.all(
    input
      .split  (/\.[\n ]/)
      .map    (l => l.trim())
      .filter (l => l.length && !l.startsWith("//"))
      .map    (split_name_and_body)
      .map    (add_missing_rays)
      .map    (compile)
  );
  console.log(rez);
}
function split_name_and_body(l) {
  const p = l.indexOf(" ");
  const n = l.slice(0, p);
  if (l[p + 1] === "{") {
    const b = l.slice(p + 2, l.lastIndexOf("}"));
    return [n, b];
  } else {
    const [n, ...rest] = l.split(/[\n;]/).map(l => l.trim()).filter(Boolean)
    const sc = rest.reduce((d, l) => {
      const p = l.indexOf(' ');
      const maybecname = l.slice(0, p);
      const cname = colors[maybecname] ? maybecname : 'Lime';
      const asent = colors[maybecname] ? l.slice(p+1): l
      if (d[cname]) d[cname].push(asent)
      else d[cname] = [asent]
      return d;
    }, {});
    const b = `${Object.keys(sc).map(c => `
n_t  ${c}_asentences[${sc[c].length}];
long ${c}_current;`).join('\n')}
G(Purple) {
  o[a++] = Purple;
${
  Object
    .keys(sc)
    .map(c => sc[c].map((l, i) => {
      const awords = l.split(' ');
      return `
  o[a++] = "tab";
${awords.map((aword) => `  o[a++] = "${aword}";`).join('\n')}
  o[a++] = "o";
  o[a++] = (void*)${awords.length + 2};
  o[a++] = (void*)&${c}_asentences[${i}];
`;
}).join('  o[a++] = o[2];\n') + `
  ${c}_current = 0;`).join('\n')}
  ((n_t*)o)[2](o, s, a);
}

${Object.keys(sc).map(c => `
G(${c}) {
  n_t aword     = ${c}_asentences[${c}_current];
  ${c}_current  = ${c}_current + (long)o[3];
  o[3]          = (void*)(${c}_current / ${sc[c].length});
  ${c}_current  = ${c}_current - (long)o[3] * ${sc[c].length};
  (o[--s] = ${c}), aword(o, s, a);
}
`).join('\n')}
`;
    return [n, b];
  }
}
function add_missing_rays([n, b]) {
  b = '#include "aw.h"\n' + b;
  const rays = {
    Y: "Yellow",
    P: "Purple",
    R: "Red",
    G: "Green",
    B: "Blue",
    N: "Navy",
    L: "Lime",
    M: "Maroon",
    F: "Fuchsia",
    O: "Olive",
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
  for (let k in rays) b = b + `\nR(${rays[k]}) { ${rays[k]}(o, s, a); }`;
  return [n, b];
}
async function compile([n, b]) {
  await writeFile(n + ".c", b);
  await exec(`gcc -std=gnu17 -Wall -O3 -c ${n}.c -o ${n}.o -ffreestanding -fno-stack-clash-protection -fno-stack-protector`);
  await exec(`ld -T rainbow.ld ${n}.o -o ${n}.elf`);
  await exec(`objcopy -O binary -j .text.* -j .text -j .data ${n}.elf ${n}.bin`);
  let abin = (await readFile(`${n}.bin`));
  abin = abin.slice(5*16)
  abin = abin.slice(0, abin.length - 5*16 - 4);
  await writeFile(`abin/${n}`, abin);
  await exec(`rm ${n}.elf ${n}.o ${n}.bin ${n}.c`);//
  return n;
}
