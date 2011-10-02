var modulename = {
    fn: function() { return Math.floor(133.7 / Math.PI); }
};

var start = Date.now();
for (var i = 0; i < 1000000; i++) {
    var val = modulename.fn();
    if (val !== 42) throw new Error('invalid result!');
}

console.warn(Date.now() - start);