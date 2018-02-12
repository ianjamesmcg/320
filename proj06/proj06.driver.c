#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

/*******************************************************************************
 Ian McGregor
 CSE320
 Computer Project #6
*******************************************************************************/

int main()
{
  printf("\nCSE320 US17 | Computer Project #5 Test Cases | Ian McGregor\n\n");

  char result[80];
  unsigned mInstr;

  mInstr = 0xe086a007;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe286a007;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe1520003;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe1a01003;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe006500a;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe334002d;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe344002d;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe3c31004;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe0c84003;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  mInstr = 0xe1854003;
  decode( mInstr, result );
  printf( "Machine Instruction: %#8x Assembly code: %s", mInstr, result);

  return 0;
}

