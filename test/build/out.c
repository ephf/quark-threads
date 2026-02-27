// Quark Version 0.5pre
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"
#include "errno.h"
#include "pthread.h"
int main();
struct vector__Vec__int32_t { int32_t* data; size_t size; size_t capacity; };
struct threads__Mutex__struct_Vec__int32_t { pthread_mutex_t mutex; struct vector__Vec__int32_t value; };
struct threads__Mutex__struct_Vec__int32_t;
struct Payload { struct threads__Mutex__struct_Vec__int32_t* results; int32_t index; };
typedef int (*__Function__threads__StartRoutine__number__struct_Payload____qlambda1)(struct Payload);
struct Payload;
struct threads__StartRoutine__number__struct_Payload { __Function__threads__StartRoutine__number__struct_Payload____qlambda1 callback; struct Payload argument; int retval; };
struct threads__StartRoutine__number__struct_Payload;
struct threads__Thread__number__struct_Payload { pthread_t tid; struct threads__StartRoutine__number__struct_Payload* start_routine; };
struct threads__Thread__number__struct_Payload;
struct vector__Vec__struct_Thread__number__struct_Payload { struct threads__Thread__number__struct_Payload* data; size_t size; size_t capacity; };
struct vector__Vec__struct_Thread__number__struct_Payload vector__Vec__struct_Thread__number__struct_Payload__new();
struct threads__Thread__number__struct_Payload* allocator__Allocator__alloc__struct_Thread__number__struct_Payload(size_t);
struct slice__Slice__char { char* data; size_t size; };
struct slice__str { struct slice__Slice__char slice; };
void allocator__Allocator___panic_err(struct slice__str);
void io___write_panic_head();
void io__write_file(FILE*, struct slice__str);
char* slice__str__data(struct slice__str);
struct threads__Mutex__struct_Vec__int32_t threads__Mutex__struct_Vec__int32_t__new(struct vector__Vec__int32_t);
struct vector__Vec__int32_t vector__Vec__int32_t__new();
int32_t* allocator__Allocator__alloc__int32_t(size_t);
void vector__Vec__struct_Thread__number__struct_Payload__push(struct vector__Vec__struct_Thread__number__struct_Payload*, struct threads__Thread__number__struct_Payload);
void vector__Vec__struct_Thread__number__struct_Payload__reserve(struct vector__Vec__struct_Thread__number__struct_Payload*, size_t);
void io__panic(struct slice__str);
void io__print_file(FILE*, struct slice__str);
struct threads__Thread__number__struct_Payload* allocator__Allocator__realloc_array__struct_Thread__number__struct_Payload(struct threads__Thread__number__struct_Payload*, size_t);
typedef int (*__Function__threads__Thread__number__struct_Payload__new____qlambda2)(struct Payload);
struct threads__Thread__number__struct_Payload threads__Thread__number__struct_Payload__new(__Function__threads__Thread__number__struct_Payload__new____qlambda2, struct Payload);
struct threads__StartRoutine__number__struct_Payload* allocator__Allocator__alloc__struct_StartRoutine__number__struct_Payload(size_t);
void* threads__StartRoutine__number__struct_Payload__entry(void*);
int __qlambda3(struct Payload);
struct vector__Vec__int32_t* threads__Mutex__struct_Vec__int32_t__lock(struct threads__Mutex__struct_Vec__int32_t*);
void vector__Vec__int32_t__push(struct vector__Vec__int32_t*, int32_t);
void vector__Vec__int32_t__reserve(struct vector__Vec__int32_t*, size_t);
int32_t* allocator__Allocator__realloc_array__int32_t(int32_t*, size_t);
void threads__Mutex__struct_Vec__int32_t__unlock(struct threads__Mutex__struct_Vec__int32_t*);
int threads__Thread__number__struct_Payload__wait(struct threads__Thread__number__struct_Payload);
void threads__Thread__number__struct_Payload__free(struct threads__Thread__number__struct_Payload);
void allocator__Allocator__free__struct_StartRoutine__number__struct_Payload(struct threads__StartRoutine__number__struct_Payload*);
struct threads__Thread__number__struct_Payload vector__Vec__struct_Thread__number__struct_Payload__operator__Operator__index(struct vector__Vec__struct_Thread__number__struct_Payload, size_t);
void vector__Vec__struct_Thread__number__struct_Payload__free(struct vector__Vec__struct_Thread__number__struct_Payload);
void allocator__Allocator__free__struct_Thread__number__struct_Payload(struct threads__Thread__number__struct_Payload*);
size_t vector__Vec__int32_t__len(struct vector__Vec__int32_t);
void io__print_i32(int32_t);
void io__print_i64(int64_t);
int32_t vector__Vec__int32_t__operator__Operator__index(struct vector__Vec__int32_t, size_t);
void vector__Vec__int32_t__free(struct vector__Vec__int32_t);
void allocator__Allocator__free__int32_t(int32_t*);
void threads__Mutex__struct_Vec__int32_t__free(struct threads__Mutex__struct_Vec__int32_t*);


