#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
		int n,in,out;
		char buf[1024];
		
		in = open(argv[1],O_RDONLY);
		out = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
		
		while((n = read(in,buf,sizeof(buf))) > 0)
			write(out,buf,n);
		
		close(out);
		close(in);
}
