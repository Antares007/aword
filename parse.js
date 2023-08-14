const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const {writeFile, readFile} = require("node:fs/promises");
const {join} = require("node:path");
parse(process.argv[2]);
async function parse(file = "awords.tab") {
  const input = (await readFile(file)).toString();
  await exec(`rm -rf abin`);
  await exec(`mkdir abin`);
  const rez =
      await Promise.all(input.split(/\.[\n ]/)
                            .map((l) => l.trim())
                            .filter((l) => l.length && !l.startsWith("//"))
                            .map(split_name_and_body)
                            .map(add_missing_rays)
                            .map(compile));
  console.log(rez);
}
function split_name_and_body(l) {
  const p = l.indexOf(" ");
  const n = l.slice(0, p);
  if (l[p + 1] === "{") {
    const b = l.slice(p + 2, l.lastIndexOf("}"));
    return [ n, b ];
  } else {
    throw new Error("n/i")
  }
}
function add_missing_rays([ n, b ]) {
  b = '#include "aw.h"\n' + b;
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
  await exec(`rm ${n}.elf ${n}.o ${n}.bin ${n}.c`); //
  return n;
}
