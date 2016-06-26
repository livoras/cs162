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

This can answer the question of why 32-bit system support memory less than 4GB. This because CPU only use 32 bits to identify all bytes in memory, 2 ^ 32 bytes is 4GB.

### Stack frames

Functions are implemented by `stack frames`, which is a section of memory storing execution information and data of function calls. And `stack frames` interacts with CPU registers to complete certain kind of computation.

https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Mips/stack.html

### Memory segments
A program's memory is made up of four kind of segments.

1. code segment
2. data segment
3. heap segment
4. stack segment

```
+-----------+
|           |
|   text    | (fixed size)
|           |
+-----------+
|           |
|   data    | (fixed size)
|           |
+-----------+
|   stack   | | growth
+-----------+ V
|           |
|   free    |
|           |
+-----------+ ^
|   heap    | | growth
+-----------+
```
Refs: http://www.cs.uwm.edu/classes/cs315/Bacon/Lecture/HTML/ch10s04.html
