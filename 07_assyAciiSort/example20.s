
/********************************************************************
  Example #20 -- ARM Subprograms (leaf functions)

  Function "main" passes three integers to function "add_three";
  that function returns the sum of the three integers.
********************************************************************/

        .global main
        .global add_three

        .data
x:      .word   55
y:      .word   12
z:      .word   37
sum:    .word   0

        .text
main:
        push    {lr}

        ldr     r4, =x
        ldr     r0, [r4]    @ get first argument
        ldr     r5, =y
        ldr     r1, [r5]    @ get second argument
        ldr     r6, =z
        ldr     r2, [r6]    @ get third argument

        bl      add_three

        ldr     r7, =sum
        str     r0, [r7]

        pop     {lr}
        bx      lr

add_three:
        add     r0, r0, r1
        add     r0, r0, r2

        bx      lr

