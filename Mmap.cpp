
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
    struct stat sb;
    char *addr;

    // Open the file
    fd = open("mMap.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get file size
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    // Mmap the file
    addr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // Access and modify the mapped memory (e.g., change the first character)
    if (sb.st_size > 0) {
        printf("Original first char: %c\n", addr[0]);
        addr[0] = 'X';
        printf("Modified first char: %c\n", addr[0]);
    }

    // Unmap the memory
    if (munmap(addr, sb.st_size) == -1) {
        perror("munmap");
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

/*

Advantages of mmap( )
Manipulating files via mmap( ) has a handful of advantages over the standard read( ) and write( ) system calls. Among them are:

-Reading from and writing to a memory-mapped file avoids the extraneous copy that occurs when using the read( ) or write( ) system calls, where the data must be copied to and from a user-space buffer.

-Aside from any potential page faults, reading from and writing to a memory-mapped file does not incur any system call or context switch overhead. It is as simple as accessing memory.

=When multiple processes map the same object into memory, the data is shared among all the processes. Read-only and shared writable mappings are shared in their entirety; private writable mappings have their not-yet-COW (copy-on-write) pages shared.

=Seeking around the mapping involves trivial pointer manipulations. There is no need for the lseek( ) system call.

For these reasons, mmap( ) is a smart choice for many applications.

Disadvantages of mmap( )
There are a few points to keep in mind when using mmap( ):

Memory mappings are always an integer number of pages in size. Thus, the difference between the size of the backing file and an integer number of pages is "wasted" as slack space. For small files, a significant percentage of the mapping may be wasted. For example, with 4 KB pages, a 7 byte mapping wastes 4,089 bytes.

The memory mappings must fit into the process' address space. With a 32-bit address space, a very large number of various-sized mappings can result in fragmentation of the address space, making it hard to find large free contiguous regions. This problem, of course, is much less apparent with a 64-bit address space.

There is overhead in creating and maintaining the memory mappings and associated data structures inside the kernel. This overhead is generally obviated by the elimination of the double copy mentioned in the previous section, particularly for larger and frequently accessed files.


Source on Mmap() :

https://stackoverflow.com/questions/258091/when-should-i-use-mmap-for-file-access


*/
