#include <stdio.h>

int main() {
    int n,n42 = 0, rand;
    scanf("%d\n",&n);
    for(int i = 0; i < n; i++){
      scanf("%d\n",&rand);
      if(rand == 42) n42++;
    }
    printf("%d\n",n42);
  return 0;
}
