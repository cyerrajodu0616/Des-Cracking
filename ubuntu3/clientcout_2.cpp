#include<math.h>
#include<stdio.h> //printf
#include<string>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include<unistd.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;
 int sock;
        class Key_Generation{

                public :
                        int round;
                        //unsigned char Sample_key[64]={'0','0','0','1','0','0','1','1','0','0','1','1','0','1','0','0','0','1','0','1','0','1','1','1','0','1','1','1','1','0','0','1','1','0','0','1','1','0','1','1','1','0','1','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','0','0','0','1'};
                        //char Text[64];
                        //char Text1[64];
                        char Cipher[64];
                        //char Cipher1[64];
                        char Sub_Key[17][48];
                        char Left_Key[28];
                        char Right_Key[28];
                        char Expansion_Key[48];
                        char Permutation_Choice_1[56];
                        char Permutation_Choice_2[48];
                        char initialPermutation[64];
                        char inversePermutation[64];
                        char Iterated_Key[58];
                        char inputString[64];// = {'0','0','0','0','0','0','0','1','0','0','1','0','0','0','1','1','0','1','0','0','0','1','0','1','0','1','1','0','0','1','1','1','1','0','0','0','1','0','0','1','1','0','1','0','1','0','1','1','1','1','0','0','1','1','0','1','1','1','1','0','1','1','1','1'};
                        char leftText[17][32];
                        char rightText[17][32];
                        char exprightText[17][48];
                        char permRight[32];
                        char ciphertext[64];
                        char inversepermutation[64];
         void Permutation_Choice1(int rounds, char *Sample_key,int *flag);
         void Shift_Bits(int round,char Left_Key[28],char Right_Key[28]);
         void inputTextProcessing();
         void expansion(int round,char rightText[17][32], char Sub_Key[17][48]);
         void permutateRightSubText(char permRight[32]);
         void readInitialDataFromFile(int flag);
        };


