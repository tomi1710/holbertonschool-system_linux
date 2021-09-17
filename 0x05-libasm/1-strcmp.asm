	bits 64

	section .text
	global asm_strcmp

asm_strcmp:
	push rbp
	mov rbp, rsp

	push rbx
	push rcx
	push rdx
	push r8
	push r9

	mov rbx, rdi
	mov rcx, rsi
	mov rdx, 0
	jmp entry_i

iter_i:
	inc rdx
entry_i:
	mov r8b, byte [rcx + rdx]
	cmp r8b, byte 0x00
	je finally_i
	mov r9b, byte [rbx + rdx]
	cmp r9b, byte 0x00
	je finally_i
	cmp r9b, r8b
	je iter_i

finally_i:
	mov rax, 0
	push qword [rbx + rdx]
	push qword [rcx + rdx]
	mov rbx, 0
	mov rcx, 0¿
	mov bl, byte [rsp + 8]
	mov cl, byte [rsp]
	cmp rbx, rcx
	je ret_eq
	jl ret_lt
	jg ret_gt

ret_eq:
	mov rax, 0
	jmp end_func

ret_lt:
	mov rax, -1
	jmp end_func

ret_gt:
	mov rax, 1
	jmp end_func

end_func:

	pop r9
	pop r8
	pop rdx
	pop rcx
	pop rbx

	mov rsp, rbp
	pop rbp

	ret
