# tinylinux

This project is heavily inspired by Nir Lichtman's awesome [YouTube video](https://www.youtube.com/watch?v=u2Juz5sQyYQ) about hacking your own tiny Linux kernel with a static init userspace.

## Dependencies

For Ubuntu on WSL 2:

```shell
sudo apt install make build-essential flex bison libncurses-dev libelf-dev cpio syslinux isolinux genisoimage
```

## Building the kernel

Use the `tinyconfig` option along with the other config options shown in the video.

## Building the userspace

```shell
gcc -c userspace.c
```

```shell
as sys.S
```

```shell
ld -o init userspace.o a.out --entry main -z noexecstack
```

```shell
echo init | cpio -H newc -o > init.cpio
```

## Packaging the kernel and userspace

```shell
make isoimage FDARGS="initrd=/init.cpio" FDINITRD="~/tinylinux/init.cpio"
```
