/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#ifndef BITMANIPULATION_H
#define BITMANIPULATION_H

#include "utils.h"

/**********************************\
 ==================================
 
          Bit manipulation
 
 ==================================
\**********************************/

// macro: set square bit in bitboard
#define set_bit(bitboard, square) ((bitboard) |= (1ULL << (square)))

// macro: get square bit from bitboard
#define get_bit(bitboard, square) ((bitboard) & (1ULL << (square)))

// macro: pop square bit from bitboard
#define pop_bit(bitboard, square) ((bitboard) &= ~(1ULL << (square)))

// count bits within a bitboard
int count_bits(U64 bitboard);

// get least significant 1st bit (ls1b) index
int get_ls1b_index(U64 bitboard);

#endif