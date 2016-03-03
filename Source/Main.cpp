#include <Windows.h>
#include <intrin.h>
#include <stdint.h>
#include <stdio.h>

void main() {
	_TEB* tib = NtCurrentTeb();
#ifdef _AMD64_
	uint64_t x64sstib = __readgsqword(0x30);
	uint64_t x64id = __readgsqword(0x40);
	uint64_t x64peb = __readgsqword(0x60);
	printf("SubSystemTIB in x64 : %08I64X\nProcess ID in x64 : %08I64d\nPEB in x64 : %08I64X\n", 
		x64sstib, 
		x64id, 
		x64peb);
#else
	uint32_t x86sstib, x86peb, x86id;
	__asm {
		mov eax, FS:[0x18]
		mov x86sstib, eax
		mov eax, FS:[0x20]
		mov x86id, eax
		mov eax, FS:[0x30]
		mov x86peb, eax
	}
	printf("SubSystemTIB in x86 : %08X\nProcess ID in x86 : %08d\nPEB in x86 : %08X\n", 
		x86sstib, 
		x86id, 
		x86peb);
#endif
	system("pause");
}