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

    .reverse:
        CMP byte [RDI], 0 ; check if end of string
        JE .loop ; if end of string, jump to loop
        INC RDI ; increment counter
        JMP .reverse ; loop

    .loop:
        CMP byte [RDI], SIL ; check if char is found
        JNE .found ; if char is found, jump to found
        DEC RDI ; decrement counter
        CMP byte [RDI], 0 ; check if start of string
        JE .not_found ; if end of string, jump to not_found
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
