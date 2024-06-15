#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int int main(int argc, char const *argv[])
{
	printf("IAMHAPPY\n");
	char* args[]={"ls","-l",NULL};
	execvp(args[0],args);
	printf("abc\n");
	printf("IMSAD\n");
	return 0;
}