#include <node/v8.h>
#include <node/node.h>

// C standard library
#include <cstdlib>
#include <ctime>

using namespace v8;

// This function returns a JavaScript number that is either 0 or 1.
Handle<Value> Random(const Arguments& args) {
    // At the top of every function that uses anything about v8, include a
    // definition like this. It ensures that any v8 handles you create in that
    // function are properly cleaned up. If you see memory rising in your
    // application, chances are that a scope isn't properly cleaned up.
    HandleScope scope;

    // When returning a value from a function, make sure to wrap it in
    // scope.Close(). This ensures that the handle stays valid after the current
    // scope (declared with the previous statement) is cleaned up.
    return scope.Close(
        // Creating a new JavaScript integer is as simple as passing a C int
        // (technically a int32_t) to this function.
        Integer::New(rand() % 2)
    );
}

void RegisterModule(Handle<Object> target) {
    srand(time(NULL));

    // target is the module object you see when require()ing the .node file.
    target->Set(String::NewSymbol("random"),
        FunctionTemplate::New(Random)->GetFunction());
}

NODE_MODULE(modulename, RegisterModule);
