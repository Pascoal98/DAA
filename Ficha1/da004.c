#include <stdio.h>

void maior(long long int n, int k){
  int soma = 0,y;
  while (soma != k){
    long long int n1 = n+1;
    soma = 0;
    while(n1 != 0){
      y = n1 % 10;
      n1 = n1 / 10;
      soma += y;
    }
    n++;
  }
  printf("%lld\n",n);
}
void menor(int k){
  long long int y,z = 1,n = 1;
  int soma = 0;
  int multiplier = k / 10;
  if(multiplier >= 8){
    for (int j = 0; j < multiplier+1; j++){
      n = n * 10 + 9;
      z *= 10;
    }
    while (soma != k-1){
      long long int n1 = n;
      soma = 0;
      while(n1 != 0){
        y = n1 % 10;
        n1 = n1 / 10;
        soma += y;
      }
      n += z;
    }
  }else {
    if(multiplier < 8){
      for (int j = 0; j < multiplier; j++){
        n = n * 10 + 9;
        z *= 10;
      }
      while (soma != k-1){
        long long int n1 = n;
        soma = 0;
        while(n1 != 0){
          y = n1 % 10;
          n1 = n1 / 10;
          soma += y;
        }
        n += z;
      }
    }
  }
  printf("%lld\n",n);
}
int main(){
  int t,k;
  long long int n;
  scanf("%d\n",&t);
  for(int i = 0; i < t; i++){
    scanf("%lld ",&n);
    scanf("%d\n",&k);
    if(n < k){
      menor(k);
    }else{
      maior(n,k);
    }
  }
  return 0;
}
