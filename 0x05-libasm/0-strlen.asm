	bits 64

	section .text
	global asm_strlen

asm_strlen:
	push rbp
	mov rbp, rsp

	push rbx
	push rcx

	mov rbx, rdi
	mov rcx, 0
	jmp entry_i

iter_i:
	inc rcx
entry_i:
	cmp byte [rbx + rcx ], 0x00
	jne iter_i

end:
	mov rax, rcx

	pop rcx
	pop rbx

	mov rsp, rbp
	pop rbp

	ret