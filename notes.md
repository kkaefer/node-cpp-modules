basic module
- registering with node (v0.5!): `NODE_MODULE`
- When running `NODE_MODULE(sqlite3_bindings, RegisterModule);`, "sqlite3_bindings" must be the same as the basename of the resulting .node file
- basic wscript file

General recommendations
- use clang to develop and gcc to test

add a function
- putting it into the module's exports
- HandleScope
- Handle vs. Local vs. Persistent
- handles == auto_ptr?

parsing arguments
- V8's Value object tree
- ThrowException

callback functions
- call synchronously (called before original function returns!)

threadpool
- libuv
- creating Batons to store request information
- uv_ref() so  that node doesn't stop looping before
- don't call V8 stuff in the threadpool!


designing a good API
- asynchronous?
  ==> for IO or CPU heavy tasks
- chainable
- EventEmitter as base class
- object vs. function
- when wrapping other libs, include their version


creating objects
- inheriting from node::ObjectWrap
- Wrapping/Unwrapping
- adding instance functions
- adding getters/setters
- v8::AdjustAmountOfExternalAllocatedMemory()

EventEmitter
- inheriting from an eventemitter
- emitting events, responding to events

speed
- how fast is crossing the JS/C++ boundary?
- don't copy around buffers
- increase thread count (default is 4)
- instanciating C objects (pooling?)


general C++ advice
- use std library, tr1 (shared_ptr)

node-waf/wscript
- looking for 3rd party lib
- linking against a 3rd party lib

installing with npm
- npm knows to call node-waf automatically

upgrading from 0.4
- EventEmitter removed from C++
- libev/libeio --> libuv
- `rm -rf /usr/local/include/node /usr/local/lib/node /usr/local/bin/node-waf` and reinstall to clean up old cruft

debugging
- Instruments: memory leaks

Issues
- multiple copies of the same C++ extension don't play nice



RESEARCH TASKS
- JS/C++ boundary
- retain buffers, buffer deleter
- inheriting from EventEmitter

