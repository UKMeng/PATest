#include <iostream>
using namespace std;
int e[210][210];
int main() {
    int n, m, t1, t2, dis, query, minid = -1, mindis = 99999;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &t1, &t2, &dis);
        e[t1][t2] = e[t2][t1] = dis;
    }
    scanf("%d", &query);
    for(int j = 1; j <= query; j++) {
        int k, first, isSimple = 1, hashtable[210] = {0}, pre, tempdis = 0, isNa = 1, isCircle = 1, cnt = 1;
        scanf("%d %d", &k, &first);
        hashtable[first]++;
        pre = first;
        for(int i = 1; i < k; i++) {
            int temp;
            scanf("%d", &temp);
            if(e[temp][pre] == 0) {
                isNa = 0;
            }
            tempdis += e[temp][pre];
            if(hashtable[temp] == 0) cnt++;
            hashtable[temp]++;
            if((hashtable[temp] == 2 && (temp != first)) || hashtable[temp] == 3) isSimple = 0;
            pre = temp;
        }
        if(isNa == 1) printf("Path %d: %d ", j, tempdis);
        else if(isNa == 0) printf("Path %d: NA ", j);
        if(isNa == 0 || cnt != n || pre != first) printf("(Not a TS cycle)\n");
        else {
            if(isSimple == 0) printf("(TS cycle)\n");
            else printf("(TS simple cycle)\n");
            if(tempdis < mindis) {
                mindis = tempdis;
                minid = j;
            }
        }
    }
    printf("Shortest Dist(%d) = %d", minid, mindis);
    return 0;
}