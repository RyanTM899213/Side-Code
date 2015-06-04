/* CS 3710 - Voc. Langs.
 * Assignment 6
 * Ryan Martin
 * 201039054
 * rtm773
 * Oct. 30/14
 */
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* to run this code, simply go to terminal and type './assign6' and enter the 
   input file  name with its extension. The program then writes to two output files.
 */  

// number 1
int main() {
    FILE *fin;
    FILE *fout;
    FILE *fout2;
    printf(">> enter filename with .txt extension: \n");
    char filename[15];
    scanf("%s", filename);
    fin = fopen(filename,"r+");
    fout = fopen("output1.txt","w");
    fout2 = fopen("output2.txt","w");
    char line[100];
    char ch;

    while(fscanf(fin,"%s",line) != EOF) {
        
        fprintf(fout,"%s ",line);
        fprintf(fout,"%s ",line);
        
        int length = strlen(line);
        int i;
        ch = getc(fin);
        for(i = length - 1; i >= 0; i--) {

            if (ch == '\n') fprintf(fout,"\n");
            fprintf(fout2,"%c",line[i]);
        }
        if (ch == '\n') fprintf(fout,"\n");
    }
    fclose(fout);
    fclose(fin);    
    fclose(fout2);
    return 0;        
}

// number 2       
int main() {

    // part a
    struct Person {
    
        char name[];
        char sex[];
        char profession[];
        char email[];
    }
            
    // part b
    struct Union {
    
        char name[];
        float fee;
        int member;
        Person *people[];
    }
        
}         
