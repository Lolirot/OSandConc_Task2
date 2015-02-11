#include <stdio.h>

void main(int argc, char *argv[])
{
	int fdup[2];
	pipe(fdup);
	if (fork() == 0)
	{
		close(fdup[0]);
		dup2(fdup[1],1);
		dup2(fdup[2],2);
		argv[0] = "/bin/ps";
		execve("/bin/ps", argv);
	}
	
	if(fork() == 0)
	{
		close(fdup[1]);
		dup2(fdup[0], 0);
		char *args[1];
		args[0]="/usr/bin/wc";
		execve("/usr/bin/wc", args);
	}
}
