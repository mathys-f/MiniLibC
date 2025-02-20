;;
;; EPITECH PROJECT, 2025
;; memset.asm
;; File description:
;; memset.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global memset

memset:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    XOR RCX, RCX ; set RCX to 0

    .loop:
        CMP RCX, RDX ; compare RCX to RDX
        JGE .end ; if RCX >= RDX, jump to end
        MOV byte [RDI + RCX], SIL ; set byte at RDI + RCX to SIL
        INC RCX ; increment counter
        JMP .loop ; loop

    .end:
        MOV RAX, RDI ; set return value to RDI
        POP RBP ; restore RBP
        RET ; return

