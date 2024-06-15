#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int int main()
{
	int a;
	
	for (a=1;a<10;a++){
		int r= fork();
		
		if (r==0){
			printf("%d\n",getpid());
		}
		else{
			wait(NULL);
	    }
	
	}
}