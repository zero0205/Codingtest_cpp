#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[500][500];
bool visited[500][500];

struct Pos{
    int x; 
    int y;
    Pos(int _x, int _y){x= _x; y = _y;}
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y){
    int cnt = 1;
    queue<Pos> q;
    visited[x][y] = true;
    q.push(Pos(x, y));
    while(!q.empty()){
        Pos pos = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = pos.x + dx[i];
            int ny = pos.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!visited[nx][ny] && board[nx][ny] == 1){
                q.push(Pos(nx, ny));
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num = 0;
    int biggest = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            visited[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && board[i][j] == 1){
                int w = bfs(i, j);
                biggest = max(w, biggest);
                num++;
            }
        }
    }
    cout << num << "\n" << biggest;
    return 0;
}