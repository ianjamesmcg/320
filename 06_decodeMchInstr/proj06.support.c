#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

/*******************************************************************************
Ian McGregor
CSE320 US17
Computer Project #6
*******************************************************************************/

/*-------------------------------------------------
  Name:     decode
 
  Purpose:  translate ARM machine instructions to assembly language
  Receive:  32 bit hexidecimal ARM machine language instruction
  Return:   equivelant instruction in assembly code
--------------------------------------------------*/
void decode( unsigned mInstr, char result[80] )
{
  //parse I and S bits from mInstr
  unsigned iBit = (mInstr >> 25) & 0x00000001;
  unsigned sBit = (mInstr >> 20) & 0x00000001;


  //translate second operand to string based on I value
  unsigned op2int;
  char op2str[5];
  if (iBit){
    op2int = mInstr & 0x000000ff;
    sprintf(op2str, "#%#x", op2int );
  }
  else{
    op2int = mInstr & 0x0000000f;
    sprintf(op2str, "r%d", op2int );
  }

  //parse opcode from mInstr
  unsigned opcode = (mInstr >> 21) & 0x0000000f;  
  //reference array to get opcode string from int rep
  char* opcodeRef[16] = {"and", "eor", "sub", "rsb", "add", "adc", "sbc", "rsc",
  "tst", "teq", "cmp", "cmn", "orr", "mov", "bic", "mvn"};

  //parse rn and rd from mInstr
  unsigned rn = (mInstr >> 16) & 0x0000000f;
  unsigned rd = (mInstr >> 12) & 0x0000000f;

  //if comparrison opcode
  if ((opcode > 7) && (opcode < 12))
  {

    //comparisons must have S bit on
    if (sBit == 0)
    {
      sprintf( result, "Instruction invalid, cannot compare with S bit off\n" ); 
    }

    //print to result sting with correct operands
    else
    {
      sprintf( result, "%s r%d %s\n", opcodeRef[opcode], rn, op2str );
    }

  }

  //if movement opcodes, print to result string w/ correct operands
  else if ((opcode == 13) || (opcode == 15))  
  {  
    sprintf( result, "%s r%d %s\n", opcodeRef[opcode], rd, op2str );
  }

  //print to result string w/correct operands
  else
  {
    sprintf( result, "%s r%d r%d %s\n", opcodeRef[opcode], rd, rn, op2str );
  } 
}
