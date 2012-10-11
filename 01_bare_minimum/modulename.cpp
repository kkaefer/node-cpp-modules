#include <node.h>

void RegisterModule(v8::Handle<v8::Object> target) {
    // You can add properties to the module in this function. It is called
    // when the module is required by node.
}

// Register the module with node. Note that "modulename" must be the same as
// the basename of the resulting .node file. You can specify that name in
// binding.gyp ("target_name"). When you change it there, change it here too.
NODE_MODULE(modulename, RegisterModule);
