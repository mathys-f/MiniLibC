;;
;; EPITECH PROJECT, 2025
;; strncmp.asm
;; File description:
;; strncmp.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strncmp

strncmp:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    XOR RAX, RAX ; clear RAX

    .loop:
        CMP RDX, 0 ; compare RDX and 0
        JE .end ; if equal, jump to end
        MOV AL, [RDI] ; load byte from RDI
        CMP AL, [RSI] ; compare byte from RDI and RSI
        JNE .not_equal ; if not equal, jump to not_equal
        CMP AL, 0 ; compare AL and 0
        JE .end ; if equal, jump to end
        DEC RDX ; decrement RDX
        INC RDI ; increment RDI
        INC RSI ; increment RSI
        JMP .loop ; jump to loop

    .not_equal:
        SUB AL, [RSI] ; calculate difference between AL and [RSI]
        MOVSX RAX, AL ; sign-extend AL to RAX
        POP RBP ; restore RBP
        RET ; return

    .end:
        XOR RAX, RAX ; clear RAX
        POP RBP ; restore RBP
        RET ; return
