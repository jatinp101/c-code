/**
 * C/C++ implementation of SHA-1
 * @author Jatin Pandya
 * @since 3/30/2019
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1048576
// Function prototypes
unsigned int onesComplement(unsigned int); // may not need
unsigned int circleLeft (unsigned int, unsigned int);
unsigned int charPacker (unsigned char, unsigned char, unsigned char, unsigned char);
unsigned int calculateBlocks(unsigned int);
void convertCharArrayToIntArray(unsigned char, unsigned int, unsigned int);
void addBitCountToLastBlock(unsigned int, unsigned int, unsigned int);
void computeMessageDigest(unsigned int, unsigned int);
unsigned int f(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int K(unsigned int);

int main (int argc, char *argv[]) {
    //open file
    unsigned char bufferChar = 'a';
    unsigned char buffer [MAX];
    unsigned int h [5] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    unsigned int h0 = 0x67452301; 
    unsigned int h1 = 0xEFCDAB89;
    unsigned int h2 = 0x98BADCFE;
    unsigned int h3 = 0x10325476;
    unsigned int h4 = 0xC3D2E1F0;
    unsigned int k [4] = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6};
    FILE *filePointer = NULL;
    unsigned int blockCount = 0;
    filePointer = fopen(argv[1],"r");
    printf ("opened file \n");
    if (filePointer == NULL) {
        printf ("No such file exists\n");
        exit (1);
    } // closes if for file pointer 
    unsigned int i = 0;
    char rip = ' ';
    while((rip = fgetc(filePointer)) != EOF){
        //bufferChar = rip;
        buffer[i] = (unsigned char)rip;
        //  printf ("placed into buffer\n");
        //printf ("%08x\n", buffer[i]);
        i++;
    } //closes while loop
    //puts ("placed into buffer array");
    if (i > MAX) {
        puts ("Rethink strat");
        printf ("%i\n", i);
        exit (1);
    } // closes if statement for i > MAX
    buffer[i] = 0x80;
    printf (" number of chars taken in: %i \n", i );
    //puts ("inserted EOL char");

    blockCount = calculateBlocks(i);
    unsigned int block [blockCount][16];
    unsigned int block2 [blockCount][80];
    //puts ("Created arrays");

    unsigned int v = 0;
    unsigned int j = 0;
    unsigned int p = 0;
    unsigned int o = 0;
    unsigned int eLoop = 0;

    for (v = 0; v < blockCount; v++) {
        unsigned char temp [64];
        p = 0;
       // puts ("created temp array");
        for (j = (v * 64); j < ((v + 1) * 64); j++) {
            temp[p] = buffer[j];
            //printf("%08x\n", temp[p]);
            if (temp[p] == 0x80) {
                p++;
                eLoop = 1;
                break;
            }
            //if (eLoop == 1)
                //puts ("this is a dud");
            p++;
            }
        if (eLoop = 1){
            //puts ("we hit it");
            for (p; p < 64; p++) {
                temp[p] = 0x0000000;
            }
            unsigned int b = 0;
           // for (o = 0; o < 64; o+=4){
                //block [v][b] = charPacker(temp[o],temp[o+1],temp[o+2],temp[o+3]);
                ///printf ("Printing block one %08x\n", block[v][b]);
                //b++;
           // }
           // break;
        }
        eLoop = 0;
        unsigned int b = 0;
        for (o = 0; o < 64; o+=4){
            block [v][b] = charPacker(temp[o],temp[o+1],temp[o+2],temp[o+3]);
            //printf ("Printing  one word  %08x\n", block[v][b]);
            b++;
         }
     }
    //puts ("work after char packer nonsense");
    unsigned int nLoop = 0;
    for (nLoop = 0; nLoop < blockCount; nLoop++) {
        unsigned int iLoop = 0;
        for (iLoop = 0; iLoop < 16; iLoop++) {
            block2[nLoop][iLoop] = block[nLoop][iLoop];
            //printf("block2 = %08x\n",block2[nLoop][iLoop]);
        }
    }
    //puts ("worked after placing everything into block 2");
    // i - 1 because i currently includes where 0x80 is currently 
    unsigned int placer = (i * 8);
    block2[blockCount - 1][15] += (unsigned int)placer;
    printf ("block2 placer (size)= %08x\n",  block2[blockCount - 1][15]);
    //printf ("%08x\n",placer);
    //puts ("placed the placer");

   // filling up rest of the blocks from 16 - 80 with a scramble
   for (j = 0; j < blockCount; j++) {
       for (o = 16; o < 80; o++) {
           unsigned int tempX = 0;
           tempX = (block2[j][o-3] ^ block2[j][o-8]  ^ block2[j][o-14] ^ block[j][o-16]);
                block2[j][o] = circleLeft((block2[j][o-3] ^ block2[j][o-8]  ^ block2[j][o-14] ^ block2[j][o-16]), 1); 
               //printf ("block2[%i] = %08x\n", o, block2[j][o]);
            }
        }
        //printf ("block2 [o][16] = %08x\n", block2[0][16]);
        //puts ("created the scramble");
        printf ("block count: %i \n",blockCount);
        for (j = 0; j <= blockCount-1; j++) {
            unsigned int temp = 0;
            o = 0;
            //printf ("This should work\n");
            unsigned int a = h[0]; unsigned int b = h[1]; unsigned int c = h[2]; unsigned int d = h[3]; unsigned int e = h[4];
            for (o = 0; o < 80; o++) {
                temp = 0;
                //printf ("o = %i\n",o);
                unsigned int cL = 0;
                unsigned int fS = 0;
                if ( o >= 0 && o <= 19 ) {
                    temp = circleLeft(a, 5)+f(o, b, c, d) + e + block2[j][o] + k[0];
                    //e = d; d = c; c = b; b = a; a = temp;
                     printf ("1 \t%08x %08x %08x %08x %08x\n", h[0], h[1], h[2], h[3], h[4]);

                } else if ( o >= 20 && o <= 39) {
                    temp = circleLeft(a, 5) + f(o, b, c, d) + e + block2[j][o] + k[1];
                    //e = d; d = c; c = b; b = a; a = temp;
                     printf ("2\t%08x %08x %08x %08x %08x\n", h[0], h[1], h[2], h[3], h[4]);

                } else if ( o >= 40 && o <= 59) {
                    temp = circleLeft(a, 5) + f(o, b, c, d) + e + block2[j][o] + k[2];
                    //e = d; d = c; c = b; b = a; a = temp;
                     printf ("3\t%08x %08x %08x %08x %08x\n", h[0], h[1], h[2], h[3], h[4]);

                } else if ( o >= 60 && o <= 79) {
                    temp = circleLeft(a, 5) + f(o, b, c, d) + e + block2[j][o] + k[3];
                   // e = d; d = c; c = b; b = a; a = temp; 
                    printf ("4\t%08x %08x %08x %08x %08x\n", h[0], h[1], h[2], h[3], h[4]);

                }
                //puts ("next loop");
                 e = d; d = c; c = circleLeft(b,30); b = a; a = temp;
                  printf ("4\t%08x %08x %08x %08x %08x\n", a, b, c, d, e);
                //h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e;
            }
            h0 += a; h1 += b; h2 += c; h3 += d; h4 += e;
            h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e;
             printf ("%08x %08x %08x %08x %08x\n", h0, h1, h2, h3, h4);
             //puts ("works");
        }
        puts("Message Digest:");
        printf ("%08x %08x %08x %08x %08x\n", h[0], h[1], h[2], h[3], h[4]);

    // close file
    int fileClosed = fclose(filePointer);
    if (fileClosed != 0) {
        puts ("File closed unsuccessfully");
    } else {
        puts ("File closed sucessfully");
    }
    return 0;
}

unsigned int onesComplement (unsigned int x) {
    unsigned int temp = x;
    temp = ~temp;
    return temp;
}
unsigned int charPacker (unsigned char one, unsigned char two, unsigned char three, unsigned char four) {
    unsigned int temp = one;
    temp <<= 8;
    temp |= two;
    temp <<= 8;
    temp |= three;
    temp <<= 8;
    temp |= four;
    return temp;
}

unsigned int circleLeft (unsigned int x, unsigned int y) {
    unsigned int z = ((x << y) | (x >> (32 - y))); // changed 8 to 32
    return z;
}

unsigned int calculateBlocks(unsigned int sizeOfFileInBytes) {
    unsigned int x = sizeOfFileInBytes;
    unsigned int y = 0;
    //y = floor (x/64) + 1;
    //if ((y%64) > 56)
    //    y++;
    y = (((8 * sizeOfFileInBytes) + 1) / 512) + 1;
    if((((8 * sizeOfFileInBytes) + 1) % 512) > (512 - 64)) 
        y = y + 1;
    return y;
}

unsigned int f (unsigned int t, unsigned int b, unsigned int c, unsigned d) {
    unsigned int temp = 0;
    //printf ("%i\n", t);
    if (t >= 0 && t <= 19) {
        temp = ((b & c) | ((~b) & d));
        return temp;
    } else if (t >= 20 && t <= 39) {
        temp = (b ^ c ^ d);
        return temp;
    } else if (t >= 40 && t <= 59) {
        temp = ((b & c) | (b & d) | (c & d));
        return temp;
    } else {
        temp = (b ^ c ^ d);
        return temp;
    }
}
