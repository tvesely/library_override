.PHONEY: all clean

all: memcpy_override.so basic_stdlib.so

memcpy_override.so:
	make -C memcpy_override

basic_stdlib.so:
	make -C basic_stdlib

clean:
	make -C memcpy_override clean
	make -C basic_stdlib clean
