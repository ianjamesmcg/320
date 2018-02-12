 
/****************************************************************************
  Implements the Boolean functions F1 = a + b', F2 = a + a'b'
****************************************************************************/ 
 
#include <Sim.h>                       // Interface to the "sim" package
 
void simnet()                          // Function must be named "simnet"
{
  Signal a, b, F1, F2;                // Switch and output objects 
 
  Signal nota, notb;
  Signal and1;                   // Intermediate objects 
 
  // Components and interconnections
 
  Switch ( SD("1a"), a, 'a' );         // Switch a controlled by 'a' key
  Switch ( SD("3a"), b, 'b' );         // Switch b controlled by 'b' key
 
  Not ( SD("1b"), a, nota );           // NOT gates
  Not ( SD("3b"), b, notb );
 
  And ( SD("2c"), (nota, notb), and1 );   // AND gate                                      
  Or ( SD("2d"), (a, notb), F1 );    // OR gates
  Or ( SD("3d"), (a, and1), F2 );

  Probe ( (SD("2e"), "F1"), F1 );  // Probes
  Probe ( (SD("3e"), "F2"), F2 );
}

