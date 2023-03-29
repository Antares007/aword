#!/usr/bin/node
const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const { writeFile, readFile } = require("node:fs/promises");
module.exports = acton;
if (require.main === module) acton(process.argv[2], process.argv[3]);
async function acton(c, o) {
  await exec(`gcc -std=gnu17 -Wall -ffreestanding -O3 -c ${c} -o ${o}.o`);
  await exec(`ld -T b5o5.ld ${o}.o -o ${o}.elf`);
  await exec(`objcopy -O binary -j .text.* -j .text -j .data ${o}.elf ${o}`);
  await exec(`rm -f ${o}.o ${o}.elf`);
  await writeFile(o, (await readFile(o)).slice(5 * 16, -(5 * 16 + 4)));
}
