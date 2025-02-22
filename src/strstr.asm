;;
;; EPITECH PROJECT, 2025
;; strstr.asm
;; File description:
;; strstr.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global strstr

strstr:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    CMP BYTE [RSI], 0 ; check if substring is empty
    JE .found ; jump to found if substring is empty

    .loop_outer:
        CMP BYTE [RDI], 0 ; check if end of string
        JE .not_found ; jump to not_found if end of string

        MOV RDX, RSI ; save pointer to substring
        MOV RCX, RDI ; save pointer to string

    .loop_inner:
        CMP BYTE [RDX], 0 ; check if end of substring
        JE .found ; jump to found if end of substring

        CMP BYTE [RCX], 0 ; check if end of string
        JE .not_found ; jump to not_found if end of string

        MOV AL, [RDX] ; load character from substring
        CMP BYTE [RCX], AL ; compare characters
        JNE .next ; jump to next if characters are different

        INC RDX ; move to next character
        INC RCX ; move to next character
        JMP .loop_inner ; jump to loop_inner

    .next:
        INC RDI ; move to next character
        JMP .loop_outer ; jump to loop_outer

    .not_found:
        XOR RAX, RAX ; set RAX to 0
        JMP .end ; jump to end

    .found:
        MOV RAX, RDI ; return pointer to char
        JMP .end ; jump to end

    .end:
        POP RBP ; restore RBP
        RET ; return pointer to char
