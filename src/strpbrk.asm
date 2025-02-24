;;
;; EPITECH PROJECT, 2025
;; strpbrk.asm
;; File description:
;; strpbrk.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strpbrk

strpbrk:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    .loop:
        CMP byte [RDI], 0 ; check if end of string
        JE .not_found ; if end of string, jump to not_found

        MOV RCX, RSI ; save char to search

    .check:
        CMP byte [RCX], 0 ; check if end of string
        JE .next ; if end of string, jump to next

        MOV AL, [RCX] ; move char to AL
        CMP AL, [RDI] ; compare char to search
        JE .found ; if char found, jump to found

        INC RCX ; move to next char
        JMP .check ; jump to check

    .next:
        INC RDI ; move to next char
        JMP .loop ; jump to loop

    .not_found:
        XOR RAX, RAX ; set RAX to 0
        JMP .end ; jump to end

    .found:
        MOV RAX, RDI ; return pointer to char
        JMP .end ; jump to end

    .end:
        POP RBP ; restore RBP
        RET ; return pointer to char
