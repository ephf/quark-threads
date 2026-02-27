# Quark Threads

> `pthread.h` Wrapper for the [Quark Programming Language](https://quar.k.vu)

## Example Program

```cpp
import threads::{ Thread };

// Note: return types and argument types are required
Thread<int, int> thread = Thread::new(int (int ignore) {
    print("Hello World!");
    return 0;
}, 5);

thread.wait();
```

You can see the compiled output of this program in [`test/build/out.c`](test/build/out.c). See the [`Makefile`](makefile) for a compilation example. *Note `$QUARK_LIB` is specified as the `lib/` directory on your clone, not the root (see `important` label in [Quark `0.5.3pre`](https://github.com/quark-programming/quark/releases/tag/0.5.3pre))*.

### Extra

> [Quark `0.5.3pre`](https://github.com/quark-programming/quark/releases/tag/0.5.3pre) or see [latest](https://github.com/quark-programming/quark/releases)
