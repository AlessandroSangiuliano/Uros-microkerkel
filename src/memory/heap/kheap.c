/**
 * @author Alex Sangiuliano
 * @email alex22_7@hotmail.com
 * @create date 2021-12-26 10:58:42
 * @modify date 2021-12-26 10:58:42
 * @desc [description]
 */

#include "kheap.h"
#include "heap.h"
#include "config.h"
#include "kernel.h"
#include "memory/memory.h"

struct heap kernel_heap;
struct heap_table kernel_heap_table;

void kheap_init()
{
    int total_table_entries = HEAP_BYTE_SIZE / HEAP_BLOCK_SIZE;
    kernel_heap_table.entries = (heap_table_entry*) (HEAP_TABLE_ADDRESS);
    kernel_heap_table.total_entries = total_table_entries;

    void *end = (void*) (HEAP_ADDRESS + HEAP_BYTE_SIZE);
    int res = heap_create(&kernel_heap, (void*)(HEAP_ADDRESS), end, &kernel_heap_table);

    if (res < 0)
    {
        kprintf("ERROR. Unable to allocate the kernel heap!\n");
    }
    
}

void *kmalloc(size_t size)
{
    return heap_malloc(&kernel_heap, size);
}

void kfree(void *ptr)
{
    heap_free(&kernel_heap, ptr);
}

void *kzalloc(size_t size)
{
    void *ptr = kmalloc(size);

    if (!ptr)
    {
        return 0;
    }
    
    memset(ptr, 0x00, size);
    return ptr;
}