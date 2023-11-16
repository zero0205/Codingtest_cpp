#include <stdio.h>

int fixed[41];
int dp[41];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d", &fixed[i]);
    }

    // dp 배열 채우기
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<41;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    int cnt = 1;
    int prev = 0;
    for(int i=0;i<m;i++){
        cnt *= (dp[fixed[i]-prev-1]);
        prev = fixed[i];
    }
    cnt *= dp[n-prev];

    printf("%d", cnt);
}