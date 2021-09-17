	bits 64

	section .text
	global asm_putc

asm_putc:
	push rbp
	mov rbp, rsp

	push rdi

	mov rax, 1
	mov rdi, 1
	mov rsi, rsp
	mov rdx, 1
	syscall

	pop rdi
	mov rax, 1

	mov rsp, rbp
	pop rbp

	ret
