/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include "utils.h"

/**********************************\
 ==================================
 
            Chess board
 
 ==================================
\**********************************/

// piece bitboards
U64 bitboards[12];

// occupancy bitboards
U64 occupancies[3];

// side to move
int side = -1;

// enpassant square
int enpassant = no_sq;

// castling rights
int castle = 0;

