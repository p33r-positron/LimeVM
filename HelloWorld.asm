db 1 ; Mov
db 1 ; AH
db 0 ; PrintChar Interrupt Code

db 1 ; Mov
db 0 ; AL
db 72 ; 'H' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 69 ; 'E' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 76 ; 'L' (ASCII)

db 2 ; Interrupt
db 2 ; Interrupt (Another time for the other 'L')

db 5 ; Add
db 0 ; AL
db 3 ; 76+3 = 'L'+3 = 'O' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 44 ; ',' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 32 ; ' ' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 87 ; 'W' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 79 ; 'O' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 82 ; 'R' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 76 ; 'L' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 68 ; 'D' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 32 ; ' ' (ASCII)

db 2 ; Interrupt

db 3 ; Increment
db 0 ; AL
; 32+1 = ' '+1 = '!' (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 0 ; AL
db 10 ; '\n' (New Line: Line Feed/LF) (ASCII)

db 2 ; Interrupt

db 1 ; Mov
db 1 ; AH
db 1 ; GetChar Interrupt Code

db 2 ; Interrupt

; This will print the input char to the screen...

db 1 ; Mov
db 1 ; AH
db 0 ; PrintChar Interrupt Code

db 2 ; Interrupt

; ...but that's not useful for now because getchar() let user see his char.

times 510-($-$$) db 0
; Magic numbers: Two bytes where byte1 XOR byte2 = 256
db 0x55, 0xAA
; Could be 0xAA and 0x55, 255 and 0...