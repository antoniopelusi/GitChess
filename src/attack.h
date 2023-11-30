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

// mask queen attacks
U64 mask_queen_attacks(int square);

// init leaper pieces attack
void init_leapers_attacks();

#endif