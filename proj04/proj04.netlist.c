
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // User control for initialize to 0xA and clock cycle through A468120
  Pulser ((SD("1a"), "i -- Initialization"), Init, 'i', 10000);
  Pulser ((SD("3a"), "c -- Clock"), Clock, 'c', 10000);
 
  // takes initialization and clock signal, outputs current 4bit dff store 
  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Display binary of current D flip flop stored values
  Probe ((SD("1d"), "w"), w);
  Probe ((SD("2d"), "x"), x);
  Probe ((SD("3d"), "y"), y);
  Probe ((SD("4d"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  Signal notw, notx, noty, notz, dw, dx, dy, dz, and1, and2, and3, and4;

  // 4bit store, intialize to 1010, next val d$ goes to output $ on clock
  Dff (SD(sd,"1a"), (Init, dw, Clock, Zero), w);
  Dff (SD(sd,"3a"), (Zero, dx, Clock, Init), x);
  Dff (SD(sd,"5a"), (Init, dy, Clock, Zero), y);
  Dff (SD(sd,"7a"), (Zero, dz, Clock, Init), z);

  // not gates needed for next val computation
  Not (SD(sd,"1b"), w, notw);
  Not (SD(sd,"3b"), x, notx);
  Not (SD(sd,"5b"), y, noty);
  Not (SD(sd,"7b"), z, notz);

  // intermediate and gates for next val computation
  And (SD(sd,"2d"), (notw,notx,noty,notz), and1);
  And (SD(sd,"2d"), (x,y), and2);
  And (SD(sd,"4d"), (x,noty), and3);
  And (SD(sd,"4d"), (w,y), and4);

  // and/or gates sending output to next val of DFF's
  And (SD(sd,"6e"), (notw,noty), dy);
  And (SD(sd,"8e"), (w,noty), dz);

  Or (SD(sd,"2e"), (and1, and2), dw);
  Or (SD(sd,"4e"), (and3, and4), dx);

  
}

