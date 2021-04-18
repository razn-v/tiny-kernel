CC = gcc -m32
NASM = nasm

C_SOURCES = $(wildcard kernel/*.c drivers/*.c libc/*.c)
ASM_SOURCES = $(wildcard boot/*.asm kernel/*.asm)

OBJS = ${C_SOURCES:.c=.o} ${ASM_SOURCES:.asm=.o}
INC_DIR = include

BUILD_DIR = build
ISO_DIR = iso
OUTPUT_NAME = tiny-kernel
LINKER = linker.ld

all: iso

qemu:
	qemu-system-i386 ${BUILD_DIR}/${OUTPUT_NAME}.iso

iso: ${OBJS} link multiboot
	cp ${BUILD_DIR}/${OUTPUT_NAME}.bin ${ISO_DIR}/boot/
	grub-mkrescue -o ${BUILD_DIR}/${OUTPUT_NAME}.iso ${ISO_DIR}

%.o: %.c
	dirname ${BUILD_DIR}/$@ | xargs mkdir -p
	${CC} -c $< -o ${BUILD_DIR}/$@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ${INC_DIR}

%.o: %.asm
	dirname ${BUILD_DIR}/$@ | xargs mkdir -p
	${NASM} -felf32 $< -o ${BUILD_DIR}/$@

link:
	cd ${BUILD_DIR} && ${CC} -T ../${LINKER} -o ${OUTPUT_NAME}.bin -ffreestanding -O2 -nostdlib ${OBJS} -lgcc

multiboot:
	grub-file --is-x86-multiboot ${BUILD_DIR}/${OUTPUT_NAME}.bin

clean:
	rm -rf build/
