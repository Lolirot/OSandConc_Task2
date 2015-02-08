#include <stdio.h>
#include <time.h>

void main(int argc, char *argv[])
{
	execve("./bash.sh", argv);
}