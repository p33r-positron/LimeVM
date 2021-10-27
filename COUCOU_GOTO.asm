db 15 ; LABEL

db 1 ; Mov
db 1 ; AH
db 0 ; PrintChar Interrupt Code

db 1 ; Mov
db 0 ; AL
db 67 ; 'C' (ASCII)

db 2 ; Interrupt

db 5 ; Add
db 0 ; AL
db 12 ; 'C'+12 = 'O' (ASCII)

db 2 ; Interrupt

db 5 ; Add
db 0 ; AL
db 6 ; 'O'+6 = 'U' (ASCII)

db 2 ; Interrupt

db 16 ; GOTO/JMP
db 0 ; Label 0 -> First label

times 510-($-$$) db 0 ; Fill with zeroes
; Magic numbers: Two bytes where byte1 XOR byte2 = 256
db 0xAA
db 0x55
; Could be 0xAA and 0x55, 255 and 0...