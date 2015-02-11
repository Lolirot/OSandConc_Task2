#include <stdio.h>

void main(int argc, char *argv[])
{
	int fdup[2];
	FILE *fd;
	pipe(fdup);
	if (fork() == 0)
	{
		fd = popen("ps", "r");
		fdup[0] = dup2(fd, 0);
		close(fd);
		argv[0] = "/bin/ps";
		execve("/bin/ps", argv);
	}
	
	if(fork() == 0)
	{
		fd = popen("wc", "w");
		fdup[1] = dup2(fd, 1);
		close(fd);
		char *args[1];
		args[0]="/usr/bin/wc";
		execve("/usr/bin/wc", args);
	}
}
