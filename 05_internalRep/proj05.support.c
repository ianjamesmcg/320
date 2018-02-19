#include "/user/cse320/Projects/project05.support.h"

/***************************************************************************
  library module to implement the functions declared in project05.support.h
****************************************************************************/

/* return positive infinity */
float get_infinity()
{
  union sp_object num;

  num.irep = 0x7f800000;

  return num.frep;
}

/* return not a number */
float get_nan()
{
  union sp_object num;

  num.irep = 0x7f800001; //assign nan value using hex rep 

  return num.frep; 
}

/* return largest positive single precision float */
float get_max_normal()
{
  union sp_object num;

  num.irep = 0x7f7fffff; //assign max val using hex rep

  return num.frep;
}

/* return smallest positive single precision float */
float get_min_normal()
{
  union sp_object num;

  num.irep = 0x00800000; //assign min val using hex rep

  return num.frep;
}

/* return largest positive denormal sp float */
float get_max_denormal()
{
  union sp_object num;

  num.irep = 0x007fffff; //assign max denormal using hex rep

  return num.frep;
}

/* return smallest positive denormal sp float */
float get_min_denormal()
{
  union sp_object num;

  num.irep = 0x00000001; //assign min denormal using hex rep

  return num.frep;
}

/* return 1 if arg is negative, zero if positive*/
int is_negative( float arg )
{
  union sp_object num;
  num.frep = arg;

  /* shift sign bit to one's place and mask out leading digits */
  return (num.irep  >> 31) & (0x00000001);
} 

/* return 1 if arg is infinite, zero otherwise */
int is_infinity( float arg )
{
  union sp_object num;
  num.frep = arg;

  /* shift off sign bit and compare for infinity hex pattern */
  return ((num.irep << 1) == 0xff000000);
}

/* return 1 if arg is denormal, zero otherwise */
int is_denormal( float arg )
{
  union sp_object num;
  num.frep = arg;

  /* shift off sign bit, then fraction bits, denormal will be all 0's */
  return ((num.irep << 1) ^ 0xff000000 ) > 0xff000000;
}

/* return 1 if arg's value is zero, return 0 otherwise*/
int is_zero( float arg )
{
  union sp_object num;
  num.frep = arg;

  /* shift off sign bit, compare to zero */
  return ((num.irep << 1) == 0);
}

/* return 1 if arg is not a number, 0 otherwise */
int is_nan( float arg )
{
  union sp_object num;
  num.frep = arg;

  /* shift off sign bit, nan will have some nonzero digit after 0xff */
  return ((num.irep << 1) > 0xff000000);
}

/* returns the negative of arg */ 
float negate( float arg )
{
  union sp_object num;
  union sp_object neg;
  num.frep = arg;

  /* XOR flips sign bit, passes current value for the rest */
  neg.irep = num.irep ^ 0x80000000;
  return neg.frep;
}

/* returns absolute value of arg */
float absolute( float arg )
{
  union sp_object num;
  union sp_object abs; 
  num.frep = arg;
 
  /* AND sets sign bit to 0, passes current value for the rest */ 
  abs.irep = num.irep & 0x7fffffff; 
  return abs.frep;
}