int main() {
int32_t thread_count;
struct vector__Vec__struct_Thread__number__struct_Payload threads;
struct threads__Mutex__struct_Vec__int32_t results;
int32_t index;
int32_t i;
struct vector__Vec__int32_t numbers;
size_t n;
    thread_count = 20;
    threads = vector__Vec__struct_Thread__number__struct_Payload__new();
    results = threads__Mutex__struct_Vec__int32_t__new(vector__Vec__int32_t__new());
    for(index = 0; index < thread_count; index++) 
    {
        vector__Vec__struct_Thread__number__struct_Payload__push((&threads), threads__Thread__number__struct_Payload__new(__qlambda3, (struct Payload) { (&results), index }));
    }
    for(i = 0; i < thread_count; i++) 
        threads__Thread__number__struct_Payload__wait(vector__Vec__struct_Thread__number__struct_Payload__operator__Operator__index(threads, i));
    vector__Vec__struct_Thread__number__struct_Payload__free(threads);
    numbers = (*threads__Mutex__struct_Vec__int32_t__lock((&results)));
    for(n = 0; n < vector__Vec__int32_t__len(numbers); n++) 
    {
        io__print_i32(vector__Vec__int32_t__operator__Operator__index(numbers, n));
    }
    vector__Vec__int32_t__free(numbers);
    threads__Mutex__struct_Vec__int32_t__free((&results));
}


struct vector__Vec__struct_Thread__number__struct_Payload vector__Vec__struct_Thread__number__struct_Payload__new() {
    return (struct vector__Vec__struct_Thread__number__struct_Payload) { .data = allocator__Allocator__alloc__struct_Thread__number__struct_Payload(sizeof(struct threads__Thread__number__struct_Payload)), .size = 0, .capacity = 1 };
}


struct threads__Thread__number__struct_Payload* allocator__Allocator__alloc__struct_Thread__number__struct_Payload(size_t size) {
struct threads__Thread__number__struct_Payload* memory;
    memory = malloc(size);
    if(!memory) 
        allocator__Allocator___panic_err((struct slice__str) { "[Allocator::alloc] malloc() failed: %s\n", 39 });
    return memory;
}


void allocator__Allocator___panic_err(struct slice__str message) {
    io___write_panic_head();
    fprintf(stderr, slice__str__data(message), strerror(errno));
    exit(EXIT_FAILURE);
}


void io___write_panic_head() {
    io__write_file(stderr, (struct slice__str) { "[\x1b[31mpanicked\x1b[0m]:\n\t", 22 });
}


void io__write_file(FILE* file, struct slice__str message) {
    fwrite(message.slice.data, message.slice.size, sizeof(char), file);
}


char* slice__str__data(struct slice__str self) {
    return self.slice.data;
}


struct threads__Mutex__struct_Vec__int32_t threads__Mutex__struct_Vec__int32_t__new(struct vector__Vec__int32_t value) {
struct threads__Mutex__struct_Vec__int32_t mutex;
    mutex = (struct threads__Mutex__struct_Vec__int32_t) { PTHREAD_MUTEX_INITIALIZER, value };
    pthread_mutex_init((&mutex.mutex), 0);
    return mutex;
}


