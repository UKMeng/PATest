#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10010;
struct node {
    int id, pg, mg, fg, tg;
    string name;
};
map<string, int> ma; 
vector<node> student;
bool cmp(node a, node b) {
    if(a.tg != b.tg)  return a.tg > b.tg;
    else return a.name < b.name;
}
int failed[maxn];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int id = 0;
    for(int i = 0; i < n; i++) {
        string name;
        int pg_;
        cin >> name >> pg_;
        ma[name] = id++;
        node temp;
        temp.id = ma[name];
        temp.pg = pg_;
        temp.name = name;
        temp.mg = -1;
        temp.fg = 0;
        student.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        string name;
        int mg_;
        cin >> name >> mg_;
        if(ma.find(name) == ma.end()) {continue;}
        else student[ma[name]].mg = mg_;
    }
    for(int i = 0; i < k; i++) {
        string name;
        int fg_;
        cin >> name >> fg_;
        if(ma.find(name) == ma.end()) {continue;}
        else student[ma[name]].fg = fg_;
    }
    auto it = student.begin();
    int num = student.size();
    while(it != student.end()) {
        if(it -> pg < 200) {
            it -> tg = -1;
            num--;
        }
        if(it -> mg > it -> fg) {
            it -> tg =  (int)((double)(it -> mg) * 0.4 + (double)(it -> fg) * 0.6 + 0.5);
        } else it -> tg = it -> fg;
        if(it -> tg < 60) {
            it -> tg = -1;
            num--;
        }
        it++;
    }
    sort(student.begin(), student.end(), cmp);
    for(int i = 0; i < num; i++) {
        cout << student[i].name << " " << student[i].pg << " " << student[i].mg << " " << student[i].fg << " " << student[i].tg << endl;
    }
    return 0;
}