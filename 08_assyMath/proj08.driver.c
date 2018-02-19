/*
   Project #8
   Ian McGregor
*/

#include <stdio.h>
#include "/user/cse320/Projects/project08.support.h"

int main()
{
  unsigned inputA_int = 0x7FFFFFFF;
  unsigned inputB_int = 0;
  unsigned result_int = 0;

  printf( "NEGATE TESTING\n" );

  result_int = negate(inputA_int);
  printf( "Negation of %11d is %11d\n", inputA_int, result_int );

  inputA_int = 0;
  result_int = negate(inputA_int);
  printf( "Negation of %11d is %11d\n", inputA_int, result_int );

  inputA_int = 0x80000001;
  result_int = negate(inputA_int);
  printf( "Negation of %11d is %11d\n", inputA_int, result_int );

  inputA_int = 0x80000000;
  result_int = negate(inputA_int);
  printf( "Negation of %11d is %11d\n", inputA_int, result_int );

/*---------------------------------------------------------------------------*/

  printf( "\nABSOLUTE TESTING\n" );

  inputA_int = 0x7FFFFFFF;
  result_int = absolute(inputA_int);
  printf( "Absolute value of %11d is %11d\n", inputA_int, result_int );

  inputA_int = 0;
  result_int = absolute(inputA_int);
  printf( "Absolute value of %11d is %11d\n", inputA_int, result_int );

  inputA_int = 0x80000001;
  result_int = absolute(inputA_int);
  printf( "Absolute value of %11d is %11d\n", inputA_int, result_int );

  inputA_int = 0x80000000;
  result_int = absolute(inputA_int);
  printf( "Absolute value of %11d is %11d\n", inputA_int, result_int );

/*---------------------------------------------------------------------------*/

  printf( "\nADD TESTING\n" );
  
  inputA_int = 0;
  inputB_int = 0x7fffffff;
  result_int = add(inputA_int, inputB_int);
  printf( "%11d + %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = 0x80000001;
  inputB_int = 0;
  result_int = add(inputA_int, inputB_int);
  printf( "%11d + %11d = %11d\n", inputA_int, inputB_int, result_int );
  
  inputA_int = 150;
  inputB_int = 250;
  result_int = add(inputA_int, inputB_int);
  printf( "%11d + %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = -150;
  inputB_int = -250;
  result_int = add(inputA_int, inputB_int);
  printf( "%11d + %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = -150;
  inputB_int = 250;
  result_int = add(inputA_int, inputB_int);
  printf( "%11d + %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = 0x80000001;
  inputB_int = 0xFFFFFFFE;
  result_int = add(inputA_int, inputB_int);
  printf( "%11d + %11d = %11d\n", inputA_int, inputB_int, result_int );
 
  inputA_int = 0x7FFFFFFF;
  inputB_int = 0x00000001;
  result_int = add(inputA_int, inputB_int);
  printf( "%11d + %11d = %11d\n", inputA_int, inputB_int, result_int );

/*---------------------------------------------------------------------------*/

  printf( "\nSUB TESTING\n" );  

  inputA_int = 0;
  inputB_int = 0x7fffffff;
  result_int = sub(inputA_int, inputB_int);
  printf( "%11d - %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = 0x80000001;
  inputB_int = 0;
  result_int = sub(inputA_int, inputB_int);
  printf( "%11d - %11d = %11d\n", inputA_int, inputB_int, result_int );
  
  inputA_int = 150;
  inputB_int = 250;
  result_int = sub(inputA_int, inputB_int);
  printf( "%11d - %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = -150;
  inputB_int = -250;
  result_int = sub(inputA_int, inputB_int);
  printf( "%11d - %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = -150;
  inputB_int = 250;
  result_int = sub(inputA_int, inputB_int);
  printf( "%11d - %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = 0x80000001;
  inputB_int = 0x00000002;
  result_int = sub(inputA_int, inputB_int);
  printf( "%11d - %11d = %11d\n", inputA_int, inputB_int, result_int );
 
  inputA_int = 0x7FFFFFFF;
  inputB_int = 0xFFFFFFFF;
  result_int = sub(inputA_int, inputB_int);
  printf( "%11d - %11d = %11d\n", inputA_int, inputB_int, result_int );


/*---------------------------------------------------------------------------*/

  printf( "\nMUL TESTING\n" );
 
  inputA_int = 0x7FFFFFFF;
  inputB_int = 0x00000000;
  result_int = mul(inputA_int, inputB_int);  
  printf( "%11d * %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = 0x7FFFFFFF;
  inputB_int = -1;
  result_int = mul(inputA_int, inputB_int);  
  printf( "%11d * %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = 0x7FFFFFFF;
  inputB_int = 0x7FFFFFFF;
  result_int = mul(inputA_int, inputB_int);  
  printf( "%11d * %11d = %11d\n", inputA_int, inputB_int, result_int );

  inputA_int = 0x80000001;
  inputB_int = -2;
  result_int = mul(inputA_int, inputB_int);  
  printf( "%11d * %11d = %11d\n", inputA_int, inputB_int, result_int );
 
  inputA_int = 0x80000000;
  inputB_int = -1;
  result_int = mul(inputA_int, inputB_int);  
  printf( "%11d * %11d = %11d\n", inputA_int, inputB_int, result_int ); 

/*---------------------------------------------------------------------------*/

  printf( "\nDIVIDE TESTING\n" );

  inputA_int = 51;
  inputB_int = 10;
  result_int = divide(inputA_int, inputB_int);
  printf( "%11d // %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = -52;
  inputB_int = 10;
  result_int = divide(inputA_int, inputB_int);
  printf( "%11d // %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 53;
  inputB_int = -10;
  result_int = divide(inputA_int, inputB_int);
  printf( "%11d // %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = -54;
  inputB_int = -10;
  result_int = divide(inputA_int, inputB_int);
  printf( "%11d // %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 55;
  inputB_int = 0;
  result_int = divide(inputA_int, inputB_int);
  printf( "%11d // %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 0x80000000;
  inputB_int = -1;
  result_int = divide(inputA_int, inputB_int);
  printf( "%11d // %11d = %11d\n", inputA_int, inputB_int, result_int ); 

/*---------------------------------------------------------------------------*/

  printf( "\nREMAIN TESTING\n" );

  inputA_int = 51;
  inputB_int = 10;
  result_int = remain(inputA_int, inputB_int);
  printf( "%11d r %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = -52;
  inputB_int = 10;
  result_int = remain(inputA_int, inputB_int);
  printf( "%11d r %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 53;
  inputB_int = -10;
  result_int = remain(inputA_int, inputB_int);
  printf( "%11d r %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = -54;
  inputB_int = -10;
  result_int = remain(inputA_int, inputB_int);
  printf( "%11d r %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 55;
  inputB_int = 0;
  result_int = remain(inputA_int, inputB_int);
  printf( "%11d r %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 0x80000000;
  inputB_int = -1;
  result_int = remain(inputA_int, inputB_int);
  printf( "%11d r %11d = %11d\n", inputA_int, inputB_int, result_int ); 

/*---------------------------------------------------------------------------*/

  printf( "\nPOWER TESTING\n" );

  inputA_int = 1;
  inputB_int = 4;
  result_int = power(inputA_int, inputB_int); 
  printf( "%11d ^ %11d = %11d\n", inputA_int, inputB_int, result_int ); 
  
  inputA_int = 2;
  inputB_int = -1;
  result_int = power(inputA_int, inputB_int); 
  printf( "%11d ^ %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 2;
  inputB_int = 0;
  result_int = power(inputA_int, inputB_int); 
  printf( "%11d ^ %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 2;
  inputB_int = 2;
  result_int = power(inputA_int, inputB_int); 
  printf( "%11d ^ %11d = %11d\n", inputA_int, inputB_int, result_int ); 

  inputA_int = 10000;
  inputB_int = 2;
  result_int = power(inputA_int, inputB_int); 
  printf( "%11d ^ %11d = %11d\n", inputA_int, inputB_int, result_int ); 

/*---------------------------------------------------------------------------*/
 
  printf( "\nFACTORIAL TESTING\n" );
 
  inputA_int = 4;
  result_int = factorial(inputA_int);
  printf( "Input int: %d\n", inputA_int ); 
  printf( "Factorial result: %d\n", result_int ); 
 
/*---------------------------------------------------------------------------*/

  return 0;
}
