#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

int main(void)
{
	int fd;
	char buttons[4] = {'0', '0', '0', '0'};

	fd = open("/dev/keypad", 0);
	if (fd < 0) {
		perror("open device keypad buttons");
		exit(1);
	}

	for (;;) {
		char current_buttons[4];
		int count_of_changed_key;
		int i;
		if (read(fd, current_buttons, sizeof current_buttons) != sizeof current_buttons) {
			perror("read buttons:");
			exit(1);
		}

		for (i = 0, count_of_changed_key = 0; i < sizeof buttons / sizeof buttons[0]; i++) {
			if (buttons[i] != current_buttons[i]) {
				buttons[i] = current_buttons[i];
				printf("%s", buttons[i] == '0' ? "people" : "no people");
				count_of_changed_key++;
			}
		}
		if (count_of_changed_key) {
			printf("\n");
		}
		
		
	}

	close(fd);
	return 0;
}
