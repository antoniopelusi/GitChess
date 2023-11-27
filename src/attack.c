/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include "attack.h"

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
const U64 not_a_file = 18374403900871474942ULL;

// not H file constant
const U64 not_h_file = 9187201950435737471ULL;

// not HG file constant
const U64 not_hg_file = 4557430888798830399ULL;

// not AB file constant
const U64 not_ab_file = 18229723555195321596ULL;

// pawn attacks table [side][square]
U64 pawn_attacks[2][64];

// pawn attacks table [square]
U64 knight_attacks[64];

// pawn attacks table [square]
U64 king_attacks[64];

// generate pawn attacks
U64 mask_pawn_attacks(int side, int square)
{
	// result attacks bitboard
	U64 attacks = 0ULL;

	// piece bitboard
	U64 bitboard = 0ULL;

	// set piece on board
	set_bit(bitboard, square);

	// white pawns
	if (!side)
	{
		// generate pawn attacks
		if((bitboard >> 7) & not_a_file) attacks |= (bitboard >> 7);
		if((bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
	}

	// black pawns
	else
	{
		// generate pawn attacks
		if((bitboard << 7) & not_h_file) attacks |= (bitboard << 7);
		if((bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
	}

	return attacks;
}

// generate knight attacks
U64 mask_knight_attacks(int square)
{
	// result attacks bitboard
	U64 attacks = 0ULL;

	// piece bitboard
	U64 bitboard = 0ULL;

	// set piece on board
	set_bit(bitboard, square);

	// generate knight attacks
	if ((bitboard >> 17) & not_h_file) attacks |= (bitboard >> 17);
    if ((bitboard >> 15) & not_a_file) attacks |= (bitboard >> 15);
    if ((bitboard >> 10) & not_hg_file) attacks |= (bitboard >> 10);
    if ((bitboard >> 6) & not_ab_file) attacks |= (bitboard >> 6);
    if ((bitboard << 17) & not_a_file) attacks |= (bitboard << 17);
    if ((bitboard << 15) & not_h_file) attacks |= (bitboard << 15);
    if ((bitboard << 10) & not_ab_file) attacks |= (bitboard << 10);
    if ((bitboard << 6) & not_hg_file) attacks |= (bitboard << 6);

	return attacks;
}

// generate king attacks
U64 mask_king_attacks(int square)
{
	// result attacks bitboard
	U64 attacks = 0ULL;

	// piece bitboard
	U64 bitboard = 0ULL;

	// set piece on board
	set_bit(bitboard, square);

	// generate king attacks
	if (bitboard >> 8) attacks |= (bitboard >> 8);
    if ((bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
    if ((bitboard >> 7) & not_a_file) attacks |= (bitboard >> 7);
    if ((bitboard >> 1) & not_h_file) attacks |= (bitboard >> 1);
    if (bitboard << 8) attacks |= (bitboard << 8);
    if ((bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    if ((bitboard << 7) & not_h_file) attacks |= (bitboard << 7);
    if ((bitboard << 1) & not_a_file) attacks |= (bitboard << 1);
    

	return attacks;
}

// init leaper pieces attack
void init_leapers_attacks()
{
	for(int square = 0; square < 64; square++)
	{
		// init pawn attacks
		pawn_attacks[white][square] = mask_pawn_attacks(white, square);
		pawn_attacks[black][square] = mask_pawn_attacks(black, square);

		// init knight attacks
		knight_attacks[square] = mask_knight_attacks(square);

		// init king attacks
        king_attacks[square] = mask_king_attacks(square);
	}
}