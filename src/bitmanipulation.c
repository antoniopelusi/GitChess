/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include "bitmanipulation.h"

/**********************************\
 ==================================
 
          Bit manipulation
 
 ==================================
\**********************************/

// print the bitboard
void print_bitboard(U64 bitboard)
{
      // print new line
      printf("\n");

      // loop over board ranks
      for(int rank = 0; rank < 8; rank++)
      {
            // loop over board files
            for(int file = 0; file < 8; file++)
            {
                  // convert file and rank into square index
                  int square = rank * 8 + file;

                  // print board files
                  if(!file)
                  {

                        printf(" %d  ", (8 - rank));
                  }

                  // print bit state [0, 1]
                  printf(" %d", get_bit(bitboard, square) ? 1 : 0);
            }

            // print new line every rank
            printf("\n");
      }

      // print board files
      printf("\n     a b c d e f g h\n");

      // print bitboard as unsigned decimal number
      printf("\n     Bitboard: %llud\n\n", bitboard);
}