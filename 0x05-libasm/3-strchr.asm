	bits 64

	section .data
	iter dd 0
	arg_a dq 0
	arg_b dd 0

	section .text
	global asm_strchr


asm_strchr:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push r11

	mov [arg_a], rdi
	mov [arg_b], esi
	mov [iter], dword 0
	mov rcx, [arg_a]

count_c:
	inc dword [iter]
	mov r11, 0
	mov r11d, [iter]
	mov rbx, 0
	mov bl, [rcx + r11 - 1]
	cmp bl, 0x00
	je next_c
	cmp bl, [arg_b]
	jne count_c

next_c:
	mov rax, 0
	cmp ebx, [arg_b]
	je equ_c

end_c:
	pop r11
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

equ_c:
	dec r11
	add rcx, r11
	mov rax, rcx
	jmp end_c