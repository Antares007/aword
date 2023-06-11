const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const { writeFile, readFile } = require("node:fs/promises");
const { join } = require("node:path");
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
    const b = `
const char*asentences[${rest.length}];
long current, charge, Blue_s;
G(Purple) {
${rest.map((l,i) => `  asentences[${i}] = "tab ${l} o";`).join('\n')}
  current = 0;
  Purple(a, o, s);
}
N(Lime_switch);
N(Lime_next  ) { Blue_s++; Lime_switch((long)o[s - 1], o, s); }
N(Lime_switch) {
  void (*T)(long, void*, long, const char*) = o[2];
  const char*asen = asentences[current];
  current   = (current + charge) % ${rest.length};
  o[--s]    = (void*)a;
  o[--s]    = Lime;
  o[--s]    = ${rest.length} == Blue_s ? Navy : Lime_next;
  T(a, o, s, asen);
}
G(Lime       ) {
  charge    = (long)o[3];
  o[3]      = (void*)(long)(current + charge == ${rest.length});
  Blue_s    = 0;
  Lime_switch(a, o, s);
}
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
  for (let k in rays) b = b + `\nR(${rays[k]}) { ${rays[k]}(a, o, s); }`;
  return [n, b];
}
async function compile([n, b]) {
  await writeFile(n + ".c", b);
  await exec(`gcc -std=gnu17 -Wall -O3 -c ${n}.c -o ${n}.o -ffreestanding -fno-stack-clash-protection -fno-stack-protector`);
  await exec(`ld -T rainbow.ld ${n}.o -o ${n}.elf`);
  await exec(`objcopy -O binary -j .text.* -j .text -j .data ${n}.elf ${n}.bin`);
  await exec(`tail --bytes=+81 ${n}.bin | head --bytes=-84 > abin/${n}`);
  await exec(`rm ${n}.elf ${n}.o ${n}.bin ${n}.c`);
  return n;
}
