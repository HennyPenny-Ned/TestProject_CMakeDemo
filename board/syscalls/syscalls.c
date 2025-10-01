#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int _read(int file, char *ptr, int len) { return -1; }
int _write(int file, char *ptr, int len) { return -1; }
int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { return 0; }
int _lseek(int file, int ptr, int dir) { return -1; }
int _isatty(int file) { return 1; }
void _exit(int status) { while (1); }
void *_sbrk(ptrdiff_t incr) { return (void *)-1; }

// Stub for _kill
int _kill(int pid, int sig) {
    errno = EINVAL;
    return -1;
}

// Stub for _getpid
int _getpid(void) {
    return 1;
}
