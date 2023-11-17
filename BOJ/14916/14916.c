#include <stdio.h>

int main(){
    int n, tmp;
    scanf("%d", &n);
    if(n == 1 || n == 3){
        printf("%d", -1);
        return 0;
    }
    for(int i=n/5;i>=0;i--){
        tmp = n - 5*i;
        if(tmp%2 == 0){
            printf("%d", i+tmp/2);
            break;
        }
    }
    return 0;
}