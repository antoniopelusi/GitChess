/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/

#include "attack.h"
#include "magics.h"

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

    U64 occupancy = 0ULL;    
    print_bitboard(get_bishop_attacks(d4, occupancy));

    return 0;
}