#include <kernel/isr_handler.h>
#include <drivers/screen.h>

char* exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
};

void isr_handler(registers_t *regs) {
    // Exception not handled
    if (regs->int_no > 31) {
        return;
    }

    write_str("Received interrupt: ");

    if (regs->int_no < 19) {
        write_str(exception_messages[regs->int_no]);
    } else {
        write_str("Reserved");
    }

    for (;;);
}
