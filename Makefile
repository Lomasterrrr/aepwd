CC = cc
CFLAGS = -Wall -O2
TARGET = aepwd
PREFIX ?= /usr/lopwd
BINDIR = $(DESTDIR)$(PREFIX)/bin

all: $(TARGET)

$(TARGET): aepwd.c
	$(CC) $(CFLAGS) -o $(TARGET) aepwd.c

install: $(TARGET)
	mkdir -p $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)/$(TARGET)

uninstall:
	rm -f $(BINDIR)/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all install uninstall clean