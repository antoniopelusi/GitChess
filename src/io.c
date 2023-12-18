/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include <stdio.h>
#include "bitmanipulation.h"
#include "chessboard.h"

/**********************************\
 ==================================
 
          Input and Output
 
 ==================================
\**********************************/

// print bitboard
void print_bitboard(U64 bitboard)
{
      // print init board
      printf("\n   ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");

      // loop over board ranks
      for(int rank = 0; rank < 8; rank++)
      {
            // loop over board files
            for(int file = 0; file < 8; file++)
            {
                  // convert file and rank into square index
                  int square = rank * 8 + file;

                  // print board ranks
                  if(!file)
                  {
                        printf(" %d ┃", (8 - rank));
                  }

                  // print targets
                  printf(" %s ┃", get_bit(bitboard, square) ? "🞪" : " ");
            }

            // print new line every rank
            if(rank == 7)
            {
                  printf("\n   ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛");
            }
            else
            {
                  printf("\n   ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
            }
      }

      // print board files
      printf("\n     a   b   c   d   e   f   g   h\n");

      // print bitboard as unsigned decimal number
      printf("\n- decimal value: %llu\n", bitboard);

      // print bit count
      printf("\n- bit count: %d\n", count_bits(bitboard));
}

// print board
void print_board()
{
      // print init board
      printf("\n   ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");

      // loop over board ranks
      for(int rank = 0; rank < 8; rank++)
      {
            // loop over board files
            for(int file = 0; file < 8; file++)
            {
                  // convert file and rank into square index
                  int square = rank * 8 + file;

                  // print board ranks
                  if(!file)
                  {
                        printf(" %d ┃", (8 - rank));
                  }

                  // define piece variable
                  int piece = -1;

                  // loop over all piece bitboards
                  for(int bb_piece = P; bb_piece <= k; bb_piece++)
                  {
                        if(get_bit(bitboards[bb_piece], square))
                        {
                              piece = bb_piece;
                        }
                  }

                  // print different piece set depending on OS
                  #ifdef WIN64
                        printf(" %c ┃", (piece == -1) ? ' ' : ascii_pieces[piece]);
                  #else
                        printf(" %s ┃", (piece == -1) ? " " : unicode_pieces[piece]);
                  #endif
            }

            // print new line every rank
            if(rank == 7)
            {
                  printf("\n   ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛");
            }
            else
            {
                  printf("\n   ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
            }
      }

      // print board files
      printf("\n     a   b   c   d   e   f   g   h\n\n");
    
      // print side to move
      printf("     Side: %s\n\n", !side ? "white" : "black");
    
      // print enpassant square
      printf("     Enpassant: %s\n\n", (enpassant != no_sq) ? square_to_coordinates[enpassant] : "no");
    
      // print castling rights
      printf("     Castling: %c%c%c%c\n\n", (castle & wk) ? 'K' : '-',
                                             (castle & wq) ? 'Q' : '-',
                                             (castle & bk) ? 'k' : '-',
                                             (castle & bq) ? 'q' : '-');
}