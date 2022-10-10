#include <dirent.h>
#include <stdio.h>

int main(void) {
	DIR *d;
	struct dirent *dir;
	//opening the current directory
	d = opendir(".");
	if (d) {
		while((dir = readdir(d)) != NULL) {
			//printing the directory contents
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
	return 0;
}
