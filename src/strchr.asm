;;
;; EPITECH PROJECT, 2025
;; strchr.asm
;; File description:
;; strchr.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strchr

strchr:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    .loop:
        CMP byte [RDI], 0 ; check if end of string
        JE .not_found ; if end of string, jump to not_found
        CMP byte [RDI], SIL ; check if char is found
        JE .found ; if char is found, jump to found
        INC RDI ; increment counter
        JMP .loop ; loop

    .not_found:
        XOR RAX, RAX ; set RAX to 0
        JMP .end ; jump to end

    .found:
        MOV RAX, RDI ; return pointer to char
        JMP .end ; jump to end

    .end:
        POP RBP ; restore RBP
        RET ; return pointer to char