/*
        Permutation_Choice1 function will remove pairity bits and load them in pre-defined order
        into Permutation_Choice_1 array.

         After Permutation choice 1, 57th bit of key should be 1st bit of Permutation choice 1


         Left:  57 49 41 33 25 17  9 1 58 50 42 34 26 18 10  2 59 51 43 35 27 19 11  3 60 52 44 36

         Right: 63 55 47 39 31 23 15 7 62 54 46 38 30 22 14  6 61 53 45 37 29 21 13  5 28 20 12  4
         -------------------------------------------------------------------------------------------

         AS array index is started from 0 we can consider this as 1, so 57 bit will be at 56th position of key
        */

        void Key_Generation::Permutation_Choice1(int rounds, char *Sample_key,int *flag)
        {
                        // for checking whether program fouund key or not
                *flag =0;
                Permutation_Choice_1[0]=Sample_key[57-1];
                Permutation_Choice_1[1]=Sample_key[49-1];
                Permutation_Choice_1[2]=Sample_key[41-1];
                Permutation_Choice_1[3]=Sample_key[33-1];
                Permutation_Choice_1[4]=Sample_key[25-1];
                Permutation_Choice_1[5]=Sample_key[17-1];
                Permutation_Choice_1[6]=Sample_key[9-1];
                Permutation_Choice_1[7]=Sample_key[1-1];
                Permutation_Choice_1[8]=Sample_key[58-1];
                Permutation_Choice_1[9]=Sample_key[50-1];
                Permutation_Choice_1[10]=Sample_key[42-1];
                Permutation_Choice_1[11]=Sample_key[34-1];
                Permutation_Choice_1[12]=Sample_key[26-1];
                Permutation_Choice_1[13]=Sample_key[18-1];
                Permutation_Choice_1[14]=Sample_key[10-1];
                Permutation_Choice_1[15]=Sample_key[2-1];
                Permutation_Choice_1[16]=Sample_key[59-1];
                Permutation_Choice_1[17]=Sample_key[51-1];
                Permutation_Choice_1[18]=Sample_key[43-1];
                Permutation_Choice_1[19]=Sample_key[35-1];
                Permutation_Choice_1[20]=Sample_key[27-1];
                Permutation_Choice_1[21]=Sample_key[19-1];
                Permutation_Choice_1[22]=Sample_key[11-1];
                Permutation_Choice_1[23]=Sample_key[3-1];
                Permutation_Choice_1[24]=Sample_key[60-1];
                Permutation_Choice_1[25]=Sample_key[52-1];
                Permutation_Choice_1[26]=Sample_key[44-1];
                Permutation_Choice_1[27]=Sample_key[36-1];
                Permutation_Choice_1[28]=Sample_key[63-1];
                Permutation_Choice_1[29]=Sample_key[55-1];
                Permutation_Choice_1[30]=Sample_key[47-1];
                Permutation_Choice_1[31]=Sample_key[39-1];
                Permutation_Choice_1[32]=Sample_key[31-1];
                Permutation_Choice_1[33]=Sample_key[23-1];
                Permutation_Choice_1[34]=Sample_key[15-1];
                Permutation_Choice_1[35]=Sample_key[7-1];
                Permutation_Choice_1[36]=Sample_key[62-1];
                Permutation_Choice_1[37]=Sample_key[54-1];
                Permutation_Choice_1[38]=Sample_key[46-1];
                Permutation_Choice_1[39]=Sample_key[38-1];
                Permutation_Choice_1[40]=Sample_key[30-1];
                Permutation_Choice_1[41]=Sample_key[22-1];
                Permutation_Choice_1[42]=Sample_key[14-1];
                Permutation_Choice_1[43]=Sample_key[6-1];
                Permutation_Choice_1[44]=Sample_key[61-1];
                Permutation_Choice_1[45]=Sample_key[53-1];
                Permutation_Choice_1[46]=Sample_key[45-1];
                Permutation_Choice_1[47]=Sample_key[37-1];
                Permutation_Choice_1[48]=Sample_key[29-1];
                Permutation_Choice_1[49]=Sample_key[21-1];
                Permutation_Choice_1[50]=Sample_key[13-1];
                Permutation_Choice_1[51]=Sample_key[5-1];
                Permutation_Choice_1[52]=Sample_key[28-1];
                Permutation_Choice_1[53]=Sample_key[20-1];
                Permutation_Choice_1[54]=Sample_key[12-1];
                Permutation_Choice_1[55]=Sample_key[4-1];

                for(int i=0;i<28;i++)
                {
                        Left_Key[i]=Permutation_Choice_1[i];
                }

                for(int i=28;i<56;i++)
                {
                        Right_Key[i-28]=Permutation_Choice_1[i];
                }

                // processing input string to divide into two halfs
                inputTextProcessing();
                //ROUNDS
                for(int i=1;i<=rounds;i++)
                {
                        Shift_Bits(i,Left_Key,Right_Key);
                        // subkeys finding
                        for (int j=0;j<48;j++)
                        {

                            Sub_Key[i][j] =  Permutation_Choice_2[j];
                        }

                                                // Text processing
                        expansion(i,rightText,Sub_Key);

                        // xor with lefttext
                for (int p=0;p<32;p++)
                {
                        if (permRight[p] == leftText[i-1][p])
                        {
                           rightText[i][p]= '0';
                        }
                        else
                        {
                            rightText[i][p]= '1';
                        }
                }


                // Copying Right half to left one

                        for(int j=0;j<32;j++)
                        {
                            leftText[i][j]=rightText[i-1][j];

                        }
                }

                for (int i=0;i<32;i++)
                {
                        ciphertext[i]=rightText[16][i];
                }
                for (int i=0;i<32;i++)
                {
                        ciphertext[i+32]=leftText[16][i];
                }

                //Inverse permutation
                inversepermutation[0]=ciphertext[40-1];
                inversepermutation[1]=ciphertext[8-1];
                inversepermutation[2]=ciphertext[48-1];
                inversepermutation[3]=ciphertext[16-1];
                inversepermutation[4]=ciphertext[56-1];
                inversepermutation[5]=ciphertext[24-1];
                inversepermutation[6]=ciphertext[64-1];
                inversepermutation[7]=ciphertext[32-1];
                inversepermutation[8]=ciphertext[39-1];
                inversepermutation[9]=ciphertext[7-1];
                inversepermutation[10]=ciphertext[47-1];
                inversepermutation[11]=ciphertext[15-1];
                inversepermutation[12]=ciphertext[55-1];
                inversepermutation[13]=ciphertext[23-1];
                inversepermutation[14]=ciphertext[63-1];
                inversepermutation[15]=ciphertext[31-1];
                inversepermutation[16]=ciphertext[38-1];
                inversepermutation[17]=ciphertext[6-1];
                inversepermutation[18]=ciphertext[46-1];
                inversepermutation[19]=ciphertext[14-1];
                inversepermutation[20]=ciphertext[54-1];
                inversepermutation[21]=ciphertext[22-1];
                inversepermutation[22]=ciphertext[62-1];
                inversepermutation[23]=ciphertext[30-1];
                inversepermutation[24]=ciphertext[37-1];
                inversepermutation[25]=ciphertext[5-1];
                inversepermutation[26]=ciphertext[45-1];
                inversepermutation[27]=ciphertext[13-1];
                inversepermutation[28]=ciphertext[53-1];
                inversepermutation[29]=ciphertext[21-1];
                inversepermutation[30]=ciphertext[61-1];
                inversepermutation[31]=ciphertext[29-1];
                inversepermutation[32]=ciphertext[36-1];
                inversepermutation[33]=ciphertext[4-1];
                inversepermutation[34]=ciphertext[44-1];
                inversepermutation[35]=ciphertext[12-1];
                inversepermutation[36]=ciphertext[52-1];
                inversepermutation[37]=ciphertext[20-1];
                inversepermutation[38]=ciphertext[60-1];
                inversepermutation[39]=ciphertext[28-1];
                inversepermutation[40]=ciphertext[35-1];
                inversepermutation[41]=ciphertext[3-1];
                inversepermutation[42]=ciphertext[43-1];
                inversepermutation[43]=ciphertext[11-1];
                inversepermutation[44]=ciphertext[51-1];
                inversepermutation[45]=ciphertext[19-1];
                inversepermutation[46]=ciphertext[59-1];
                inversepermutation[47]=ciphertext[27-1];
                inversepermutation[48]=ciphertext[34-1];
                inversepermutation[49]=ciphertext[2-1];
                inversepermutation[50]=ciphertext[42-1];
                inversepermutation[51]=ciphertext[10-1];
                inversepermutation[52]=ciphertext[50-1];
                inversepermutation[53]=ciphertext[18-1];
                inversepermutation[54]=ciphertext[58-1];
                inversepermutation[55]=ciphertext[26-1];
                inversepermutation[56]=ciphertext[33-1];
                inversepermutation[57]=ciphertext[1-1];
                inversepermutation[58]=ciphertext[41-1];
                inversepermutation[59]=ciphertext[9-1];
                inversepermutation[60]=ciphertext[49-1];
                inversepermutation[61]=ciphertext[17-1];
                inversepermutation[62]=ciphertext[57-1];
                inversepermutation[63]=ciphertext[25-1];
                cout << "Program cipher" << endl;
                for(int i=0;i<64;i++)
                {
                  cout << inversepermutation[i];
                }

                cout<<endl<<"Cipher Text" << endl;
                for(int i=0;i<64;i++)
                {
                        cout<<Cipher[i];
                        if(inversepermutation[i] != Cipher[i])
                        {
                                *flag = -1;
                                break;
                        }
                }
         }

        void Key_Generation::inputTextProcessing(){
                initialPermutation[0]=inputString[57];
                initialPermutation[1]=inputString[49];
                initialPermutation[2]=inputString[41];
                initialPermutation[3]=inputString[33];
                initialPermutation[4]=inputString[25];
                initialPermutation[5]=inputString[17];
                initialPermutation[6]=inputString[9];
                initialPermutation[7]=inputString[1];
                initialPermutation[8]=inputString[59];
                initialPermutation[9]=inputString[51];
                initialPermutation[10]=inputString[43];
                initialPermutation[11]=inputString[35];
                initialPermutation[12]=inputString[27];
                initialPermutation[13]=inputString[19];
                initialPermutation[14]=inputString[11];
                initialPermutation[15]=inputString[3];
                initialPermutation[16]=inputString[61];
                initialPermutation[17]=inputString[53];
                initialPermutation[18]=inputString[45];
                initialPermutation[19]=inputString[37];
                initialPermutation[20]=inputString[29];
                initialPermutation[21]=inputString[21];
                initialPermutation[22]=inputString[13];
                initialPermutation[23]=inputString[5];
                initialPermutation[24]=inputString[63];
                initialPermutation[25]=inputString[55];
                initialPermutation[26]=inputString[47];
                initialPermutation[27]=inputString[39];
                initialPermutation[28]=inputString[31];
                initialPermutation[29]=inputString[23];
                initialPermutation[30]=inputString[15];
                initialPermutation[31]=inputString[7];
                initialPermutation[32]=inputString[56];
                initialPermutation[33]=inputString[48];
                initialPermutation[34]=inputString[40];
                initialPermutation[35]=inputString[32];
                initialPermutation[36]=inputString[24];
                initialPermutation[37]=inputString[16];
                initialPermutation[38]=inputString[8];
                initialPermutation[39]=inputString[0];
                initialPermutation[40]=inputString[58];
                initialPermutation[41]=inputString[50];
                initialPermutation[42]=inputString[42];
                initialPermutation[43]=inputString[34];
                initialPermutation[44]=inputString[26];
                initialPermutation[45]=inputString[18];
                initialPermutation[46]=inputString[10];
                initialPermutation[47]=inputString[2];
                initialPermutation[48]=inputString[60];
                initialPermutation[49]=inputString[52];
                initialPermutation[50]=inputString[44];
                initialPermutation[51]=inputString[36];
                initialPermutation[52]=inputString[28];
                initialPermutation[53]=inputString[20];
                initialPermutation[54]=inputString[12];
                initialPermutation[55]=inputString[4];
                initialPermutation[56]=inputString[62];
                initialPermutation[57]=inputString[54];
                initialPermutation[58]=inputString[46];
                initialPermutation[59]=inputString[38];
                initialPermutation[60]=inputString[30];
                initialPermutation[61]=inputString[22];
                initialPermutation[62]=inputString[14];
                initialPermutation[63]=inputString[6];

                //Divide Left and right array
                for(int i=0; i<32; i++){
                        leftText[0][i] = initialPermutation[i];
                }

                for(int i=32; i<64; i++){
                        rightText[0][i-32] = initialPermutation[i];
                }
        }


        void Key_Generation::expansion(int round,char rightText[17][32],char Sub_Key[17][48])
        {
            int sBox1[4][16]=
            {
                {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
            };

            int sBox2[4][16]=
            {
                15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
                3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
                0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
                13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
            };

            int sBox3[4][16]=
            {
                10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
                13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
                13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
                1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
            };

            int sBox4[4][16]=
            {
                7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
                13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
                10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
                3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
            };

            int sBox5[4][16]=
            {
                2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
                14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
                4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
                11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
            };

            int sBox6[4][16]=
            {
                12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
                10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
                9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
                4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
            };

            int sBox7[4][16]=
            {
                4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
                13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
                1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
                6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
            };

            int sBox8[4][16]=
            {
                13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
                1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
                7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
                2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
            };

                exprightText[round][0] = rightText[round-1][32-1];
                exprightText[round][1] = rightText[round-1][1-1];
                exprightText[round][2] = rightText[round-1][2-1];
                exprightText[round][3] = rightText[round-1][3-1];
                exprightText[round][4] = rightText[round-1][4-1];
                exprightText[round][5] = rightText[round-1][5-1];
                exprightText[round][6] = rightText[round-1][4-1];
                exprightText[round][7] = rightText[round-1][5-1];
                exprightText[round][8] = rightText[round-1][6-1];
                exprightText[round][9] = rightText[round-1][7-1];
                exprightText[round][10] = rightText[round-1][8-1];
                exprightText[round][11] = rightText[round-1][9-1];
                exprightText[round][12] = rightText[round-1][8-1];
                exprightText[round][13] = rightText[round-1][9-1];
                exprightText[round][14] = rightText[round-1][10-1];
                exprightText[round][15] = rightText[round-1][11-1];
                exprightText[round][16] = rightText[round-1][12-1];
                exprightText[round][17] = rightText[round-1][13-1];
                exprightText[round][18] = rightText[round-1][12-1];
                exprightText[round][19] = rightText[round-1][13-1];
                exprightText[round][20] = rightText[round-1][14-1];
                exprightText[round][21] = rightText[round-1][15-1];
                exprightText[round][22] = rightText[round-1][16-1];
                exprightText[round][23] = rightText[round-1][17-1];
                exprightText[round][24] = rightText[round-1][16-1];
                exprightText[round][25] = rightText[round-1][17-1];
                exprightText[round][26] = rightText[round-1][18-1];
                exprightText[round][27] = rightText[round-1][19-1];
                exprightText[round][28] = rightText[round-1][20-1];
                exprightText[round][29] = rightText[round-1][21-1];
                exprightText[round][30] = rightText[round-1][20-1];
                exprightText[round][31] = rightText[round-1][21-1];
                exprightText[round][32] = rightText[round-1][22-1];
                exprightText[round][33] = rightText[round-1][23-1];
                exprightText[round][34] = rightText[round-1][24-1];
                exprightText[round][35] = rightText[round-1][25-1];
                exprightText[round][36] = rightText[round-1][24-1];
                exprightText[round][37] = rightText[round-1][25-1];
                exprightText[round][38] = rightText[round-1][26-1];
                exprightText[round][39] = rightText[round-1][27-1];
                exprightText[round][40] = rightText[round-1][28-1];
                exprightText[round][41] = rightText[round-1][29-1];
                exprightText[round][42] = rightText[round-1][28-1];
                exprightText[round][43] = rightText[round-1][29-1];
                exprightText[round][44] = rightText[round-1][30-1];
                exprightText[round][45] = rightText[round-1][31-1];
                exprightText[round][46] = rightText[round-1][32-1];
                exprightText[round][47] = rightText[round-1][1-1];

                // xor with key
                for (int i=0;i<48;i++)
                {
                        if (exprightText[round][i] == Sub_Key[round][i])
                        {
                           exprightText[round][i]= '0';
                        }
                        else
                        {
                            exprightText[round][i]= '1';
                        }
                }

                int p = 0;
                //int q = 0;
                int bit4 = sBox1[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c1(bit4);
                string str1 = c1.to_string();

                p=p+6;
                bit4 = sBox2[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c2(bit4);
                str1 = str1.append(c2.to_string());

                p=p+6;
                bit4 = sBox3[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c3(bit4);
                str1 = str1.append(c3.to_string());

                p=p+6;
                bit4 = sBox4[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c4(bit4);
                str1 = str1.append(c4.to_string());

                p=p+6;
                bit4 = sBox5[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c5(bit4);
                str1 = str1.append(c5.to_string());

                p=p+6;
                bit4 = sBox6[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c6(bit4);
                str1 = str1.append(c6.to_string());

                p=p+6;
                bit4 = sBox7[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c7(bit4);
                str1 = str1.append(c7.to_string());

                p=p+6;
                bit4 = sBox8[((exprightText[round][p]-'0')*2) + (exprightText[round][p+5]-'0')] [(((exprightText[round][p+1])-'0')*8) + (((exprightText[round][p+2])-'0')*4)+(((exprightText[round][p+3])-'0')*2) + ((exprightText[round][p+4])-'0')];
                bitset<4> c8(bit4);
                str1 = str1.append(c8.to_string());

                char tmpRight[32];
                for(int k=0;k<32;k++){
                        tmpRight[k] = (char)str1[k];
                }

                permutateRightSubText(tmpRight);
        }

void Key_Generation::permutateRightSubText( char tempRight[32]){

                permRight[0]=tempRight[16-1];
                permRight[1]=tempRight[7-1];
                permRight[2]=tempRight[20-1];
                permRight[3]=tempRight[21-1];
                permRight[4]=tempRight[29-1];
                permRight[5]=tempRight[12-1];
                permRight[6]=tempRight[28-1];
                permRight[7]=tempRight[17-1];
                permRight[8]=tempRight[1-1];
                permRight[9]=tempRight[15-1];
                permRight[10]=tempRight[23-1];
                permRight[11]=tempRight[26-1];
                permRight[12]=tempRight[5-1];
                permRight[13]=tempRight[18-1];
                permRight[14]=tempRight[31-1];
                permRight[15]=tempRight[10-1];
                permRight[16]=tempRight[2-1];
                permRight[17]=tempRight[8-1];
                permRight[18]=tempRight[24-1];
                permRight[19]=tempRight[14-1];
                permRight[20]=tempRight[32-1];
                permRight[21]=tempRight[27-1];
                permRight[22]=tempRight[3-1];
                permRight[23]=tempRight[9-1];
                permRight[24]=tempRight[19-1];
                permRight[25]=tempRight[13-1];
                permRight[26]=tempRight[30-1];
                permRight[27]=tempRight[6-1];
                permRight[28]=tempRight[22-1];
                permRight[29]=tempRight[11-1];
                permRight[30]=tempRight[4-1];
                permRight[31]=tempRight[25-1];
        }

        void Key_Generation::Shift_Bits(int Round,char Left_Key[28],char Right_Key[28])
        {
                if (Round!=1 && Round!=2 && Round!=9 && Round!=16)
                {
                        char temp1[2];
                        temp1[0]=Left_Key[0];
                        temp1[1]=Left_Key[1];
                        for ( int i=0;i<28;i++)
                        {
                            Left_Key[i] = Left_Key[i+2];
                        }
                        Left_Key[26]=temp1[0];
                        Left_Key[27]=temp1[1];

                        temp1[0] = Right_Key[0];
                        temp1[1] = Right_Key[1];
                        for ( int i=0;i<28;i++)
                        {
                            Right_Key[i] = Right_Key[i+2];
                        }
                        Right_Key[26]=temp1[0];
                        Right_Key[27]=temp1[1];
                }
                else
                {
                        char temp1[1];
                        temp1[0] = Left_Key[0];
                        for ( int i=0;i<28;i++)
                        {
                            Left_Key[i] = Left_Key[i+1];
                        }
                        Left_Key[27]=temp1[0];

                        temp1[0] = Right_Key[0];
                        for ( int i=0;i<28;i++)
                        {
                            Right_Key[i] = Right_Key[i+1];
                        }
                        Right_Key[27]=temp1[0];
                }

                for (int i=0;i<28;i++)
                {
                        Iterated_Key[i]=Left_Key[i];
                }
                for (int j=28;j<56;j++)
                {
                        Iterated_Key[j]=Right_Key[j-28];
                }

                Permutation_Choice_2[0] = Iterated_Key[14-1];
                Permutation_Choice_2[1] = Iterated_Key[17-1];
                Permutation_Choice_2[2] = Iterated_Key[11-1];
                Permutation_Choice_2[3] = Iterated_Key[24-1];
                Permutation_Choice_2[4] = Iterated_Key[1-1];
                Permutation_Choice_2[5] = Iterated_Key[5-1];
                Permutation_Choice_2[6] = Iterated_Key[3-1];
                Permutation_Choice_2[7] = Iterated_Key[28-1];
                Permutation_Choice_2[8] = Iterated_Key[15-1];
                Permutation_Choice_2[9] = Iterated_Key[6-1];
                Permutation_Choice_2[10] = Iterated_Key[21-1];
                Permutation_Choice_2[11] = Iterated_Key[10-1];
                Permutation_Choice_2[12] = Iterated_Key[23-1];
                Permutation_Choice_2[13] = Iterated_Key[19-1];
                Permutation_Choice_2[14] = Iterated_Key[12-1];
                Permutation_Choice_2[15] = Iterated_Key[4-1];
                Permutation_Choice_2[16] = Iterated_Key[26-1];
                Permutation_Choice_2[17] = Iterated_Key[8-1];
                Permutation_Choice_2[18] = Iterated_Key[16-1];
                Permutation_Choice_2[19] = Iterated_Key[7-1];
                Permutation_Choice_2[20] = Iterated_Key[27-1];
                Permutation_Choice_2[21] = Iterated_Key[20-1];
                Permutation_Choice_2[22] = Iterated_Key[13-1];
                Permutation_Choice_2[23] = Iterated_Key[2-1];
                Permutation_Choice_2[24] = Iterated_Key[41-1];
                Permutation_Choice_2[25] = Iterated_Key[52-1];
                Permutation_Choice_2[26] = Iterated_Key[31-1];
                Permutation_Choice_2[27] = Iterated_Key[37-1];
                Permutation_Choice_2[28] = Iterated_Key[47-1];
                Permutation_Choice_2[29] = Iterated_Key[55-1];
                Permutation_Choice_2[30] = Iterated_Key[30-1];
                Permutation_Choice_2[31] = Iterated_Key[40-1];
                Permutation_Choice_2[32] = Iterated_Key[51-1];
                Permutation_Choice_2[33] = Iterated_Key[45-1];
                Permutation_Choice_2[34] = Iterated_Key[33-1];
                Permutation_Choice_2[35] = Iterated_Key[48-1];
                Permutation_Choice_2[36] = Iterated_Key[44-1];
                Permutation_Choice_2[37] = Iterated_Key[49-1];
                Permutation_Choice_2[38] = Iterated_Key[39-1];
                Permutation_Choice_2[39] = Iterated_Key[56-1];
                Permutation_Choice_2[40] = Iterated_Key[34-1];
                Permutation_Choice_2[41] = Iterated_Key[53-1];
                Permutation_Choice_2[42] = Iterated_Key[46-1];
                Permutation_Choice_2[43] = Iterated_Key[42-1];
                Permutation_Choice_2[44] = Iterated_Key[50-1];
                Permutation_Choice_2[45] = Iterated_Key[36-1];
                Permutation_Choice_2[46] = Iterated_Key[29-1];
                Permutation_Choice_2[47] = Iterated_Key[32-1];
        }



void Key_Generation::readInitialDataFromFile(int flag1){
   FILE * CipherFile;
   FILE * PlainText;
  // FILE * CipherFile1;
   //FILE * PlainText1;


   char buffer [64];
   if(flag1==1){
           CipherFile = fopen ("//home//ubuntu//ciphertext1.txt" , "r");
           if (CipherFile == NULL) perror ("Error opening file");
           else
           {
                 while ( ! feof (CipherFile) )
                 {
                   if ( fgets (buffer , 100 , CipherFile) == NULL ) break;
                 }
                        printf("Cipher From File");
                 for(int i=0;i<64;i++)
                 {
                        Cipher[i]=(char)buffer[i];
                        printf("%c",Cipher[i]);
                 }
                // Cipher[64]='\0';
                 fclose (CipherFile);
           }

           PlainText = fopen ("//home//ubuntu//plaintext1.txt" , "r");
           if (PlainText == NULL) perror ("Error opening file");
           else
           {
                 while ( ! feof (PlainText) )
                 {
                   if ( fgets (buffer , 100 , PlainText) == NULL ) break;
                 }
                printf("Text From File");
                 for(int i=0;i<64;i++)
                 {
                        inputString[i]=(char)buffer[i];
                        printf(" %c ",inputString[i]);
                 }
                // inputString[64]='\0';
                 fclose (PlainText);
           }
   }else{
           CipherFile = fopen ("//home//ubuntu//ciphertext2.txt" , "r");
           if (CipherFile == NULL) perror ("Error opening file");
           else
           {
                 while ( ! feof (CipherFile) )
                 {
                   if ( fgets (buffer , 100 , CipherFile) == NULL ) break;
                 }
                 for(int i=0;i<64;i++)
                   {
                        Cipher[i]=(char)buffer[i];
                   }
                 Cipher[64]='\0';
                 fclose (CipherFile);
           }
           PlainText = fopen ("//home//ubuntu//plaintext2.txt" , "r");
           if (PlainText == NULL) printf ("Error opening file");
           else
           {
                 while ( ! feof (PlainText) )
                 {
                   if ( fgets (buffer , 100 , PlainText) == NULL ) break;
                 }
                 for(int i=0;i<64;i++)
                 {
                        inputString[i]=(char)buffer[i];
                 }
                 inputString[64]='\0';
                 fclose (PlainText);
           }
   }
}

void *clientReturn(void *arg){
        char  server_reply[20];
	int msg_length;
        if( msg_length = read(sock , server_reply , 20) < 0)
        {
            //br90eak;
            exit(0);
        }
	puts(server_reply);
	puts("\n server reply in clietn return");
        if(strcmp(server_reply,"close")==0){
		puts("ending thread\n");
		cout<<pthread_self();
                exit(0);
        }
	puts("end of client return");
}

void *desFunction(void *arg){
    Key_Generation KG;
    string str1;
    unsigned long long int bit4 = 0;
    int keyFound = -1;
    int flag=0;
    int msg_length=0;
    int rounds = *(int*)arg;
    cout << "rounds" << rounds <<endl;
    KG.readInitialDataFromFile(1);
    char sampleKey[64];

    for(bit4=pow(2,51)*31; bit4<pow(2,56); bit4++){

        bitset<64> key(bit4);
        str1 = key.to_string();
        for(int k=0;k<64;k++)
        {
                sampleKey[k] = (char)str1[k];
        }
        KG.Permutation_Choice1(rounds,sampleKey,&flag);
       cout << "flag" << flag << endl;
        if(flag == 0)
        {
                flag=1;
              KG.readInitialDataFromFile(0);
               KG.Permutation_Choice1(rounds,sampleKey,&flag);
                if(flag == 0)
                {
                	cout<<"Found: %ul:"<<bit4<<"\n";
                	keyFound = bit4;
			write(sock,sampleKey,65);
			exit(0);
                	break;
                }
                else
                {
                 	memset(sampleKey,' ',64);
			write(sock,sampleKey,65);
			exit(0);
                	cout << "not a key %d: " << bit4;
                }
        }
        else
        {        //memset(sampleKey,' ',64);
		 //write(sock,sampleKey,65);
                 //       exit(0);
                cout << "not a key %d: " << bit4;
        }
    }
}

int main(int argc, char *argv[])
{
    //int sock;
    int rounds = atoi(argv[1]);
    struct sockaddr_in server;
    //char message[1000] , server_reply[2000];
    pthread_t cr,des;
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(3333);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        return 0;
    }
    pthread_create(&des,NULL,desFunction,&rounds);
    pthread_create(&cr,NULL,clientReturn,NULL);
    pthread_exit(NULL);
    return 0;
}

