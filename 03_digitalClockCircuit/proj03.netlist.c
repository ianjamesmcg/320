
/******************************************************************************
  Project #3
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- User interface to count from 0 to F seeing if the
  currect digit is present in my PID and if so an LED clock like 7 panel display
  of it
******************************************************************************/

void simnet()
{
  //circuit signals
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

  //counter control signals
  Signal Strobe (1);
  Signal ResetA (1);
  Signal ResetB (1);

  //pulsers to toggle counter controls
  Pulser ((SD("1a"), "r -- Reset counter"), ResetA, 'r', 10000);
  Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

  //counter reset is active low
  Not (SD("1b"), ResetA, ResetB);

  //counts through one digit hexidecimal
  //increments by one on Strobe signal, output as 4 1-bit binary signals
  //reset signal (active low) sets current value to zero
  Counter ((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe), (w,x,y,z));

//uncomment Probes to display 4-bit counter output
//  Probe ((SD("1d"), "w"), w);
//  Probe ((SD("2d"), "x"), x);
//  Probe ((SD("3d"), "y"), y);
//  Probe ((SD("4d"), "z"), z);
  
//uncomment Switches and disconnect Counter to manually control inputs wxyz
//  Switch( SD("1e"), w, 'w' );
//  Switch( SD("2e"), x, 'x' );
//  Switch( SD("3e"), y, 'y' );
//  Switch( SD("4e"), z, 'z' );

  //algebraic transform of 4 bit hex value to LED 7 panel display pattern
  circuits( SD("1f-5f"), w, x, y, z, Present, a, b, c, d, e, f, g);

  //displays if the current hex is present in my PID
  Probe ( (SD("1h"), "P"), Present );

  //dispalys 7 panel led activation as computed by circuits function
  Probe ( (SD("2h"), "a"), a );
  Probe ( (SD("3i"), "b"), b );
  Probe ( (SD("5i"), "c"), c );
  Probe ( (SD("6h"), "d"), d );
  Probe ( (SD("5g"), "e"), e );
  Probe ( (SD("3g"), "f"), f );
  Probe ( (SD("4h"), "g"), g );
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
  receives four signals as inputs and return eight signals as outputs
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );
  
  //declareing not/and signals required to represent algebraic minimizations
  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7;
  
  //implement NOT gates
  Not ( SD(sd,"1a"), w, notw );
  Not ( SD(sd,"2a"), x, notx );
  Not ( SD(sd,"3a"), y, noty );
  Not ( SD(sd,"4a"), z, notz );

  //implement AND gates
  And ( SD(sd,"1d"), (notw, notx, noty), and1 );
  And ( SD(sd,"2d"), (notw, notz), and2 );
  And ( SD(sd,"3d"), (notx, notz), and3 );
  And ( SD(sd,"4d"), (notw, y), and4 );
  And ( SD(sd,"5d"), (noty, notz), and5 );
  And ( SD(sd,"6d"), (notx, noty, notz), and6 );

  //OR gates, each representing the algebraic minimization function of one
  //display probe
  Or ( SD(sd,"1g"), (and1, and2, and3), Present );
  Or ( SD(sd,"2g"), (and3, y), a );
  Or ( SD(sd,"3g"), (and3, noty), b );
  Or ( SD(sd,"4g"), (w, x, noty), c );
  Or ( SD(sd,"5g"), (and4, and6), d );
  Or ( SD(sd,"6g"), (and3, y), e );
  Or ( SD(sd,"7e"), (and5, w, x), f );
  Or ( SD(sd,"8e"), (w, x, y), g );
}

