CFLAGS				= -Wall -O2
CC				= arm-linux-gcc
INSTALL				= install

TARGET				= pir_test


all: $(TARGET)

$(TARGET): pir.c
	$(CC) $(CFLAGS) $< -o $@


install: $(TARGET)
	$(INSTALL) $^ ./

clean distclean:
	rm -rf *.o $(TARGET)


# ----------------------------------------------------------------------------

.PHONY: $(PHONY) install clean distclean

# End of file
# vim: syntax=make

