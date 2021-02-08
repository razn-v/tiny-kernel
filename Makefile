CC = i686-elf-gcc
NASM = nasm

CC_SOURCES = $(wildcard kernel/*.c)
ASM_SOURCES = $(wildcard boot/*.asm kernel/*.asm)

OBJS = ${CC_SOURCES:.c=.o} ${ASM_SOURCES:.asm=.o}

BUILD_DIR = build
ISO_DIR = iso
OUTPUT_NAME = tiny-kernel
LINKER = linker.ld

all: iso

iso: ${OBJS} link multiboot
	cp ${BUILD_DIR}/${OUTPUT_NAME}.bin ${ISO_DIR}/boot/
	grub-mkrescue -o ${BUILD_DIR}/${OUTPUT_NAME}.iso ${ISO_DIR}

%.o: %.c
	dirname ${BUILD_DIR}/$@ | xargs mkdir -p
	${CC} -c $< -o ${BUILD_DIR}/$@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

%.o: %.asm
	dirname ${BUILD_DIR}/$@ | xargs mkdir -p
	${NASM} -felf32 $< -o ${BUILD_DIR}/$@

link:
	cd ${BUILD_DIR} && ${CC} -T ../${LINKER} -o ${OUTPUT_NAME}.bin -ffreestanding -O2 -nostdlib ${OBJS} -lgcc

multiboot:
	grub-file --is-x86-multiboot ${BUILD_DIR}/${OUTPUT_NAME}.bin

clean:
	rm -rf build/