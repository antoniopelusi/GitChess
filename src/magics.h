/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#ifndef MAGIC_H
#define MAGIC_H

#include <string.h>
#include "attack.h"
#include "drng.h"

/**********************************\
 ==================================
 
               Magics
 
 ==================================
\**********************************/

// rook magic numbers
extern U64 rook_magic_numbers[64];

// bishop magic numbers
extern U64 bishop_magic_numbers[64];

// find appropriate magic number
U64 find_magic_number(int square, int relevant_bits, int bishop);

// init magic numbers
void init_magic_numbers();

#endif