#include <stdio.h>

int main(){
	
	asm("mov a1, 2"); //moves 2 into register al
	printf("success");
	//system("PAUSE");
	
}
//Set Break points and monitor registers. Remember:
/*
Things to know: Registers, Instructions, Memory, Stack, Pointers.

The CPU fetches instructions from memory. Instruction Pointer (points to the next instruction to execute).
Stack Pointer (points to the top of the stack).

Registers:
EAX 32 bit - 0000 0100 0000 1000 0110 0000 0000 0111
AX  16 bit - 0000 0100 0000 1000
AH   8 bit - 0000 0100 (first half of AX)
AL   8 bit - 0000 1000 (second half of AX)

In operating Systems a WORD is an instruction, a string of bits. In a 32 bit Operating system the instruction is 32 bits 0000 0100 0000 1000 0110 0000 0000 0111
In a 64 bit Operating system the instruction is 64 bits in length. 0000 0100 0000 1000 0110 0000 0000 01110000 0100 0000 1000 0110 0000 0000 0111
ASM is different for those machines. 16 bit OS is different too. (32 bit OS can run 16bit programs, 64bit can run 32 but not 16 except in a VM)
ASM relates to physical programming, however you can also do that in C. A great source is wokwi.com     EXAMPLE : Simon Says https://wokwi.com/projects/328451800839488084

1. General-Purpose Registers (GPRs):
These registers are used for arithmetic, logic, and data manipulation. Their specific roles may vary depending on the architecture (e.g., x86, ARM). Examples in x86 assembly include:

EAX/AX/AL: Accumulator register, often used for arithmetic operations.
EBX/BX/BL: Base register, used for addressing memory.
ECX/CX/CL: Counter register, commonly used in loops.
EDX/DX/DL: Data register, often used for I/O operations or extended arithmetic.

2. Segment Registers (x86-specific):
These registers are used to manage memory segmentation in x86 architecture:

CS: Code Segment (holds the segment address of the code).
DS: Data Segment (used for data storage).
SS: Stack Segment (points to the stack).
ES, FS, GS: Extra segments for additional data.
3. Special-Purpose Registers:
These registers serve specific functions:

EIP/RIP: Instruction Pointer (points to the next instruction to execute).
ESP/RSP: Stack Pointer (points to the top of the stack).
EBP/RBP: Base Pointer (used for stack frame referencing).
EFLAGS/RFLAGS: Flags register (stores status flags like zero, carry, overflow, etc.).
4. Floating-Point Registers:
Used for floating-point arithmetic:

ST(0) to ST(7): Registers in the x87 FPU stack.
In modern architectures, SIMD registers like XMM, YMM, and ZMM are used for vectorized floating-point operations.
5. Control and Debug Registers:
CR0-CR4: Control registers for system-level operations (e.g., enabling paging).
DR0-DR7: Debug registers for hardware breakpoints.
6. ARM-Specific Registers (Example):
In ARM architecture, registers are named R0-R15:

R0-R12: General-purpose registers.
R13 (SP): Stack Pointer.
R14 (LR): Link Register (stores return address for subroutines).
R15 (PC): Program Counter.


*/
