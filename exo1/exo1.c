#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo1.h"

short parity(const short c)
{
   short p = 0;

   // Completer la fonction ici
   for (unsigned i = 0; i < sizeof(c) * 8; i++)
   {
      p ^= (c >> i) & 1;
   }

   return p;
}

short hamming_encoding(const char c)
{
   short code = 0;

   code |= (c & 0x01) << 2;
   code |= (c & 0x0E) << 3;
   code |= (c & 0xF0) << 4;

   //p0
   code |= parity(code & 0x1554) << 0;

   //p1
   code |= parity(code & 0x6664) << 1;

   //p2
   code |= parity(code & 0xf070) << 3;

   //p3
   code |= parity(code & 0xff00) << 7;

   return code;
}

char hamming_decoding(const short c)
{
   // Completer la fonction ici

   short ccc = c;
   short cc = 0;

   //c0
   cc |= parity(ccc & 0x5555);

   //c1
   cc |= parity(ccc & 0x6666) << 1;

   //c2
   cc |= parity(ccc & 0x7878) << 2;

   //c3
   cc |= parity(ccc & 0x7f80) << 3;

   if (cc) //une erreur
   {
      //position cc-1
      if (((cc - 1) >> ccc) & 1) //push un 1
         ccc |= 1 << (cc - 1);
      else                       //push un 0
         ccc ^= 1 << (cc - 1);
   }

   char code = 0;
   code |= (ccc & 0x0004) >> 2;
   code |= (ccc & 0x0070) >> 3;
   code |= (ccc & 0x0F00) >> 4;

   return code;
}
