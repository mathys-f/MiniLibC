;;
;; EPITECH PROJECT, 2025
;; strcasecmp.asm
;; File description:
;; strcasecmp.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strcasecmp

strcasecmp:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    XOR RAX, RAX ; clear RAX

    .loop:
        MOV AL, BYTE [RDI] ; load byte from RDI to AL
        MOV DL, BYTE [RSI] ; load byte from RSI to DL

        CMP AL, 'a' ; compare AL with 'a'
        JL .skip_lower ; jump if less
        CMP AL, 'z' ; compare AL with 'z'
        JG .skip_lower ; jump if greater
        SUB AL, 32 ; subtract 32 from AL

        CMP DL, 'a' ; compare DL with 'a'
        JL .skip_lower ; jump if less
        CMP DL, 'z' ; compare DL with 'z'
        JG .skip_lower ; jump if greater
        SUB DL, 32 ; subtract 32 from DL

    .skip_lower:
        CMP AL, DL ; compare AL with DL
        JNE .not_equal ; jump if not equal

        CMP AL, 0 ; compare AL with 0
        JE .end ; jump if equal

        INC RDI ; increment RDI
        INC RSI ; increment RSI
        JMP .loop ; jump to loop

    .not_equal:
        SUB AL, DL ; subtract DL from AL
        MOVSX RAX, AL ; sign-extend AL to RAX
        POP RBP ; restore RBP
        RET ; return

    .end:
        XOR RAX, RAX ; clear RAX
        POP RBP ; restore RBP
        RET ; return
