;;
;; EPITECH PROJECT, 2025
;; strlen.asm
;; File description:
;; strlen.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strlen

strlen:
    XOR RAX, RAX ; init counter to 0

    .loop:
        CMP byte [RDI + RAX], 0 ; check if end of string
        JE .end ; if end of string, jump to end
        INC RAX ; increment counter
        JMP .loop ; loop

    .end:
        RET ; return counter
