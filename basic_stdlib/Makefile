TOP_BUILDDIR = ..

BUILD_DIR = .
SOURCES = basic_string.c
OBJ_FILES = $(SOURCES:.c=.o)

SO_TARGET = basic_stdlib.so

override CFLAGS := -I$(BUILD_DIR) -g -Wall -Werror -fPIC -ldl $(CFLAGS)

.PHONEY: clean all

all: $(TOP_BUILDDIR)/$(SO_TARGET)

$(TOP_BUILDDIR)/$(SO_TARGET): library_override.o $(OBJ_FILES)
	$(CC) -shared -o $@ $^ $(CFLAGS)

library_override.o:
	$(CC) $(CFLAGS) -c -o $@ $(TOP_BUILDDIR)/library_override.c

$(OBJ_FILES): %.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TOP_BUILDDIR)/$(SO_TARGET) $(OBJ_FILES) library_override.o
