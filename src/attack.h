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

// generate pawn attacks
U64 mask_pawn_attacks(int side, int square);

// generate knight attacks
U64 mask_knight_attacks(int square);

// generate king attacks
U64 mask_king_attacks(int square);

// init leaper pieces attack
void init_leapers_attacks();

#endif