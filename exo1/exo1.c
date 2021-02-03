#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo1.h"

short parity(const short c){
   short p = 0;  
   
   // Completer la fonction ici
   
   
   return p;
}

short hamming_encoding(const char c){
   short code = 0;
   
   // Completer la fonction ici
   
   
   return code;
}

char hamming_decoding(const short c){   
   // Completer la fonction ici
   
   
   short cc = c;
         
   char code = 0;
   code |= (cc & 0x0004) >> 2;
   code |= (cc & 0x0070) >> 3;
   code |= (cc & 0x0F00) >> 4;
   
   return code;
}

