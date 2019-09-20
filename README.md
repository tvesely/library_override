# Easy Linked Library Override

Tools for overriding library calls using LD_PRELOAD

Build and use example:

```bash
make
LD_PRELOAD=./memcpy_override.so bash -c 'echo test'

```
