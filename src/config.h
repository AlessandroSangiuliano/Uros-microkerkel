/**
 * @author Alex Sangiuliano
 * @email alex22_7@hotmail.com
 * @create date 2021-12-26 10:58:42
 * @modify date 2021-12-26 10:58:42
 * @desc [description]
 */

#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_CODE_SELECTOR 0x08
#define KERNEL_DATA_SELECTOR 0x10

#define MAX_INTERRUPTS 512

// these are 100MB for now, so at least 100MB of ram installed is needed for now. (better implementation coming)
#define HEAP_BYTE_SIZE  104857600
#define HEAP_BLOCK_SIZE 4096
#define HEAP_ADDRESS    0x01000000
#define HEAP_TABLE_ADDRESS 0x00007E00

#define UROS_SECTOR_SIZE 512
#define UROS_MAX_FILESYSTEMS 12
#define UROS_MAX_FILE_DESCRIPTORS 512

#endif