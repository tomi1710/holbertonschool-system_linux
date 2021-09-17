	bits 64

	section .text
	global asm_strncmp

asm_strncmp:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push r11
	push r12
	push r13

	mov rbx, rdi
	mov rcx, rsi
	mov r11, rdx
	mov r12, 0

count_c:
	inc r12
	cmp r12, r11
	jg next_a
	mov r13b, byte [rcx + r12 - 1]
	cmp r13b, byte 0x00
	je next_c
	mov r13b, byte [rbx + r12 - 1]
	cmp r13b, byte 0x00
	je next_c
	cmp r13b, byte [rcx + r12 - 1]
	je count_c

next_c:
	mov rax, 0
	push qword [rbx + r12 - 1]
	push qword [rcx + r12 - 1]
	mov rbx, 0
	mov rcx, 0
	mov bl, byte [rsp + 8]
	mov cl, byte [rsp]
	cmp rbx, rcx
	je eq_c
	jg pos_c
	jl neg_c

eq_c:
	mov rax, 0
	jmp end_c

neg_c:
	mov rax, -1
	jmp end_c

pos_c:
	mov rax, 1
	jmp end_c

end_c:
	pop rdx
	pop rcx

	pop r13
	pop r12
	pop r11
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp

	ret

next_a:
	dec r12
	jmp next_c
