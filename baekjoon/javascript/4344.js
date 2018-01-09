var input = require('fs').readFileSync('dev/stdin').toString().trim().split('\n');
var arrays = input.map(function (values) {
  return values.split(' ').map(function(value) {
    return parseInt(value);
  });
});
arrays.shift();
function calSum(array) {
  return array.reduce(function (previousItem, currentItem) {
    return previousItem + currentItem;
  });
}
function calAverage(array) {
  return calSum(array) / array.length;
}
function upperAverage(array) {
  var average = calAverage(array);
  return array.filter(function (value) {
    return value > average;
  });
}
function calPercentUpperAverage(array) {
  return (upperAverage(array).length / array.length)*100;
}
arrays.map(function (array) {
  array.shift();
  console.log(calPercentUpperAverage(array).toFixed(3) + '%');
});
