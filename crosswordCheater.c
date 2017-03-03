/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/23/2015
*Assignment 5, Problem 2:
*A program which takes a partial word and produces of possible valid English words by matching them against a standard dictionary 
*/

#include <stdlib.h>
#include <stdio.h>
int comparator(const char* p1, const char* p2, const int size);
void Cheat(int size, char*word);

int comparator(const char* p1, const char* p2, const int size){
    int l = 0;
    while(l <= size){
        if(p1[l] != 45 && p1[l] != p2[l]){
             return 0;
        }
        l++;
    }
return 1;
}
void Cheat(int size, char* word){
    FILE * fp;
    fp = fopen("/usr/share/dict/american", "r");
    int i;
    int j;
    int k;
    char buffer[100];
    fgets(buffer, 100, fp);
    char match[100];
    k=0;
    while(k<=100){
        match[k] = buffer[k];
        k++;
    }
    j=0;
    while(j < 305090){
        if(comparator(match, word, size)){
            printf("%s\n", match);
        }
        k= 0;
        fgets(buffer, 100,fp);
        while(k<=100){
            match[k] = buffer[k];
            k++;
        }
        j++;
    }
}

int main(int argc, char *argv){
    Cheat(argc, argv);
    //Cheat(5 ,"b--ts");
    return 0;
}
