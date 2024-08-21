HELLO = "HELLO WORLD"

# QEMU file path
QEMU = qemu-system-riscv32

# clangのパス (Ubuntuの場合は CC=clang)
CC = clang

#OBFCOPY's PATH
OBJCOPY = /usr/bin/llvm-objcopy

CFLAGS = -std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib

DELETEFILE = shell.bin shell.bin.o shell.elf

run:
	set -xue
	
	$(CC) $(CFLAGS) -Wl,-T ./ld/user.ld -Wl,-Map=./map/shell.map -o shell.elf shell.c user.c common.c
	$(OBJCOPY) --set-section-flags .bss=alloc,contents -O binary shell.elf shell.bin
	$(OBJCOPY) -Ibinary -Oelf32-littleriscv shell.bin shell.bin.o

	# カーネルをビルド
	$(CC) $(CFLAGS) -Wl,-T ./ld/kernel.ld -Wl,-Map=./map/kernel.map -o kernel.elf kernel.c common.c shell.bin.o

	rm $(DELETEFILE)

	# QEMUを起動
	$(QEMU) -machine virt -bios default -serial stdio --no-reboot -kernel kernel.elf
