
/******************************************************************************
  Ian McGregor
  Computer Project #7
*******************************************************************************/

            .global main
            .text
            .balign 4

main:       push    {lr}

            mov     r4, #0        @ reset character count
            mov     r5, #0        @ reset newline count
            mov     r6, #0        @ reset whitespace count
            mov     r7, #0        @ reset octal digit count
            mov     r8, #0        @ reset decimal digit count
            mov     r9, #0        @ reset hex digit count
            mov     r10, #0       @ reset letter count

            ldr     r0, =fmt0     @ load header string
            bl      printf        @ display



readf:      bl      getchar       @ read one char from stdin (returned in r0) 

            cmp     r0, #-1       @ compare return value to EOF  
            beq     eof           @ when EOF found, exit readf loop

            add     r4, r4, #1    @ increment character count
            bl      putchar       @ write char to stdout stream 

iflower:    cmp     r0, #0x7a     @ compare char to 'z'
            bgt     readf         @ 'z' < char uncounted, to top of readf loop 
            cmp     r0, #0x61     @ compare char to 'a'
            bge     lower         @ 'a' <= char <= 'z', to lowercase handling 

ifupper:    cmp     r0, #0x5a     @ compare char to 'Z'
            bgt     readf         @ 'Z' < char < 'a' uncounted, to top of readf
            cmp     r0, #0x41     @ compare char to 'A'
            bge     letter        @ 'A' <= char <= 'Z', to letter handling

ifdecimal:  cmp     r0, #0x39     @ compare char to '9'
            bgt     readf         @ '9' < char < 'A' uncounted, to top of readf
            cmp     r0, #0x30     @ compare to '0'
            bge     decimal       @ '0' <= char <= '9', to decimal dig handling

ifspace:    cmp     r0, #0x20     @ compare char to ' '
            beq     wspace        @ if equal, to whitespace handling

ifwhite:    cmp     r0, #0x0c     @ compare char to ascii formfeed   
            bgt     readf         @ FF > char > '0' besides space uncounted 
            cmp     r0, #0x09     @ compare to ascii horizontal tab
            bge     wspace        @ (HT,newline,VT,FF) to whitespace handling

else:       b       readf         @ remaining char's uncounted, to top of readf



wspace:     add     r6, r6, #1    @ increment whitespace count
ifnewline:  cmp     r0, #0x0a     @ compare char to newline
            bne     readf         @ non-newline to top of readf 
            add     r5, r5, #1    @ increment newline count     
            b       readf         @ to top of readf loop

lower:      sub     r0, r0, #0x20 @ change to uppercase       
letter:     add     r10, r10,#1   @ increment letter count
ifhexlttr:  cmp     r0, #0x46     @ compare char to 'F'
            bgt     readf         @ letters > 'F' to top of readf loop
            add     r9, r9, #1    @ letters from 'A' to 'F' increment hex count
            b       readf         @ go to top of readf loop

decimal:    add     r8, r8, #1    @ increment decmial digit count
hexnum:     add     r9, r9, #1    @ increment hex digit count
ifoctal:    cmp     r0, #0x37     @ compare to '7'
            bgt     readf         @ decimal > '7' to top of readf loop 
            add     r7, r7, #1    @ decimal < '7' increment octal count
            b       readf



eof:        ldr     r0, =fmt1
            mov     r1, r4        @ load char count
            mov     r2, r5        @ load newline count
            mov     r3, r6        @ load whitespace count
            bl      printf        @ display

            ldr     r0, =fmt2
            mov     r1, r7        @ load octal count
            mov     r2, r8        @ load decimal count
            mov     r3, r9        @ load hex count
            bl      printf        @ display

            ldr     r0, =fmt3
            mov     r1, r10       @ load letter count
            bl      printf        @ display

            pop     {lr}
            bx      lr 



fmt0:   .asciz  "\nStart copy of input\n-\n"
fmt1:   .ascii  "-\nEnd of input\n\n"
        .ascii  "chars:%d\n"
        .ascii  "newlines:%d\n"
        .asciz  "whitespaces:%d\n"
fmt2:   .ascii  "octal digits:%d\n"
        .ascii  "decimal digits:%d\n"
        .asciz  "hexidecimal digits:%d\n"
fmt3:   .ascii  "letters:%d\n"
        .asciz  "\nEnd of Program\n\n"
