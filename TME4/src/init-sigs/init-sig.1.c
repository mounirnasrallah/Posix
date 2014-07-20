#define _POSIX_SOURCE 1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main () {

	pause ();
	printf ("1er signal\n");
	pause ();
	printf ("2e signal\n");
	return 0;
}

