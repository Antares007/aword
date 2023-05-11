const fs = require("fs");
const j = fs.readFileSync("../sample.json").toString();
function getTime() {
  const hrTime = process.hrtime();
  return hrTime[0] + hrTime[1] / 1e9;
}
const fun = () => {
  const startTime = getTime();
  JSON.parse(j);
  const endTime = getTime();
  const executionTime = endTime - startTime;
  return executionTime;
};
const runs = [
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
  fun(),
];
console.log(runs.reduce((s, a) => s + a, 0) / runs.length);
const cruns = [
  0.000198, 0.000194, 0.000194, 0.000193, 0.000193, 0.000193, 0.000193,
  0.000193, 0.000208, 0.0002, 0.000198, 0.000199, 0.000198,
];
console.log(cruns.reduce((s, a) => s + a, 0) / cruns.length);
// 0.0011423286403961746 / 0.00019646153846153845 = 5.8145153974747

//0.000002
//0.00001700678382933672
