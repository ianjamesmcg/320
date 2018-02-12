/******************************************************************************
  allAscii.c -- sends ascii chars 0x00-0x7F to stdout stream in ascending order

  Ian McGregor
  06/13/17
******************************************************************************/

#include <stdio.h>


int main()
{

  int i;
  for( i = 0x00 ; i <= 0x7F ; i++ )
  {
    printf("%d:", i);
    putchar(i);
    printf("\n");
  }  

  return 0;
}
