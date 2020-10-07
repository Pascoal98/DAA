  #include <stdio.h>

  int main(){
    int t,k,soma = 0;
    long long int n,y = 0,z=1;
    scanf("%d\n",&t);
    for(int i = 0; i < t; i++){
      scanf("%lld ",&n);
      scanf("%d\n",&k);
      soma = 0;
      if(n < k){
          n = 1;
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
    }else{
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
    }
      printf("%lld\n",n);
    }
    return 0;
  }
