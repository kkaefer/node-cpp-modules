#include <node.h>

using namespace v8;

// Returns the Nth number in the fibonacci sequence where N is the first
// argument passed.
Handle<Value> Fibonacci(const Arguments& args) {
    HandleScope scope;

    // Check that there are enough arguments. If we access an index that doesn't
    // exist, it'll be Undefined().
    if (args.Length() < 1) {
        // No argument was passed. Throw an exception to alert the user to
        // incorrect usage. Alternatively, we could just use 0.
        return ThrowException(
            Exception::TypeError(String::New("First argument must be a number"))
        );
    }

    // Cast a value to a specific type. See
    // http://izs.me/v8-docs/classv8_1_1Value.html for available To*() functions
    // and type checking functions. When converting to integer, make sure the
    // POD type you use is big enough!
    Local<Integer> integer = args[0]->ToInteger();
    int32_t seq = integer->Value();

    // Also possible in one call. (Don't forget HandleScope, otherwise the
    // intermediate Local handle won't be cleaned up!)
    // int32_t seq = args[0]->ToInteger()->Value();

    // Check for invalid parameter.
    if (seq < 0) {
        return ThrowException(Exception::TypeError(String::New(
            "Fibonacci sequence number must be positive")));
    }

    // The actual algorithm.
    int32_t current = 1;
    for (int32_t previous = -1, next = 0, i = 0; i <= seq; i++) {
        next = previous + current;
        previous = current;
        current = next;
    }

    return scope.Close(Integer::New(current));
}

void RegisterModule(Handle<Object> target) {
    target->Set(String::NewSymbol("fibonacci"),
        FunctionTemplate::New(Fibonacci)->GetFunction());
}

NODE_MODULE(modulename, RegisterModule);
