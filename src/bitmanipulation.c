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
int count_bits(U64 bitboard)
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

// get least significant 1st bit (ls1b) index
int get_ls1b_index(U64 bitboard)
{
      // if not empty
      if(bitboard)
      {
            // count trailing bits before ls1b
            return count_bits((bitboard & -bitboard) - 1); 
      }

      // if empty
      else
      {
            return -1;
      }
}