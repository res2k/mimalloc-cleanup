#include "lib.h"

#include "mimalloc.h"

#include <stdio.h>

struct HeapWrapper
{
    struct Container
    {
        mi_heap_t *heap;
    };
    Container *container;

    HeapWrapper()
    {
        container = mi_malloc_tp(Container);
        printf("created 'container' %p\n", container);
        container->heap = mi_heap_new();
        printf("created heap %p\n", container->heap);
    }
    ~HeapWrapper()
    {
        printf("about to destroy heap %p\n", container->heap);
        fflush(stdout);
        mi_heap_destroy(container->heap);

        printf("about to destroy 'container' %p\n", container);
        fflush(stdout);
        mi_free(container->heap);
    }
};

static HeapWrapper static_heap;

void lib_function()
{
    auto *p = mi_heap_malloc(static_heap.container->heap, 123);
    mi_free(p);
}