struct vector__Vec__int32_t vector__Vec__int32_t__new() {
    return (struct vector__Vec__int32_t) { .data = allocator__Allocator__alloc__int32_t(sizeof(int32_t)), .size = 0, .capacity = 1 };
}


int32_t* allocator__Allocator__alloc__int32_t(size_t size) {
int32_t* memory;
    memory = malloc(size);
    if(!memory) 
        allocator__Allocator___panic_err((struct slice__str) { "[Allocator::alloc] malloc() failed: %s\n", 39 });
    return memory;
}


void vector__Vec__struct_Thread__number__struct_Payload__push(struct vector__Vec__struct_Thread__number__struct_Payload* self, struct threads__Thread__number__struct_Payload item) {
    vector__Vec__struct_Thread__number__struct_Payload__reserve(self, 1);
    (*(self->data + self->size++)) = item;
}


void vector__Vec__struct_Thread__number__struct_Payload__reserve(struct vector__Vec__struct_Thread__number__struct_Payload* self, size_t n) {
    if(self->size + n > SIZE_MAX / 2) 
        io__panic((struct slice__str) { "[Vec::reserve] capacity overflow", 32 });
    if(self->size + n <= self->capacity) 
        return ;
    while(self->capacity < self->size + n) 
        self->capacity *= 2;
    self->data = allocator__Allocator__realloc_array__struct_Thread__number__struct_Payload(self->data, self->capacity);
}


void io__panic(struct slice__str message) {
    io___write_panic_head();
    io__print_file(stderr, message);
    exit(EXIT_FAILURE);
}


void io__print_file(FILE* file, struct slice__str message) {
char const newline = '\n';
    fwrite(message.slice.data, message.slice.size, sizeof(char), file);
    fwrite((&newline), 1, sizeof(char), file);
}


struct threads__Thread__number__struct_Payload* allocator__Allocator__realloc_array__struct_Thread__number__struct_Payload(struct threads__Thread__number__struct_Payload* ptr, size_t n) {
struct threads__Thread__number__struct_Payload* memory;
    if(n > SIZE_MAX / sizeof(struct threads__Thread__number__struct_Payload)) 
        io__panic((struct slice__str) { "[Allocator::realloc_array] multiplication overflow between input size and element size", 86 });
    memory = realloc(ptr, n * sizeof(struct threads__Thread__number__struct_Payload));
    if(!memory) 
        allocator__Allocator___panic_err((struct slice__str) { "[Allocator::realloc_array] realloc() failed: %s\n", 48 });
    return memory;
}


struct threads__Thread__number__struct_Payload threads__Thread__number__struct_Payload__new(__Function__threads__Thread__number__struct_Payload__new____qlambda2 callback, struct Payload argument) {
struct threads__Thread__number__struct_Payload thread;
    thread = (struct threads__Thread__number__struct_Payload) { .start_routine = allocator__Allocator__alloc__struct_StartRoutine__number__struct_Payload(sizeof(struct threads__StartRoutine__number__struct_Payload)) };
    (*thread.start_routine) = (struct threads__StartRoutine__number__struct_Payload) { callback, argument };
    pthread_create((&thread.tid), 0, threads__StartRoutine__number__struct_Payload__entry, (void*) thread.start_routine);
    return thread;
}


struct threads__StartRoutine__number__struct_Payload* allocator__Allocator__alloc__struct_StartRoutine__number__struct_Payload(size_t size) {
struct threads__StartRoutine__number__struct_Payload* memory;
    memory = malloc(size);
    if(!memory) 
        allocator__Allocator___panic_err((struct slice__str) { "[Allocator::alloc] malloc() failed: %s\n", 39 });
    return memory;
}


void* threads__StartRoutine__number__struct_Payload__entry(void* void_self) {
struct threads__StartRoutine__number__struct_Payload* const self = (struct threads__StartRoutine__number__struct_Payload*) void_self;
    self->retval = self->callback(self->argument);
    return (void*) ((&(self->retval)));
}


