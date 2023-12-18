/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include "attack.h"
#include "magics.h"
#include "chessboard.h"
#include <stdio.h>
#include "io.h"
#include "bitmanipulation.h"

/**********************************\
 ==================================
 
             Main driver
 
 ==================================
\**********************************/

// init all variables
void init_all()
{
    // init leaper pieces attacks
    init_leapers_attacks();

    // init slider pieces attacks
    init_sliders_attacks(bishop);
    init_sliders_attacks(rook);
    
    // init magic numbers pre-calculated and saved in magics.c
    /* init_magic_numbers(); */
}

// Main function
int main()
{
    // init all
    init_all();

    // set white pawns
    set_bit(bitboards[P], a2);
    set_bit(bitboards[P], b2);
    set_bit(bitboards[P], c2);
    set_bit(bitboards[P], d2);
    set_bit(bitboards[P], e2);
    set_bit(bitboards[P], f2);
    set_bit(bitboards[P], g2);
    set_bit(bitboards[P], h2);
    
    // set white knights
    set_bit(bitboards[N], b1);
    set_bit(bitboards[N], g1);
    
    // set white bishops
    set_bit(bitboards[B], c1);
    set_bit(bitboards[B], f1);
    
    // set white rooks
    set_bit(bitboards[R], a1);
    set_bit(bitboards[R], h1);
    
    // set white queen & king
    set_bit(bitboards[Q], d1);
    set_bit(bitboards[K], e1);
    
    // set white pawns
    set_bit(bitboards[p], a7);
    set_bit(bitboards[p], b7);
    set_bit(bitboards[p], c7);
    set_bit(bitboards[p], d7);
    set_bit(bitboards[p], e7);
    set_bit(bitboards[p], f7);
    set_bit(bitboards[p], g7);
    set_bit(bitboards[p], h7);
    
    // set white knights
    set_bit(bitboards[n], b8);
    set_bit(bitboards[n], g8);
    
    // set white bishops
    set_bit(bitboards[b], c8);
    set_bit(bitboards[b], f8);
    
    // set white rooks
    set_bit(bitboards[r], a8);
    set_bit(bitboards[r], h8);
    
    // set white queen & king
    set_bit(bitboards[q], d8);
    set_bit(bitboards[k], e8);

    // init side
    side = black;
    
    // init enpassant
    enpassant = e3;
    
    // init castling
    castle |= wk;
    castle |= wq;
    castle |= bk;
    castle |= bq;
    
    // print board
    print_board();

    return 0;
}