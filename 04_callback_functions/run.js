var modulename = require('./build/Release/modulename');

modulename.callback(false, function(err, result) {
    console.warn(result);
});
