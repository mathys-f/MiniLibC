;;
;; EPITECH PROJECT, 2025
;; memcpy.asm
;; File description:
;; memcpy.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global memcpy

memcpy:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    XOR RCX, RCX ; set RCX to 0

    .loop:
        CMP RCX, RDX ; compare RCX to RDX
        JGE .end ; if RCX >= RDX, jump to end
        MOV AL, byte [RSI + RCX] ; set AL to byte at RSI + RCX
        MOV byte [RDI + RCX], AL ; set byte at RDI + RCX to AL
        INC RCX ; increment counter
        JMP .loop ; loop

    .end:
        MOV RAX, RDI ; set return value to RDI
        POP RBP ; restore RBP
        RET ; return
