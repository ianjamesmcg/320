/*
   Project #8
   Ian McGregor
*/

E = 0x80000000                        @set constant symbol for error val

        .global negate, absolute, add, sub, mul, divide, remain, power
        .global factorial
        .text
        .balign 4


/*-----------------------------------------------------------------------------
  Name: negate

  Purpose: get negation of input value
  Receive: a single 32 bit two's complement integer
  Return: a single 32 bit two's complement integer

      - error value is returned when input is itself, no corresponding
      positive value
-----------------------------------------------------------------------------*/

negate: 
        push    {lr}

        mvn     r0, r0                @flip all bits
        adds    r0, r0, #0x01         @add 1

        pop     {lr}
        bx      lr

/*-----------------------------------------------------------------------------
  Name: absolute

  Purpose: get absolute value of input
  Receive: a single 32 bit two's complement integer
  Return: a single 32 bit two's complement integer

      - error value is returned when input is itself, no corresponding
      positive value
-----------------------------------------------------------------------------*/

absolute:
        push    {lr}

        cmp     r0, #0x00             @compare to zero
        blt     negate                @flip sign if less than zero

        pop     {lr}
        bx      lr

/*-----------------------------------------------------------------------------
  Name: add

  Purpose: adds the values in r0 and r1
  Receive: 2 32 bit two's complement integers
  Return: a single 32 bit two's complement integer

      - returns error value when subs sets oVerflow bit
-----------------------------------------------------------------------------*/

add:
        push    {lr} 

        adds    r0, r0, r1            @add arguments and set NZCV bits
        bvs     error                 @return error val on overflow       

        pop     {lr}
        bx      lr

/*-----------------------------------------------------------------------------
  Name: sub

  Purpose: subtract value in r1 from value in r0
  Receive: 2 32 bit two's complement integers
  Return: a single 32 bit two's complement integer

      - returns error value when subs sets oVerflow bit
-----------------------------------------------------------------------------*/

sub:
        push    {lr}

        subs    r0, r0, r1            @r0 <== r0-r1 and set NZCV
        bvs     error                 @return error val on overflow

        pop     {lr}
        bx      lr

/*-----------------------------------------------------------------------------
  Name: mul

  Purpose: multiply values in r0 and r1
  Recevie: 2 32 bit two's complement integers
  Return: a single 32 bit two's complement integer
          
      - if all bits of the upper product of smull do not match the most
      significant bit of the lower product, overflow has occurred and the error
      code is returned
-----------------------------------------------------------------------------*/

mul:
        push    {lr}

        smull   r0, r1, r0, r1        @r0:lower product, r1:upper product
        lsr     r2, r0, #31           @store most sig bit of lower product
        
        cmp     r2, #0                @check most sig bit of lower == 0
        beq     firstzero             

firstone:                             @most sig of lower is one              
        cmp     r1, #-1               @check upper product for all ones  
        bne     error                 @return error val if not all ones 
        b       endmul                

firstzero:                            @most sig of lower is zero
        cmp     r1, #0                @check lower product for all zeroes
        bne     error                 @return error val if not all zeroes

endmul:
        pop     {lr}
        bx      lr

/*-----------------------------------------------------------------------------
  Name: divide

  Purpose: get quotient of r0/r1
  Recevie: 2 32 bit two's complement integers
  Return: a single 32 bit two's complement integer

      - error value returned if divisor,r1 is zero
      - error value is returned if minimum int is divided by -1
-----------------------------------------------------------------------------*/

divide:
        push    {lr}

        cmp     r1, #0                @compare divisor to zero
        beq     divbyzero             @if equal branch to special handling
       
        cmp     r1, #-1               @compare divisor to -1
        beq     isnegate              @if same, equivelant to negation 

        sdiv    r0, r0, r1            @run division
        b       enddiv                
          
isnegate:
        bl      negate
        b       enddiv

divbyzero:
        b       error                 @divide by zero returns error

enddiv:
        pop     {lr}
        bx      lr

/*-----------------------------------------------------------------------------
  Name: remain

  Purpose: get remainder of r0/r1
  Recevie: 2 32 bit two's complement integers
  Return: a single 32 bit two's complement integer

      - error value returned when divide returns error
-----------------------------------------------------------------------------*/

remain: 
        push    {lr}

        mov     r2, r0                @dividend copy in r2
        bl      divide                @r0 <== r0//r1

        cmp     r0, #E                @check for error from divide
        beq     endrem

        mul     r3, r1, r0            @r3 <== divisor*quotient
        sub     r0, r2, r3            @r0 <== dividend-r3 == r0%r1
          
endrem:
        pop     {lr}
        bx      lr

/*-----------------------------------------------------------------------------
  Name: power

  Purpose: get r0(N) to the r1(I)th power. (N^Ith)
  Recevie: 2 32 bit two's complement integers
  Return: a single 32 bit two's complement integer

  - error value returned when mul gives error or I is negative

Known Issue: Seg fault for large N  
-----------------------------------------------------------------------------*/

power:
        push    {r4,r5,lr}

        cmp     r0, #1                @compare N to one
        beq     endpower              @if N==1, keep and return        

        mov     r5, r1                @copy I to r5
        mov     r4, r0                @copy N to r4

        cmp     r5, #0                @compare I to 0
        beq     zpower
        cmp     r5, #0                @compare I to 0
        bgt     ploop                 @I>0 pass to loop

negpower:        
        bl      error    
        b       endpower
  
ploop:
        cmp     r5, #1                @compare I to 1
        beq     endpower

        mov     r1, r4
        bl      mul                   @r0 <== r0*r4
        
        cmp     r0, #E                @check if mul returned error
        beq     endpower              

        add     r5, r5, #-1            @r5--

        b       ploop        

zpower:
        mov     r0, #1                @N^0 == 1

endpower:
        pop     {r4,r5,lr}
        bx      lr


/*---------------------------------------------------------------------------*/

factorial:
        push    {lr}

        mov     r2, r0

        cmp     r0, #0
        beq     factzero
        blt     factneg

floop: 
        sub     r2, r2, #1            @r2--

        cmp     r2, #1
        beq     endfact

        mul     r0, r0, r2

        b       floop

factzero:
        mov     r0, #1
        b       endfact

factneg:
        bl      error

endfact:
        pop     {lr}
        bx      lr

/*---------------------------------------------------------------------------*/

error:
        push    {lr}
          
        mov     r0, #E                @return error val 0x80000000  

        pop     {lr}
        bx      lr
