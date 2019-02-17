#include <iostream>
#include <queue>
using namespace std;
int m, n, l, t;
struct node {
    int x, y, z;
} a;
int matrix[1290][130][70];
bool inq[1290][130][70];
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
bool judge(int x, int y, int z) {
    if(x >= n || x < 0 || y >= m || y < 0 || z >= l || z < 0) return false;
    if(matrix[x][y][z] == 0 || inq[x][y][z] == true) return false;
    return true;
}
int bfs(int x, int y, int z) {
    int cnt = 0;
    queue<node> q;
    a.x = x, a.y = y, a.z = z;
    q.push(a);
    inq[x][y][z] = true;
    while(!q.empty()) {
        node temp = q.front();
        q.pop();
        cnt++;
        for(int i = 0; i < 6; i++) {
            int newX = temp.x + X[i];
            int newY = temp.y + Y[i];
            int newZ = temp.z + Z[i];
            if(judge(newX, newY, newZ)) {
                a.x = newX, a.y = newY, a.z = newZ;
                q.push(a);
                inq[newX][newY][newZ] = true;
            }
        }
    }
    if(cnt >= t) return cnt;
    else return 0;
}
int main() {
    cin >> m >> n >> l >> t;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) cin >> matrix[k][j][i];
        }
    }
    int ans = 0;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(matrix[k][j][i] == 1 && inq[k][j][i] == false) {
                    ans += bfs(k, j, i);
                }
            }
        }
    }
    cout << ans;
    return 0;
}