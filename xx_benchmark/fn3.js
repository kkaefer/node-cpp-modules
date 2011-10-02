var modulename = require('./build/Release/modulename');

var start = Date.now();
for (var i = 0; i < 1000000; i++) {
    modulename.fn3(function(err, val) {
        if (val !== 42) throw new Error('invalid result!');
    });
}

console.warn(Date.now() - start);