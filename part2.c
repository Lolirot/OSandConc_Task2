#include <stdio.h>

void main(int argc, char *argv[])
{
	argv[0] = "/bin/ps";
	execve("/bin/ps", argv);
}
