;;
;; EPITECH PROJECT, 2025
;; memmove.asm
;; File description:
;; memmove.asm
;;

bits 64 ; 64-bit mode

;; code
section .text
    global memmove

memmove:
    PUSH RBP ; save RBP
    MOV RBP, RSP ; set RBP to RSP

    CMP RDI, RSI ; compare RDI to RSI
    JE .end ; if RDI == RSI, jump to end

    CMP RDI, RSI ; compare RDI to RSI
    JB .forward ; if RDI < RSI, jump to forward

    .backward:
        MOV RCX, RDX ; set RCX to RDX
        DEC RCX ; decrement RCX

    .backward_loop:
        CMP RCX, -1 ; compare RCX to -1
        JL .end ; if RCX < -1, jump to end
        MOV AL, byte [RSI + RCX] ; set AL to byte at RS + RCX
        MOV byte [RDI + RCX], AL ; set byte at RD + RCX to AL
        DEC RCX ; decrement counter
        JMP .backward_loop ; loop

    .forward:
        XOR RCX, RCX ; set RCX to 0

    .forward_loop:
        CMP RCX, RDX ; compare RCX to RDX
        JGE .end ; if RCX >= RDX, jump to end
        MOV AL, byte [RSI + RCX] ; set AL to byte at RS + RCX
        MOV byte [RDI + RCX], AL ; set byte at RD + RCX to AL
        INC RCX ; increment counter
        JMP .forward_loop ; loop

    .end:
        MOV RAX, RDI ; set return value to RDI
        POP RBP ; restore RBP
        RET ; return
