/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#ifndef ATTACK_H
#define ATTACK_H

#include "bitmanipulation.h"

/**********************************\
 ==================================
 
              Attacks
 
 ==================================
\**********************************/

/*
        not A file

 8   0 1 1 1 1 1 1 1
 7   0 1 1 1 1 1 1 1
 6   0 1 1 1 1 1 1 1
 5   0 1 1 1 1 1 1 1
 4   0 1 1 1 1 1 1 1
 3   0 1 1 1 1 1 1 1
 2   0 1 1 1 1 1 1 1
 1   0 1 1 1 1 1 1 1

     a b c d e f g h


        not H file
     
 8   1 1 1 1 1 1 1 0
 7   1 1 1 1 1 1 1 0
 6   1 1 1 1 1 1 1 0
 5   1 1 1 1 1 1 1 0
 4   1 1 1 1 1 1 1 0
 3   1 1 1 1 1 1 1 0
 2   1 1 1 1 1 1 1 0
 1   1 1 1 1 1 1 1 0

     a b c d e f g h


       not HG file

 8   1 1 1 1 1 1 0 0
 7   1 1 1 1 1 1 0 0
 6   1 1 1 1 1 1 0 0
 5   1 1 1 1 1 1 0 0
 4   1 1 1 1 1 1 0 0
 3   1 1 1 1 1 1 0 0
 2   1 1 1 1 1 1 0 0
 1   1 1 1 1 1 1 0 0

     a b c d e f g h


       not AB file

 8   0 0 1 1 1 1 1 1
 7   0 0 1 1 1 1 1 1
 6   0 0 1 1 1 1 1 1
 5   0 0 1 1 1 1 1 1
 4   0 0 1 1 1 1 1 1
 3   0 0 1 1 1 1 1 1
 2   0 0 1 1 1 1 1 1
 1   0 0 1 1 1 1 1 1

     a b c d e f g h
*/

// not A file constant
static const U64 not_a_file = 18374403900871474942ULL;

// not H file constant
static const U64 not_h_file = 9187201950435737471ULL;

// not HG file constant
static const U64 not_hg_file = 4557430888798830399ULL;

// not AB file constant
static const U64 not_ab_file = 18229723555195321596ULL;

// bishop relevant occupancy bit count for every square on board
static const int bishop_relevant_bits[64] = {
    6, 5, 5, 5, 5, 5, 5, 6, 
    5, 5, 5, 5, 5, 5, 5, 5, 
    5, 5, 7, 7, 7, 7, 5, 5, 
    5, 5, 7, 9, 9, 7, 5, 5, 
    5, 5, 7, 9, 9, 7, 5, 5, 
    5, 5, 7, 7, 7, 7, 5, 5, 
    5, 5, 5, 5, 5, 5, 5, 5, 
    6, 5, 5, 5, 5, 5, 5, 6
};

// rook relevant occupancy bit count for every square on board
static const int rook_relevant_bits[64] = {
    12, 11, 11, 11, 11, 11, 11, 12, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    11, 10, 10, 10, 10, 10, 10, 11, 
    12, 11, 11, 11, 11, 11, 11, 12
};

// mask pawn attacks
U64 mask_pawn_attacks(int side, int square);

// mask knight attacks
U64 mask_knight_attacks(int square);

// mask king attacks
U64 mask_king_attacks(int square);

// mask bishop attacks
U64 mask_bishop_attacks(int square);

// mask rook attacks
U64 mask_rook_attacks(int square);

// mask rook attacks on the fly
U64 mask_bishop_attacks_block(int square, U64 block);

// mask rook attacks on the fly
U64 mask_rook_attacks_block(int square, U64 block);

// init leaper pieces attack
void init_leapers_attacks();

// set occupancies
U64 set_occupancy(int index, int bits_in_mask, U64 attack_mask);

#endif