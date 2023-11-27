/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include "attack.h"
#include "bitmanipulation.h"

/**********************************\
 ==================================
 
              Attacks
 
 ==================================
\**********************************/

// pawn attacks table [side][square]
U64 pawn_attacks[2][64];

U64 mask_pawn_attacks(int square, int side)
{
	// result attacks bitboard
	U64 attacks = 0ULL;

	// piece bitboard
	U64 bitboard = 0ULL;

	// set piece on board
	set_bit(bitboard, square);

	// print the board
	print_bitboard(bitboard);

	// white pawns
	if (!side)
	{

	}

	// black pawns
	else
	{

	}

	return attacks;
}