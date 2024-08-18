#!/bin/bash

set -xue^

# QEMU file path
QEMU=qemu-system-riscv32

# clangのパス (Ubuntuの場合は CC=clang)
CC=clang

CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib"

# カーネルをビルド
$CC $CFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf kernel.c common.c

# QEMUを起動
$QEMU -machine virt -bios default -serial stdio -display gtk --no-reboot -kernel kernel.elf

