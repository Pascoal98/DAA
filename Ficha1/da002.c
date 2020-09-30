#include <stdio.h>

int main(){
  int t,n,k,y,soma = 0;
  scanf("%d\n",&t);
  for(int i = 0; i < t; i++){
    scanf("%d ",&n);
    scanf("%d\n",&k);
    soma = 0;
    while (soma != k){
      int n1 = n+1;
      soma = 0;
      while(n1 != 0){
        y = n1 % 10;
        n1 = n1 / 10;
        soma += y;
      }
      n++;
    }
    printf("%d\n",n);
  }
  return 0;
}
