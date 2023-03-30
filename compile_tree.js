const util = require("node:util");
const exec = util.promisify(require("node:child_process").exec);
const { lstat, writeFile } = require("node:fs/promises");
const exists = async (f) => {
  try {
    await lstat(f);
    return true;
  } catch (e) {
    return false;
  }
};
const { join } = require("node:path");
const compile = require("./compile.js");
const empty = "4b825dc642cb6eb9a060e54bf8d69288fbee4904";
setup(process.argv[2]);
async function setup(hash) {
  await compile("b.c", "b");
  await compile("m.c", "m");
  await compile("o.c", "o");
  await exec("rm -rf precompile");
  await exec("mkdir precompile");
  await precompile(hash);
  await exec("git add precompile/aword")
  const sha1 = (await exec("git write-tree --prefix=precompile/aword")).stdout.trim()
}
async function precompile(hash, path = "aword") {
  await exec(`mkdir -p ${join("precompile", path)}`);
  await Promise.all(
    (
      await lsTree(hash)
    ).map(async (e) => {
      if (e.type === "blob" && e.name.endsWith("c")) {
        const c = join(path, e.name);
        const o = join("precompile", path, e.name);
        await exec(`gcc -E -P -DTPATH="${path}" -DTNAME="${e.name}" ${c} > ${o}`);
      } else if (e.type == "tree") {
        await precompile(e.hash, join(path, e.name));
      }
    })
  );
}
async function compileTree(hash, path = "aword") {
  if (empty == hash) {
    await compileBlob("m.c", hash);
  } else if (await exists(await binPath(hash)));
  else {
    const list = await Promise.all(
      (
        await lsTree(hash)
      )
        .filter((e) => e.type === "blob" || e.type === "tree")
        .filter((e) => e.name.endsWith("c")) // TODO: we need to invert compilation
        .map(async (e) => {
          if (e.type === "blob") await compileBlob(join(path, e.name), e.hash);
          else await compileTree(e.hash, join(path, e.name));
          return e;
        })
    );
    if (list.length == 1)
      await exec(`cp ${await binPath(list[0].hash)} ${await binPath(hash)}`);
    else {
      await reducetree(list, path, hash);
    }
  }
}
async function reducetree(list, base_path, base_hash) {
  const js = "S.c";
  await writeFile(
    js,
    `#include "aword/rays.h"
Ray(Blue___) { P(S), Blue(o, a); }
Ray(Green__) { P(S), Green(o, a); }
Ray(Red____) { P(S), Red(o, a); }
Ray(Yellow_) { P(S), Yellow(o, a); }
Ray(Purple_) { P(S), Purple(o, a); }
Ray(Aqua___) { P(S), Aqua(o, a); }
Ray(Lime___) { P(S), Lime(o, a); }
Ray(Maroon_) { P(S), Maroon(o, a); }
typedef void (*t_t)(void **, long);
t_t (*load_tree)(const char *hash);
t_t t0;
Ray(Olive__) { P(S), (t0 - 16 * 4)(o, a); }
Ray(Pink___) { P(S),
  load_tree = o[2];
${list
  .map((e, i) =>
    i
      ? `
  o[a++] = (t0 - 16 * 5);
  o[a++] = (t0 - 16 * 4);
  t0 = load_tree("${e.hash}");`
      : `
  print("--- %x %s\\n", t0, "${e.hash}");
  o[a++] = Pink;
  o[a++] = Olive;
  t0 = load_tree("${e.hash}");
`
  )
  .join("\n")}
  (t0 - 16 * 5)(o, a);
}`
  );
  await compileBlob(js, base_hash);
  //  await exec(`rm -f ${js}`);
}
async function compileBlob(c, hash) {
  const aword_path = await binPath(hash);
  if (await exists(aword_path)) return;
  const m = c + ".aword";
  await compile(c, m);
  await exec(`cat b ${m} o > ${aword_path}`);
  await exec(`rm ${m}`);
}
async function lsTree(hash) {
  return (await exec(`git ls-tree -z ${hash}`)).stdout
    .split("\0")
    .filter(Boolean)
    .map((l) => {
      const [rec, name] = l.split("\t");
      const [mode, type, hash] = rec.split(" ");
      return { name, mode, type, hash };
    });
}
async function binRoom(hash) {
  const room = join("cadb", hash.slice(0, 2));
  if (!(await exists(room))) await exec(`mkdir -p ${room}`);
  return room;
}
async function binPath(hash) {
  return join(await binRoom(hash), hash.slice(2));
}
