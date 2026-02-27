// Quark Version 0.5pre
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"
#include "errno.h"
#include "pthread.h"
int main();
typedef int (*__Function__threads__StartRoutine__number__number____qlambda1)(int);
struct threads__StartRoutine__number__number { __Function__threads__StartRoutine__number__number____qlambda1 callback; int argument; int retval; };
struct threads__StartRoutine__number__number;
struct threads__Thread__number__number { pthread_t tid; struct threads__StartRoutine__number__number* start_routine; };
struct threads__Thread__number__number;
typedef int (*__Function__threads__Thread__number__number__new____qlambda2)(int);
struct threads__Thread__number__number threads__Thread__number__number__new(__Function__threads__Thread__number__number__new____qlambda2, int);
struct threads__StartRoutine__number__number* allocator__Allocator__alloc__struct_StartRoutine__number__number(size_t);
struct slice__Slice__char { char* data; size_t size; };
struct slice__str { struct slice__Slice__char slice; };
void allocator__Allocator___panic_err(struct slice__str);
void io___write_panic_head();
void io__write_file(FILE*, struct slice__str);
char* slice__str__data(struct slice__str);
void* threads__StartRoutine__number__number__entry(void*);
int __qlambda3(int);
void io__print(struct slice__str);
void io__print_file(FILE*, struct slice__str);
int threads__Thread__number__number__wait(struct threads__Thread__number__number);
void threads__Thread__number__number__free(struct threads__Thread__number__number);
void allocator__Allocator__free__struct_StartRoutine__number__number(struct threads__StartRoutine__number__number*);


int main() {
struct threads__Thread__number__number thread;
    thread = threads__Thread__number__number__new(__qlambda3, 5);
    threads__Thread__number__number__wait(thread);
}


struct threads__Thread__number__number threads__Thread__number__number__new(__Function__threads__Thread__number__number__new____qlambda2 callback, int argument) {
struct threads__Thread__number__number thread;
    thread = (struct threads__Thread__number__number) { .start_routine = allocator__Allocator__alloc__struct_StartRoutine__number__number(sizeof(struct threads__StartRoutine__number__number)) };
    (*thread.start_routine) = (struct threads__StartRoutine__number__number) { callback, argument };
    pthread_create((&thread.tid), 0, threads__StartRoutine__number__number__entry, (void*) thread.start_routine);
    return thread;
}


struct threads__StartRoutine__number__number* allocator__Allocator__alloc__struct_StartRoutine__number__number(size_t size) {
struct threads__StartRoutine__number__number* memory;
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


void* threads__StartRoutine__number__number__entry(void* void_self) {
struct threads__StartRoutine__number__number* const self = (struct threads__StartRoutine__number__number*) void_self;
    self->retval = self->callback(self->argument);
    return (void*) ((&(self->retval)));
}


int __qlambda3(int x) {
    io__print((struct slice__str) { "Hello World!", 12 });
    return 0;
}


void io__print(struct slice__str message) {
    io__print_file(stdout, message);
}


void io__print_file(FILE* file, struct slice__str message) {
char const newline = '\n';
    fwrite(message.slice.data, message.slice.size, sizeof(char), file);
    fwrite((&newline), 1, sizeof(char), file);
}


int threads__Thread__number__number__wait(struct threads__Thread__number__number self) {
void* retval_ptr;
int retval;
    pthread_join(self.tid, (&retval_ptr));
    retval = (*(int*) retval_ptr);
    threads__Thread__number__number__free(self);
    return retval;
}


void threads__Thread__number__number__free(struct threads__Thread__number__number self) {
    allocator__Allocator__free__struct_StartRoutine__number__number(self.start_routine);
}


void allocator__Allocator__free__struct_StartRoutine__number__number(struct threads__StartRoutine__number__number* ptr) {
    free(ptr);
}

