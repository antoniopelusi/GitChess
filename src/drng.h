/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#ifndef DRNG_H
#define DRNG_H

#include "utils.h"

/**********************************\
 ==================================
 
                DRNG
 
 ==================================
\**********************************/

// generate 32-bit pseudo random numbers
unsigned int get_random_U32_number();

// generate 64-bit pseudo random numbers
U64 get_random_U64_number();

// generate magic number candidate
U64 generate_magic_number();

#endif