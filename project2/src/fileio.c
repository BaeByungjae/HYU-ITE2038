#include "disk_manager.h"
#include "fileio.h"

#if defined(__GNUC__)
    #include <unistd.h>
#elif defined(_MSC_VER)
#endif

int fexist(char* filename) {
#if defined(__GNUC__)
    return access(filename, F_OK) != -1;
#elif defined(_MSC_VER)
#endif
}

long fsize(FILE* fp) {
    fseek(fp, 0, SEEK_END);
    return ftell(fp);
}

int fresize(FILE* fp, size_t size) {
#if defined(__GNUC__)
    int fd = fileno(fp);
    return ftruncate(fd, size);
#elif defined(_MSC_VER)
#endif
}

int fpwrite(const void* ptr, size_t size, long pos, FILE* stream) {
    if (pos == -1) {
        fseek(stream, 0, SEEK_END);
    } else {
        fseek(stream, pos, SEEK_SET);
    }
    fwrite(ptr, size, 1, stream);
    return 0;
}

int fpread(void* ptr, size_t size, long pos, FILE* stream) {
    if (pos == -1) {
        fseek(stream, -PAGE_SIZE, SEEK_END);
    } else {
        fseek(stream, pos, SEEK_SET);
    }
    fread(ptr, size, 1, stream);
    return 0;
}