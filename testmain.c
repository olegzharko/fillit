#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>

int					main(int argc, char **argv)
{
	char 			buffer[60000];
	int				fn;
	unsigned int 	nbytes;
	unsigned int 	bytesread;

	nbytes = 60000;
	if (!(fn = open("test.fillit", O_RDONLY))) /*имя файла в "file name"*/
	{
		printf("%s\n", "open failed on input file");
		return (1);
	}
	if ((bytesread = read(fn, buffer, nbytes)))
		printf("%s\n", "it's work too");
	if (!(write(fn, buffer, 60000)))
		printf("%s\n", "doesn't work");
	else
		printf("Read %u bytes from filen", bytesread);
	return (0);
}

