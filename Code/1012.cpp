// 注意点 排名是1，1，3，4，5而不是1，1，2，3，4
// 用数组存储程序避免重复代码
// 平均分用总分代替
// 6位数且最后不用输出就不用string了，用int就ok了

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct STU{
    string id;
    int C, M, E, A;
};

struct RANK{
    int bestRank;
    string sub;
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<STU> stu(n);
    vector<RANK> rank(n);
    unordered_map<string, int> idmap;
    unordered_map<string, bool> idExist;
    for(int i = 0; i < n; i++){
        cin >> stu[i].id >> stu[i].C >> stu[i].M >> stu[i].E;
        stu[i].A = stu[i].C + stu[i].M + stu[i].E; // 平均分用总分代替
        idmap[stu[i].id] = i;
        idExist[stu[i].id] = true;
    }
    sort(stu.begin(), stu.end(), [](STU a, STU b){return a.A > b.A;});
    int r = 1;
    int c = 1;
    for(int i = 0; i < n; i++) {
        if(i == 0) r = 1;
        else{
            if(stu[i].A < stu[i-1].A) {
                r += c;
                c = 1;
            }
            else if(stu[i].A == stu[i-1].A){
                c++;
            }
        }
        rank[idmap[stu[i].id]].bestRank = r;
        rank[idmap[stu[i].id]].sub = "A";
    }
    sort(stu.begin(), stu.end(), [](STU a, STU b){return a.C > b.C;});
    r = 1;
    c = 1;
    for(int i = 0; i < n; i++) {
        if(i == 0) r = 1;
        else{
            if(stu[i].C < stu[i-1].C) {
                r += c;
                c = 1;
            }
            else if(stu[i].C == stu[i-1].C){
                c++;
            }
        }
        if(rank[idmap[stu[i].id]].bestRank > r){
            rank[idmap[stu[i].id]].bestRank = r;
            rank[idmap[stu[i].id]].sub = "C";
        }
    }
    sort(stu.begin(), stu.end(), [](STU a, STU b){return a.M > b.M;});
    for(int i = 0; i < n; i++) {
        if(i == 0) r = 1;
        else{
            if(stu[i].M < stu[i-1].M) {
                r += c;
                c = 1;
            }
            else if(stu[i].M == stu[i-1].M){
                c++;
            }
        }
        if(rank[idmap[stu[i].id]].bestRank > r){
            rank[idmap[stu[i].id]].bestRank = r;
            rank[idmap[stu[i].id]].sub = "M";
        }
    }
    sort(stu.begin(), stu.end(), [](STU a, STU b){return a.E > b.E;});
    r = 1;
    c = 1;
    for(int i = 0; i < n; i++) {
        if(i == 0) r = 1;
        else{
            if(stu[i].E < stu[i-1].E) {
                r += c;
                c = 1;
            }
            else if(stu[i].E == stu[i-1].E){
                c++;
            }
        }
        if(rank[idmap[stu[i].id]].bestRank > r){
            rank[idmap[stu[i].id]].bestRank = r;
            rank[idmap[stu[i].id]].sub = "E";
        }
    }
    for(int i = 0; i < m; i++){
        string id;
        cin >> id;
        if(!idExist[id]) cout << "N/A" << endl;
        else{
            int numid = idmap[id];
            cout << rank[numid].bestRank << " " << rank[numid].sub << endl;
        }
    }
    return 0;
}