const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const { writeFile, readFile } = require("node:fs/promises");
const { join } = require("node:path");
parse(process.argv[2]);
async function parse(file = "input.tab") {
  const input = (await readFile(file)).toString();
  const rez = await Promise.all(
    input
      .split("}.\n")
      .map((l) => l.trim())
      .filter(Boolean)
      .map(split_name_and_body)
      .map(add_missing_rays)
      .map(async ([n, b]) => {
        await writeFile(n + ".c", b);
        await exec(
          `gcc -std=gnu99 -Wall -ffreestanding -O3 -c ${n}.c -o ${n}.o`
        );
        await exec(`ld -T ../rainbow.ld ${n}.o -o ${n}.elf`);
        await exec(`objcopy -O binary -j .text -j .data ${n}.elf ${n}.bin`);
        await exec(`tail --bytes=+81 ${n}.bin | head --bytes=-84 > ${n}`);
        await exec(`rm ${n}.elf ${n}.o ${n}.bin`);
      })
  );
}
function split_name_and_body(l) {
  let p = l.indexOf(" ");
  const n = l.slice(0, p);
  p = l.indexOf("{", p + 1);
  const b = l.slice(p + 1);
  return [n, b];
}
function add_missing_rays([n, b]) {
  b = '#include "../aw.h"\n' + b;
  let p = b.indexOf("G(");
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
  while (-1 < p) {
    delete rays[b[p + 2]];
    p = b.indexOf("G(", p + 2);
  }
  for (let k in rays) b = b + `\nG(${rays[k]}) { ${rays[k]}(o, a, s); }`;
  return [n, b];
}
