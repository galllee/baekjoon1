#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int m, n, day = -1;
bool fail = false;
int arr[1001][1001] = {0, };
int vis[1001][1001] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<pair<int, int>, int>> q;

void bfs(){
    while(!q.empty()){
        pair<int, int> cur = q.front().X;
        day = q.front().Y + 1;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == -1 || vis[nx][ny] == 1) {
                continue;
            }
            if (vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({{nx, ny}, day});
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (arr[i][j] == 1){
                q.push({{i, j}, day});
                vis[i][j] = 1;
            }
        }
    }
    bfs();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (vis[i][j] == 0 && arr[i][j] != -1) {
                fail = true;
            }
        }
    }

    if (fail)   cout << -1;
    else    cout << day;
}