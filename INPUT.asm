db 1 ; Mov
db 1 ; AH
db 2 ; GetString/Input Interrupt Code

db 1 ; Mov
db 5 ; BH
db 8 ; Choosen max input string length

db 2 ; Interrupt

; Now, input string is stored into stack...
; ...and the pointer is at the string location since it's the last.

db 12 ; Pop value from stack and put it into AL

db 1 ; Mov
db 1 ; AH
db 0 ; PrintChar Interrupt Code

db 2 ; Interrupt

db 11 ; Push next value into stack
db 65 ; ASCII 'A'

db 1 ; Mov
db 1 ; AH
db 3 ; PrintString Interrupt Code

db 2 ;

times 510-($-$$) db 0 ; Fill with zeroes
; Magic numbers: Two bytes where byte1 XOR byte2 = 256
db 0x55, 0xAA
; Could be 0xAA and 0x55, 255 and 0...