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

// count bits within a bitboard
static inline int count_bits(U64 bitboard)
{
      // bit counter
      int count = 0;

      // consecutively reset least significant 1st bit
      while(bitboard)
      {
            // increment bit counter
            count++;

            // reset least significant 1st bit
            bitboard &= bitboard - 1;
      }

      // return bit count
      return count;
}

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

                  // print board ranks
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
      printf("\n     Bitboard decimal value: %llu\n", bitboard);
      printf("\n     Bitboard bit count: %d\n\n", count_bits(bitboard));

}