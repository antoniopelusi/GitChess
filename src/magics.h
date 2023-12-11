/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#ifndef MAGIC_H
#define MAGIC_H

#include "utils.h"

/**********************************\
 ==================================
 
               Magics
 
 ==================================
\**********************************/

// find appropriate magic number
U64 find_magic_number(int square, int relevant_bits, int bishop);

// init magic numbers
void init_magic_numbers();

// init slider piece's attack tables
void init_sliders_attacks(int bishop);

// get bishop attacks
U64 get_bishop_attacks(int square, U64 occupancy);

// get bishop attacks
U64 get_rook_attacks(int square, U64 occupancy);

#endif