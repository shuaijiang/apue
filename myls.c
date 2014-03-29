#include "myapue.h"
#include <dirent.h>
#include <errno.h>		/* for definition of errno */

int main(int argc, int ** argv)
{
	DIR 			*dp;
	struct dirent 	*dirp;
	
	if(argc != 2)
		err_quit("usage: myls directory_name");
	
	if((dp = opendir(argv[1])) == NULL)
		err_sys("Can't open %s", argv[1]);
	
	while((dirp = readdir(dp)) != NULL)
		printf("%s\n",dirp->d_name);
		
	closedir(dp);
	exit(0);
}
