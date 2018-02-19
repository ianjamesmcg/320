/******************************************************************************
  Project #9
  Ian McGregor
******************************************************************************/

          .global search, insert, delete

          .data
          .balign 4
student:  .skip   4

          .text
          .balign 4


/*****************************************************************************/

search:   push    {r4,r5,lr}

          ldrh    r3, [r0, #2]        @r3 <== table.count
          ldr     r4, [r0, #8]        @r4 <== pointer to array of students
sloop: 
          cmp     r3, #0              @compare student count to zero 
          beq     notfound            @if equal, end of table, goto notfound

          ldr     r5, [r4]            @r5 <== student ID
          cmp     r5, r1              @compare student ID to search ID
          bgt     notfound            @r5>r1 goto notfound
          beq     found               @r5==r1 goto found
                                      @r5<r1 pass through                            

          add     r4, r4, #40         @r4 <== point to next student ID 
          add     r3, r3, #-1         @decrement from student count

          b       sloop               @goto sloop

notfound:
          mov     r0, #0
          b       endsearch

found:
          mov     r0, #1

endsearch: 
          str     r4, [r2]            @r2 <== address of pointer to student
          pop     {r4,r5,lr}
          bx      lr

/*****************************************************************************/

insert:   push    {r4,r5,r6,r7,r8,lr}
         
          mov     r4, r0          @r4 <== copy of table address
          mov     r5, r1          @r5 <== copy of ID
          mov     r6, r2          @r6 <== copy address of name
          mov     r7, r3          @r7 <== copy of exam#1

          ldr     r2, =student

          bl      search          @search for student

          cmp     r0, #1          @compare search return to 1
          beq     noinsert        @if equal, student pressnt, don't insert               

          b       noinsert        @insert not finished, always display failure

          ldr     r0, [r4, #2]    @table.count
          mov     r1, #40
          mul     r0, r0, r1      
          ldr     r1, [r4, #8]    @address of first student
          add     r0, r1, r0      @address after last student

insloop:
          
          add     r1, r0, #40     @previous student address
          mov     r2, #40
          bl      memmove

          mov     r0, #1
          b       endinsert
noinsert:
          mov     r0, #0          @return zero for no insert
endinsert:
          pop     {r4,r5,r6,r7,r8,lr}
          bx      lr

/*****************************************************************************/

delete:   push    {r4,r5,r6,r7,lr}
          
          mov     r6, r0              @copy of table address
          ldrh    r4, [r0, #2]        @r4 <== table.count
          mov     r7, r4              @r7 <== copy of table.count
          
          add     r4, r4, #-2
          mov     r5, #40              
          mul     r4, r4, r5          
          ldr     r5, [r0, #8]        @r5 <== address of first student
          add     r5, r5, r4          @r5 <== address of second to last student

          ldr     r2, =student        @r2 <== pointer to data symbol

          bl      search              @search for student
          cmp     r0, #1              @compare search return to 1
          beq     pres                @if equal, student is present
          b       enddelete           @otherwise, no student present to delete

pres:     
          mov     r3, r2 
          ldr     r4, [r3]
dloop:    
          mov     r0, r4              @r0 <== address of student to be deleted                 
          add     r1, r0, #40         @r1 <== address of next student
          mov     r2, #40             @r2 <== size of one struct student
          bl      memmove             @copy next student to current spot
    
          cmp     r5, r4              @compare current address to second last
          beq     enddloop            @if equal copy complete

          add     r4, r4, #40         @next student address
          b       dloop


enddloop:
          mov     r0, #1              @return delete success
          sub     r7, r7, #1          @table.count--
          strh    r7, [r6, #2]        @store new count
enddelete:
          pop     {r4,r5,r6,r7,lr}
          bx      lr






