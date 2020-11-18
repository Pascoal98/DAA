#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int main(){

    multiset<int> bakugans;

    int additions,removes,addcounter = 0,remcounter = 0;
    char bak[] = "BAK", min[] = "MIN", max[] = "MAX";
    scanf("%i %i",&additions,&removes);

    while(addcounter <= additions && remcounter < removes){
        char var[4];
        cin >> var;
        if(strcmp(var,bak) == 0){
            int value;
            scanf("%i",&value);
            bakugans.insert(value);
            //printf("%i\n",value);
            addcounter++;
            //printf("%i\n",addcounter);
        }else if(strcmp(var,min) == 0){
            int it = *bakugans.begin();
            printf("%i\n",it);
            bakugans.erase(bakugans.lower_bound(it));
            remcounter++;
            //printf("%i\n",remcounter);
        }else if(strcmp(var,max) == 0){
            int it = *bakugans.rbegin();
            
            printf("%i\n",it);
            bakugans.erase(bakugans.lower_bound(it));
            remcounter++;
            //printf("%i\n",remcounter);
        }
    }
    return 0;
}