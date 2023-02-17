#include "pirthread.h"
#include <QtCore>
#include <QDebug>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
PirThread::PirThread(QObject* parent):
    QThread(parent)
{

}

void PirThread::run(){
    int fd;
    char buttons[4] = {'0', '0', '0', '0'};
    char current_buttons[4];
    int count_of_changed_key;
    int i;

    fd = open("/dev/keypad", 0);
    QString str = "Off";

    if (fd < 0) {
	perror("open device keypad buttons");
	exit(1);
	}

    for (;;) {
	if (read(fd, current_buttons, sizeof current_buttons) != sizeof current_buttons) {
		    perror("read buttons:");
		    exit(1);
			if(this->Stop== true) {
			::close(fd);
			break; 
		}
		}

	for (i = 0, count_of_changed_key = 0; i < sizeof buttons/sizeof buttons[0]; i++) {
		QMutex mutex;
		mutex.lock();
		if (buttons[i] != current_buttons[i]) {
			buttons[i] = current_buttons[i];
			emit PirNumberChanged(buttons[i] == '0' ? 1 : 0);
			this->msleep(100);
			count_of_changed_key++;
		}
		if(this->Stop== true) {
				::close(fd);
				break; 
		}
		mutex.unlock();
	}	
    }

}
