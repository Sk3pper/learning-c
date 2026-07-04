_a$ = 8                                       ; size = 4
_b$ = 12                                                ; size = 4
_sum    PROC
        push    ebp
        mov     ebp, esp
        mov     eax, DWORD PTR _a$[ebp]
        add     eax, DWORD PTR _b$[ebp]
        pop     ebp
        ret     0
_sum    ENDP

_main   PROC
        push    ebp
        mov     ebp, esp
        push    20                                  ; 00000014H
        push    10                                  ; 0000000aH
        call    _sum
        add     esp, 8
        pop     ebp
        ret     0
_main   ENDP