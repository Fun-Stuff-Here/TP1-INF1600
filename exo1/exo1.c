#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo1.h"

short parity(const short c)
{
   short p = 0;
   

   // Completer la fonction ici
   for (unsigned i = 0; i < sizeof(c)*8; i++)
   {
      p ^= (c>>i) & 1;
   }

   return p;
}

short hamming_encoding(const char c)
{
   short code = 0;

   // Completer la fonction ici
    for (unsigned i = 0,j=2; i <8; i++,j++)
    {
        if (j == 3 || j == 7)
            j++;
        if((c >> i) & 1)
            code |= 1<<j;
    }

    //p0
    code |=
        parity((code & (1<<2)) |
            (code & (1<<4)) |
            (code & (1<<6)) |
            (code & (1<<8)) |
            (code & (1<<10)) |
            (code & (1<<12)) |
            (code & (1<<14)));

    //p1
    code |=
        parity((code & (1<<2)) |
            (code & (1<<5)) |
            (code & (1<<6)) |
            (code & (1<<9)) |
            (code & (1<<10)) |
            (code & (1<<13)) |
            (code & (1<<14)))
        << 1;
    //p2
     code |=
        parity((code & (1<<4)) |
            (code & (1<<5)) |
            (code & (1<<6)) |
            (code & (1<<11)) |
            (code & (1<<12)) |
            (code & (1<<13)) |
            (code & (1<<14)))
        << 3;
    //p3
     code |=
        parity((code & (1<<8)) |
            (code & (1<<9)) |
            (code & (1<<10)) |
            (code & (1<<11)) |
            (code & (1<<12)) |
            (code & (1<<13)) |
            (code & (1<<14)))
        << 7;

   return code;
}

char hamming_decoding(const short ccc)
{
   // Completer la fonction ici

   short c = ccc;
   short cc = 0;

   //c0
   cc |=
        parity((c & (1)) |
            (c & (1<<2)) |
            (c & (1<<4)) |
            (c & (1<<6)) |
            (c & (1<<8)) |
            (c & (1<<10)) |
            (c & (1<<12))|
            (c & (1<<14)) 
            );

   //c1
   cc |=
        parity((c & (1<<1)) |
            (c & (1<<2)) |
            (c & (1<<5)) |
            (c & (1<<6)) |
            (c & (1<<9)) |
            (c & (1<<10)) |
            (c & (1<<13)) |
            (c & (1<<14)))
            <<1;
   
   //c2
   cc |=
        parity((c & (1<<3)) |
            (c & (1<<4)) |
            (c & (1<<5)) |
            (c & (1<<6)) |
            (c & (1<<11)) |
            (c & (1<<12)) |
            (c & (1<<13)) |
            (c & (1<<14)))
            <<2;

   //c3
   cc |=
        parity((c & (1<<7)) |
            (c & (1<<8)) |
            (c & (1<<9)) |
            (c & (1<<10)) |
            (c & (1<<11)) |
            (c & (1<<12)) |
            (c & (1<<13)) |
            (c & (1<<14)))
            <<3;

   if(cc)
   {
      if(((cc-1)>>c)&1)
         c |= 1<<(cc-1);
      else
         c ^= 1<<(cc-1);
   }

   char code = 0;
   code |= (c & 0x0004) >> 2;
   code |= (c & 0x0070) >> 3;
   code |= (c & 0x0F00) >> 4;

   return code;
}
