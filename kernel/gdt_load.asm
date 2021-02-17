global gdt_load
section .text

; Pointer to our GDT
extern gdt_ptr

gdt_load:
	lgdt [gdt_ptr]

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	jmp 0x08:flush
flush:
	ret
