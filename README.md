# Quark Threads

> `pthread.h` Wrapper for the [Quark Programming Language](https://quar.k.vu)

## [Example Program](test/main.qk)

```cpp
import threads::{ Thread, Mutex };

i32 thread_count = 20;

// input type for threads
struct Payload {
    Mutex<Vec<i32>>* results;
    i32 index;
}

Vec<Thread<int, Payload>> threads = Vec::new();
Mutex<Vec<i32>> results = Mutex::new(Vec::new());

// create each thread and append them to `threads` variable
for(int index = 0; index < thread_count; index++) {
    threads.push(Thread::new(int (Payload payload) {
        // lock the mutex and push a new value to the `results` vector
        Vec<i32>* numbers = payload.results->lock();
        numbers->push(payload.index);

        // unlock the vector and exit the thread
        payload.results->unlock();
        return 0;
    }, Payload { &results, index }));
}

// wait for each thread to complete
for(int i = 0; i < thread_count; i++) threads[i].wait();
threads.free();

Vec<i32> numbers = *results.lock();

for(int n = 0; n < numbers.len(); n++) {
    print_i32(numbers[n]);
}

numbers.free();
results.free();
```

You can see the compiled output of this program in [`test/build/out.c`](test/build/out.c). See the [`Makefile`](makefile) for a compilation example. *Note `$QUARK_LIB` is specified as the `lib/` directory on your clone, not the root (see `important` label in [Quark `0.5.5pre`](https://github.com/quark-programming/quark/releases/tag/0.5.5pre))*.

### Extra

> [Quark `0.5.5pre`](https://github.com/quark-programming/quark/releases/tag/0.5.5pre) or see [latest](https://github.com/quark-programming/quark/releases)
