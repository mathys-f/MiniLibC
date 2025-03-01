;;
;; EPITECH PROJECT, 2025
;; strcspn.asm
;; File description:
;; strcspn.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strcspn

strcspn:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    XOR RAX, RAX ; set RAX to 0

    .loop:
        CMP byte [RDI], 0 ; check if end of string
        JE .end ; if end of string, jump to end

        MOV RCX, RSI ; save char to search

    .check:
        CMP byte [RCX], 0 ; check if end of string
        JE .next ; if end of string, jump to next

        MOV BL, [RCX] ; move char to BL
        CMP BL, [RDI] ; compare char to search
        JE .end ; if char found, jump to end

        INC RCX ; move to next char
        JMP .check ; jump to check

    .next:
        INC RAX ; increment counter
        INC RDI ; move to next char
        JMP .loop ; jump to loop

    .end:
        POP RBP ; restore RBP
        RET ; return counter
