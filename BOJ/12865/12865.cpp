#include <iostream>
using namespace std;

int n, k;
int w[101]= {0, };
int v[101]= {0, };
int dp[101][100001];

int main(){
    cin >> n >> k;

    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    // Initialize dp
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=k;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j-w[i] < 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}