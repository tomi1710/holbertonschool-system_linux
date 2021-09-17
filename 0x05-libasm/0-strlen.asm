strlen:
    mov ebx,0
    strlen_loop:
        cmp byte [eax+ebx],0
        je strlen_end
        inc ebx
        jmp strlen_loop
    strlen_end:
        inc ebx
        ret
