#include <stdio.h>

int main(){
    int x;
    int cnt = 0;
    scanf("%d", &x);
    while(1){
        if(x == 0) break;
        if(x%2 == 1) cnt++;
        x/=2;
    }
    printf("%d", cnt);
    return 0;
}