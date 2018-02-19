#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"

/***************************************************************************
  test bed for functions defined in proj05.support.c, declared in
  proj05.support.h
****************************************************************************/

int main()
{
  /* header */
  printf( "\n------------------CSE320 project#5 testing | mcgreg45 | US17----------------\n" );

  /* union object will be assigned function return value's and called to print
   * them out as floating point and hex integer representations */
  union sp_object num; 
 
  printf( "\nThese functions return some special values in single precision \
floating point representation\n\n" );

  /*  return infinity as float */
  num.frep = get_infinity();
  printf( "%-19s%-8s", "get_infinity()", "returns" );
  printf( "Real#: %-12f  Hex integer: %08x \n", num.frep, num.irep ); 

  /* return not a number, float */
  num.frep = get_nan();
  printf( "%-19s%-8s", "get_nan()", "returns" );
  printf( "Real#: %-12f  Hex integer: %08x \n", num.frep, num.irep ); 

  /* return largest 32bit float */
  num.frep = get_max_normal();
  printf( "%-19s%-8s", "get_max_normal()", "returns" );
  printf( "Real#: %-.7e Hex integer: %08x \n", num.frep, num.irep ); 
 
  /* smallest positive 32bit float */
  num.frep = get_min_normal();
  printf( "%-19s%-8s", "get_min_normal()", "returns" );
  printf( "Real#: %-.7e Hex integer: %08x \n", num.frep, num.irep ); 
 
  /* largest positive denormal 32bit float */
  num.frep = get_max_denormal();
  printf( "%-19s%-8s", "get_max_denormal()", "returns" );
  printf( "Real#: %-.7e Hex integer: %08x \n", num.frep, num.irep ); 
 
  /* smallest positive denormal 32bit float */
  num.frep = get_min_denormal();
  printf( "%-19s%-8s", "get_min_denormal()", "returns" );
  printf( "Real#: %-.7e Hex integer: %08x \n", num.frep, num.irep ); 

  
  
  
  printf( "\nThe next functions will check a given sp float for certain conditions.\n" );

  printf( "\nTest for negativity\n" );
  num.frep = -29.08;
  printf( "real#: %10.6f Hex int: %08x, is_negative returns %d \n", num.frep, num.irep, is_negative(num.frep) );
  num.frep = 35.0;
  printf( "real#: %10.6f Hex int: %08x, is_negative returns %d \n", num.frep, num.irep, is_negative(num.frep) );
  num.frep = .00005;
  printf( "real#: %10.6f Hex int: %08x, is_negative returns %d \n", num.frep, num.irep, is_negative(num.frep) );
  num.frep = -1.01;
  printf( "real#: %10.6f Hex int: %08x, is_negative returns %d \n", num.frep, num.irep, is_negative(num.frep) );
  
  printf( "\nTest for infinity, true for + and -\n" );
  num.irep = 0x7f800000;
  printf( "real#: %10.6f Hex int: %08x, is_infinity returns %d \n", num.frep, num.irep, is_infinity(num.frep) );
  num.irep = 0x7f800001;
  printf( "real#: %10.6f Hex int: %08x, is_infinity returns %d \n", num.frep, num.irep, is_infinity(num.frep) );
  num.irep = 0xff800000;
  printf( "real#: %10.6f Hex int: %08x, is_infinity returns %d \n", num.frep, num.irep, is_infinity(num.frep) );
  num.frep = -13.23;
  printf( "real#: %10.6f Hex int: %08x, is_infinity returns %d \n", num.frep, num.irep, is_infinity(num.frep) );
  
  printf( "\nTest for nan-not a number\n" );
  num.irep = 0x7f800000;
  printf( "real#: %10.6f Hex int: %08x, is_nan returns %d \n", num.frep, num.irep, is_nan(num.frep) );
  num.frep = get_nan();
  printf( "real#: %10.6f Hex int: %08x, is_nan returns %d \n", num.frep, num.irep, is_nan(num.frep) );
  num.irep = 0xff804100;
  printf( "real#: %10.6f Hex int: %08x, is_nan returns %d \n", num.frep, num.irep, is_nan(num.frep) );
  num.frep = -13.23; 
  printf( "real#: %10.6f Hex int: %08x, is_nan returns %d \n", num.frep, num.irep, is_nan(num.frep) );
  
  printf( "\nTest for zero\n" );
  num.irep = 0x80000000;
  printf( "real#: %10.6f Hex int: %08x, is_zero returns %d \n", num.frep, num.irep, is_zero(num.frep) );
  num.frep = get_nan();
  printf( "real#: %10.6f Hex int: %08x, is_zero returns %d \n", num.frep, num.irep, is_zero(num.frep) );
  num.frep = 0;
  printf( "real#: %10.6f Hex int: %08x, is_zero returns %d \n", num.frep, num.irep, is_zero(num.frep) );
  num.frep = -13.23;
  printf( "real#: %10.6f Hex int: %08x, is_zero returns %d \n", num.frep, num.irep, is_zero(num.frep) );

  printf( "\nTest for denormal, true for + and -\n" );
  num.frep = get_max_denormal();
  printf( "real#: %13.6e Hex int: %08x, is_denormal returns %d \n", num.frep, num.irep, is_denormal(num.frep) );
  num.frep = get_max_normal();
  printf( "real#: %13.6e Hex int: %08x, is_denormal returns %d \n", num.frep, num.irep, is_denormal(num.frep) );
  num.frep = 0;
  printf( "real#: %13.6e Hex int: %08x, is_denormal returns %d \n", num.frep, num.irep, is_denormal(num.frep) );
  num.irep = 0x80700023;
  printf( "real#: %13.6e Hex int: %08x, is_denormal returns %d \n", num.frep, num.irep, is_denormal(num.frep) );



  
  printf( "\nThe last two functions return an alteration of the given float\n\n" );

  printf( "Return the negative\n" );
  union sp_object neg;

  num.irep = 0x7f800000;
  neg.frep = negate(num.frep);
  printf( "origin         real#: %10.3f Hex int: %08x\n", num.frep, num.irep );
  printf( "negate returns real#: %10.3f Hex int: %08x\n", neg.frep, neg.irep );
  
  num.frep = -123.35;
  neg.frep = negate(num.frep);
  printf( "origin         real#: %10.3f Hex int: %08x\n", num.frep, num.irep );
  printf( "negate returns real#: %10.3f Hex int: %08x\n", neg.frep, neg.irep );



  printf( "\nReturn the absolute value\n" );
  union sp_object abs;
  
  num.frep = -532;
  abs.frep = absolute(num.frep);
  printf( "origin           real#: %10.3f Hex int: %08x\n", num.frep, num.irep );
  printf( "absolute returns real#: %10.3f Hex int: %08x\n", abs.frep, abs.irep );
 
  num.irep = 0x807fffff;
  abs.frep = absolute(num.frep);
  printf( "origin           real#: %10.3e Hex int: %08x\n", num.frep, num.irep );
  printf( "absolute returns real#: %10.3e Hex int: %08x\n", abs.frep, abs.irep );

  printf("\nThat's it, bye!\n\n");

  return 0;
}
