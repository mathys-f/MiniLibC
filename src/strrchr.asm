;;
;; EPITECH PROJECT, 2025
;; strrchr.asm
;; File description:
;; strrchr.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strrchr

strrchr:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    XOR RAX, RAX ; set RAX to 0

    .loop:
        CMP byte [RDI], SIL ; check if char is found
        JNE .next ; if char is not found, jump to next
        MOV RAX, RDI ; update return pointer

    .next:
        CMP byte [RDI], 0 ; check if end of string
        JE .end ; if end of string, jump to end

        INC RDI ; increment counter
        JMP .loop ; loop

    .end:
        POP RBP ; restore RBP
        RET ; return pointer to char
