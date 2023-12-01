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
#include <stdio.h>

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

// count bits within a bitboard
static inline int count_bits(U64 bitboard);

// get least significant 1st bit (ls1b) index
static inline int get_ls1b_index(U64 bitboard);

// print the bitboard
void print_bitboard(U64 bitboard);

#endif