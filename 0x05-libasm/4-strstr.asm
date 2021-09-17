	bits 64

	section .data
	iter1 dd 0
	iter2 dd 0
	arg_a dq 0
	arg_b dq 0
	r_pointer dq 0

	section .text
	global asm_strstr

asm_strstr:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push r12
	push r11

	mov [arg_a], rdi
	mov [arg_b], rsi
	mov [iter1], dword 0
	mov [iter2], dword 0
	mov r11, 0
	mov r12, 0

	mov rcx, 0
	mov cl, [rsi]
	cmp cl, 0x00
	je ret_same

count_c:
	inc dword [iter1]
	mov r11d, [iter1]

	mov rcx, 0
	mov cl, [rsi + r12]
	cmp cl, 0x00
	je equ_c

	mov rbx, 0
	mov bl, [rdi + r11 - 1]
	cmp bl, 0x00
	je next_c

	cmp bl, cl
	je inc_arg_2
	mov r12, 0
	mov [iter2], r12d
	jmp count_c

next_c:
	mov rax, 0

end_c:
	mov rdi, [arg_a]
	mov rsi, [arg_b]
	pop r11
	pop r12
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp	

	ret

equ_c:
	mov rax, [r_pointer]
	jmp end_c

inc_arg_2:
	cmp r12, 0x00
	je save_p

inc_next:
	inc dword [iter2]
	mov r12d, [iter2]
	jmp count_c

save_p:
	dec r11
	mov r12, rdi
	add r12, r11
	mov [r_pointer], r12
	inc r11
	mov r12, 0
	jmp inc_next

ret_same:
	mov [r_pointer], rdi
	jmp equ_c