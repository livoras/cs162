### Function Pointers
All functions have pointers stored in memory just like variables. Just wrapper a function's name with `(*)`, you will define a function pointer.

```
int swap(int *a, int *b) // function name
int (*swap)(int *a, int *b) // function pointer
typedef int (*swap)(int *a, int *a) // define a type which actually is function pointer with a signature `int (int *, int*)`
```

###  GDB && LLDB command-lines map
http://lldb.llvm.org/lldb-gdb.html

### Checkout include headers in you MacOS
```
clang -E -x c++ -v -
```

### Address of memory

Memories are divided in unit of byte. One byte of memory has its own memory address. So for example, an `int32` variable has 4 units of byte (1 byte = 8 bits). An `int32` variable occupy 4 memory address (0x000, 0x001, 0x002, 0x003). And if you increase the pointer to `int32`, it will pointer to next value by add 4 bytes, which is 0x004 in our example.

```c
int a = 3;
int *ptra = &a; // 0x000
ptra += 1; // 0x001
```

### Stack frames

Functions are implemented by `stack frames`, which is a section of memory storing execution information and data of function calls. And `stack frames` interacts with CPU registers to complete certain kind of computation.

https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Mips/stack.html
