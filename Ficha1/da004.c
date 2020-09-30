#include <stdio.h>

int main(){
  int t,k,y,soma = 0;
  long long int n;
  scanf("%d\n",&t);
  for(int i = 0; i < t; i++){
    scanf("%lld ",&n);
    scanf("%d\n",&k);
    soma = 0;
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
  return 0;
}
