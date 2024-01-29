#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

int main(int argc, char** argv) {
	int fd;
	if (argc > 1) {
		fd = open(argv[1], O_RDONLY);
		for (int i = 0; i < (int)argv[2][0] - '0'; i++) {
			printf("%s", get_next_line(fd));
		}
	}

	return (0);
}