const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const { writeFile, readFile } = require("node:fs/promises");
const { join } = require("node:path");
parse(process.argv[2]);
async function parse(file = "input.tab") {
  const input = (await readFile(file)).toString();
  const rez = await Promise.all(
    input
      .split(".\n")
      .map((l) => l.trim())
      .filter((l) => l.length && !l.startsWith("//"))
      .map(split_name_and_body)
      .map(add_missing_rays)
      .map(compile)
  );
}
async function split_name_and_body(l) {
  const p = l.indexOf(" ");
  const n = l.slice(0, p);
  const p2 = l.indexOf("{", p + 1);
  if (-1 < p2) {
    const b = l.slice(p2 + 1, l.lastIndexOf("}"));
    return [n, b];
  } else {
    const p = l.indexOf("\n");
    const n = l.slice(0, p).trim();
    const b = await Promise.all(
      l
        .slice(p + 1)
        .split(";")
        .map(
          async (x) =>
            await Promise.all(
              x
                .split(" ")
                .map((x) => x.trim())
                .filter(Boolean)
                .map(wrap_nouns)
            )
        )
    );
    return [
      n,
      `
  n_t branches[${b.length}];
  long branches_length;
  long cb;
  G(Purple) {
    if (!branches_length) {
      c_t compose = ο[2];
      cb = 0;
${b
  .map((atext, i) => {
    return `      branches[${i}] = compose((const char*[]){${atext.join(
      ","
    )}}, ${atext.length});
      (branches[${i}] + 16)(ο, σ, α, ρ);`;
  })
  .join("\n")}
      branches_length = ${b.length};
    }
    ((void (*)(const char *, ...))ο[0])("%s %s\\n", __FILE__, __FUNCTION__);
    Purple(ο, σ, α, ρ);
  }
  G(Lime) {
    ο[σ++]  = Lime;
    long nb = cb;
    cb     += ρ;
    long lb = cb / branches_length;
    cb      = cb - lb * branches_length;
    branches[nb](ο, σ, α, ρ);
  }
`,
    ];
  }
}
async function add_missing_rays(pro) {
  let [n, b] = await pro;
  b = '#include "../aw.h"\n' + b;
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
  for (let k in rays) b = b + `\nR(${rays[k]}) { ${rays[k]}(ο, σ, α, ρ); }`;
  return [n, b];
}
async function compile(pro) {
  let [n, b] = await pro;
  await writeFile(n + ".c", b);
  await exec(
    `gcc -std=gnu17 -Wall -O3 -c ${n}.c -o ${n}.o \
-ffreestanding -fno-stack-clash-protection -fno-stack-protector`
  );
  await exec(`ld -T ../rainbow.ld ${n}.o -o ${n}.elf`);
  await exec(
    `objcopy -O binary -j .text.* -j .text -j .data ${n}.elf ${n}.bin`
  );
  await exec(`tail --bytes=+81 ${n}.bin | head --bytes=-84 > ${n}`);
  await exec(`rm ${n}.elf ${n}.o ${n}.bin`);
}
async function wrap_nouns(x) {
  return `"${x}"`;
}
