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
unsigned int get_random_U32_number()
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

// generate 64-bit pseudo random numbers
U64 get_random_U64_number()
{
    // init random numbers slicing 16 bits from ms1b side
    U64 n1 = (U64)(get_random_U32_number() & 0xFFFF);
    U64 n2 = (U64)(get_random_U32_number() & 0xFFFF);
    U64 n3 = (U64)(get_random_U32_number() & 0xFFFF);
    U64 n4 = (U64)(get_random_U32_number() & 0xFFFF);

    // return random number
    return n1 | (n2 << 16) | (n3 << 32) | (n4 << 48);
}

// generate magic number candidate
U64 generate_magic_number()
{
    return get_random_U64_number() & get_random_U64_number() & get_random_U64_number();
}