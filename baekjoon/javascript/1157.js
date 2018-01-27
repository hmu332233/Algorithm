var input = require('fs').readFileSync('dev/stdin').toString().trim().split('');

var count = {};
input.forEach(function (v) {
  v = v.toUpperCase();
  if (count[v]) {
    count[v] += 1;
  } else {
    count[v] = 1;
  }
});

var key1 = Object.keys(count).reduce(function(a, b) {
  return (count[a] > count[b] ? a : b);
});
var key2 = Object.keys(count).reduce(function(a, b) {
  return (count[a] >= count[b] ? a : b);
});

console.log(key1 !== key2 ? '?' : key1);
// 너무 비효율...
