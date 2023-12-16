/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#ifndef ATTACK_H
#define ATTACK_H

#include "utils.h"

/**********************************\
 ==================================
 
              Attacks
 
 ==================================
\**********************************/

/* 
     not A file          not H file         not HG files      not AB files
      bitboard            bitboard            bitboard          bitboard

 8  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
 7  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
 6  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
 5  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
 4  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
 3  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
 2  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
 1  0 1 1 1 1 1 1 1    1 1 1 1 1 1 1 0    1 1 1 1 1 1 0 0    0 0 1 1 1 1 1 1
    
    a b c d e f g h    a b c d e f g h    a b c d e f g h    a b c d e f g h

*/

// not A file constant
extern const U64 not_a_file;

// not H file constant
extern const U64 not_h_file;

// not HG file constant
extern const U64 not_hg_file;

// not AB file constant
extern const U64 not_ab_file;

// bishop relevant occupancy bit count for every square on board
extern const int bishop_relevant_bits[64];

// rook relevant occupancy bit count for every square on board
extern const int rook_relevant_bits[64];

// rook magic numbers
extern U64 rook_magic_numbers[64];

// bishop magic numbers
extern U64 bishop_magic_numbers[64];

// pawn attacks table [side][square]
extern U64 pawn_attacks[2][64];

// pawn attacks table [square]
extern U64 knight_attacks[64];

// pawn attacks table [square]
extern U64 king_attacks[64];

// bishop attack masks
extern U64 bishop_masks[64];

// rook attack masks
extern U64 rook_masks[64];

// bishop attacks table [square][occupancies]
extern U64 bishop_attacks[64][512];

// rook attacks rable [square][occupancies]
extern U64 rook_attacks[64][4096];

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