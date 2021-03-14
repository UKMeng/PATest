#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 10;
char nameTable[maxn][5];
int get_id(char *s) {
    int temp = 0;
    for(int i = 0; i < 3; i++) temp = temp * 26 + (s[i] - 'A');
    temp = temp * 10 + (s[3] - '0');
    return temp;
}
vector<int> course[2510];
int main() {
    char name[5];
    int n, k, c, s;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s %d", name, &c);
        int id = get_id(name);
        strcpy(nameTable[id], name);
        for(int j = 0; j < c; j++) {
            scanf("%d", &s);
            course[s].push_back(id);
        }
    }
    for(int i = 1; i <= k; i++) {
        int num = course[i].size();
        sort(course[i].begin(), course[i].end());
        printf("%d %d", i, num);
        if(num != 0) printf("\n");
        for(int j = 0; j < num; j++) {
            printf("%s", nameTable[course[i][j]]);
            if(j != num - 1) printf("\n");
        }
        if(i != k) printf("\n");
    }
    return 0;
}