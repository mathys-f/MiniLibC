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

    .check_fisrt:
        CMP AL, 'A' ; compare AL with 'A'
        JL .check_second ; jump if less
        CMP AL, 'Z' ; compare AL with 'Z'
        JG .check_second ; jump if greater
        ADD AL, 32 ; add 32 to AL

    .check_second:
        CMP DL, 'A' ; compare DL with 'A'
        JL .compare ; jump if less
        CMP DL, 'Z' ; compare DL with 'Z'
        JG .compare ; jump if greater
        ADD DL, 32 ; add 32 from DL

    .compare:
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
