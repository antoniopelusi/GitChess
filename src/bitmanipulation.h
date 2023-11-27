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
#define set_bit(bitboard, square) (bitboard |= (1ULL << square))

// macro: get square bit from bitboard
#define get_bit(bitboard, square) (bitboard & (1ULL << square))

// macro: pop square bit from bitboard
#define pop_bit(bitboard, square) (get_bit(bitboard, square) ? bitboard ^= (1ULL << square) : 0)

// print the bitboard
void print_bitboard(U64 bitboard);

#endif