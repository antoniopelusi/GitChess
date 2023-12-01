/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include "drng.h"

/**********************************\
 ==================================
 
                DRNG
 
 ==================================
\**********************************/

// pseudo random number state
unsigned int state = 1804289383;

// generate 32-bit pseudo random numbers
unsigned int get_random_number()
{
    // get current state
    unsigned int number = state;

    // XOR shift algorithm
    number ^= number << 13;
    number ^= number >> 17;
    number ^= number << 5;

    // update random state
    state = number;

    // return random number
    return number;
}