int __qlambda3(struct Payload payload) {
struct vector__Vec__int32_t* numbers;
    numbers = threads__Mutex__struct_Vec__int32_t__lock(payload.results);
    vector__Vec__int32_t__push(numbers, payload.index);
    threads__Mutex__struct_Vec__int32_t__unlock(payload.results);
    return 0;
}


struct vector__Vec__int32_t* threads__Mutex__struct_Vec__int32_t__lock(struct threads__Mutex__struct_Vec__int32_t* self) {
    pthread_mutex_lock((&self->mutex));
    return (&self->value);
}


void vector__Vec__int32_t__push(struct vector__Vec__int32_t* self, int32_t item) {
    vector__Vec__int32_t__reserve(self, 1);
    (*(self->data + self->size++)) = item;
}


void vector__Vec__int32_t__reserve(struct vector__Vec__int32_t* self, size_t n) {
    if(self->size + n > SIZE_MAX / 2) 
        io__panic((struct slice__str) { "[Vec::reserve] capacity overflow", 32 });
    if(self->size + n <= self->capacity) 
        return ;
    while(self->capacity < self->size + n) 
        self->capacity *= 2;
    self->data = allocator__Allocator__realloc_array__int32_t(self->data, self->capacity);
}


int32_t* allocator__Allocator__realloc_array__int32_t(int32_t* ptr, size_t n) {
int32_t* memory;
    if(n > SIZE_MAX / sizeof(int32_t)) 
        io__panic((struct slice__str) { "[Allocator::realloc_array] multiplication overflow between input size and element size", 86 });
    memory = realloc(ptr, n * sizeof(int32_t));
    if(!memory) 
        allocator__Allocator___panic_err((struct slice__str) { "[Allocator::realloc_array] realloc() failed: %s\n", 48 });
    return memory;
}


void threads__Mutex__struct_Vec__int32_t__unlock(struct threads__Mutex__struct_Vec__int32_t* self) {
    pthread_mutex_unlock((&self->mutex));
}


int threads__Thread__number__struct_Payload__wait(struct threads__Thread__number__struct_Payload self) {
void* retval_ptr;
int retval;
    pthread_join(self.tid, (&retval_ptr));
    retval = (*(int*) retval_ptr);
    threads__Thread__number__struct_Payload__free(self);
    return retval;
}


void threads__Thread__number__struct_Payload__free(struct threads__Thread__number__struct_Payload self) {
    allocator__Allocator__free__struct_StartRoutine__number__struct_Payload(self.start_routine);
}


void allocator__Allocator__free__struct_StartRoutine__number__struct_Payload(struct threads__StartRoutine__number__struct_Payload* ptr) {
    free(ptr);
}


struct threads__Thread__number__struct_Payload vector__Vec__struct_Thread__number__struct_Payload__operator__Operator__index(struct vector__Vec__struct_Thread__number__struct_Payload self, size_t index) {
    return (*(self.data + index));
}


void vector__Vec__struct_Thread__number__struct_Payload__free(struct vector__Vec__struct_Thread__number__struct_Payload self) {
    allocator__Allocator__free__struct_Thread__number__struct_Payload(self.data);
}


void allocator__Allocator__free__struct_Thread__number__struct_Payload(struct threads__Thread__number__struct_Payload* ptr) {
    free(ptr);
}


size_t vector__Vec__int32_t__len(struct vector__Vec__int32_t self) {
    return self.size;
}


void io__print_i32(int32_t number) {
    io__print_i64((int64_t) number);
}


void io__print_i64(int64_t number) {
    printf(slice__str__data((struct slice__str) { "%jd\n", 4 }), number);
}


int32_t vector__Vec__int32_t__operator__Operator__index(struct vector__Vec__int32_t self, size_t index) {
    return (*(self.data + index));
}


void vector__Vec__int32_t__free(struct vector__Vec__int32_t self) {
    allocator__Allocator__free__int32_t(self.data);
}


void allocator__Allocator__free__int32_t(int32_t* ptr) {
    free(ptr);
}


void threads__Mutex__struct_Vec__int32_t__free(struct threads__Mutex__struct_Vec__int32_t* self) {
    pthread_mutex_destroy((&self->mutex));
}

