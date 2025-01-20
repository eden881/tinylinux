#include <unistd.h>

int main()
{
    // 1 means stdout, 21 means the number of chars
    write(1, "Welcome to my distro!\n", 22);
    _exit(0);
}
