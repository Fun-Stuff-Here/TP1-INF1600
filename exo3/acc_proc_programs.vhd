use work.acc_proc_def.all;

package acc_proc_programs is

   -- Le contenu de la memoire est uint16, 
   -- ce qui explique l'utilisation de fonctions
   -- de converssion
   constant program_0 : memtype := (
      to_uint16((ld,   7)),   --  0 
      to_uint16((br,   3)),   --  1
      to_uint16((ld,   8)),   --  2
      to_uint16((brz,  5)),   --  3
      to_uint16((add,  9)),   --  4
      to_uint16((brnz, 1)),   --  5
      to_uint16((stop, 0)),   --  6
      +2,                     --  7
      +1,                     --  8
      int16_to_uint16(-1),    --  9
      others => 0
   );

   -- Programme utilise pour Q2
   constant program_1 : memtype := (
      -- ajouter votre programme ici, une ligne par instruction
      to_uint16((lda,  13)),      --0 Ma, pointeur vers data
      --debut boucle
      to_uint16((ldi,   0)),      --1 Load S(Ma) 1
      to_uint16((adda, 15)),      --2 increment Ma (Ma 16)
      to_uint16((addx,  0)),      --3 add S(Ma) 3
      to_uint16((add,  15)),      --4 add 4
      to_uint16((adda, 15)),      --5 increment (Ma 17) 
      to_uint16((sti,   0)),      --6 store 4 at S(Ma)  
      to_uint16((suba, 15)),      --7 decremente Ma (Ma 16)
      --Condition
      to_uint16((ld,   14)),      --8 load nIteration 
      to_uint16((sub,  15)),      --9 decremnente nIteration
      to_uint16((st,   14)),      --10 store nIteration
      to_uint16((brnz,  1)),      --11 while(!nIteration)
      --Fin
      to_uint16((stop,  0)),      --12 FIN 
      +15,                        --13 Pointeur vers S(0)
      +4,                         --14 nIteration
      +1,                         --15 S(0) 
      +2,                         --16 S(1)
      others => 0
   );
   
end acc_proc_programs;

package body acc_proc_programs is  
end acc_proc_programs;