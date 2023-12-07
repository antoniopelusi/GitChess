/**********************************\
 ==================================
           
          GitChess engine     
       
                by
                
          Antonio Pelusi

 ==================================
\**********************************/
#include "io.h"
#include "magics.h"

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
    
    // init magic numbers
    init_magic_numbers();
}

// Main function
int main()
{
    // init all
    init_all();

    return 0;
}