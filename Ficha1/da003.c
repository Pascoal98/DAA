#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 5290000

int charTonum(char c){
  if(c < 'K') return c - 'A';
  if(c < 'W') return c - 'A' - 1;
  if(c < 'Y') return c - 'A' - 2;
  return c - 'A' - 3;
}

int matTonum(char *matri){
  int gen = 0;
  if(isalpha(matri[0]) && isalpha(matri[6])) gen += 3*MAX;
  else if(isalpha(matri[3])) gen += 2*MAX;
  else if(isalpha(matri[6])) gen += MAX;

  int num = 0;
  int base = 1;
  for(int i = 7;i >= 0; i--){
    if(isdigit(matri[i])){
      num += (matri[i]-'0') * base;
      base*= 10;
    }
  }
  for(int i = 7; i >= 0; i--){
    if(isalpha(matri[i])){
      num += (charTonum(matri[i])) * base;
      base *= 23;
    }
  }
  return num + gen;
}

int main(int argc, char const *argv[]) {
  int t;
  char mat1[9], mat2[9];
  scanf("%d\n",&t);
  for(int i = 0; i < t; i++){
    scanf("%s %s",mat1,mat2);
    int v1 = matTonum(mat1);
    int v2 = matTonum(mat2);
    printf("%d\n",abs(v2-v1));
  }
  return 0;
}
