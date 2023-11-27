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

U64 mask_pawn_attacks(int side, int square);

void init_leapers_attacks();

#endif