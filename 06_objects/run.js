var modulename = require('./build/Release/modulename');

var obj = new modulename.MyObject(42);
console.warn(obj);
console.warn(obj.value());
