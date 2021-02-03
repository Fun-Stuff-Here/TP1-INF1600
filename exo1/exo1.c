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
   //map le char
   for(unsigned i =0,j=2; i<8;i++,j++)
   {
      if(i==3 || i==4)
         j++;
      
      code |= (c>>i)&(0x0001<<j);
   }

   //p0
   short p0 =0;
   for(unsigned i =2; i<=14; i+=2)
   {
      p0 |= (c>>i)& 0x0001;
   }
   code |= parity(p0);


   //p1
   short p1 = 0;
      for(unsigned i =2; i<=14;)
   {
      if(i&0x0001)
         i++;
      else
           i+=3;
      
      

      p1 |= (c>>i)& 0x0001;
   }
   code |= (parity(p1)<<1);

      //p2
   short p2 = 0;
      for(unsigned i =3; i<=14; i++)
   {
      if(i==7)
         i+=4;

      p2 |= (c>>i)& 0x0001;
   }
   code |= (parity(p2)<<3);

   //p3
   short p3 = 0;
      for(unsigned i =7; i<=14; i++)
   {

      p3 |= (c>>i)& 0x0001;
   }
   code |= (parity(p3)<<7);

   return code;
}

char hamming_decoding(const short c)
{
   // Completer la fonction ici

   short cc = c;

   char code = 0;
   code |= (cc & 0x0004) >> 2;
   code |= (cc & 0x0070) >> 3;
   code |= (cc & 0x0F00) >> 4;

   return code;
}
