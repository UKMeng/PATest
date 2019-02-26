#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int convert(int hh, int mm, int ss) {return hh * 3600 + mm * 60 + ss;}
int sttime, edtime;
struct member {
    int comet, startt, playt;
    bool isVip;
} newmember;
struct table {
    int endt, snum;
    bool isVip;
} inittable;
vector<member> mem, ans;
vector<table> tab;
queue<member> ordinay, vip;
void vipprocess(int id, int idx) {
    if(mem[id].comet >= tab[idx].endt) {
        mem[id].startt = mem[id].comet;
        if(mem[id].startt >= edtime) {mem.erase(mem.begin()); return;}
        tab[idx].endt = mem[id].startt + mem[id].playt * 60;
    } else {
        mem[id].startt = tab[idx].endt;
        if(mem[id].startt >= edtime) {mem.erase(mem.begin()); return;}
        tab[idx].endt = mem[id].startt + mem[id].playt * 60;
    }
    tab[idx].snum++;
    ans.push_back(mem[id]);
    mem.erase(mem.begin() + id);
}
void show(int t) {printf("%02d:%02d:%02d ", t / 3600, (t / 60) % 60, t % 60);}
bool cmp(member a, member b) {return a.comet < b.comet;}
int main() {
    int n, k, m;
    sttime = convert(8, 0, 0);
    edtime = convert(21, 0, 0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int th, tm, ts, tb, pt;
        scanf("%d:%d:%d %d %d", &th, &tm, &ts, &pt, &tb);
        if(pt > 120) pt = 120;
        newmember.playt = pt;
        newmember.comet = convert(th, tm, ts);
        if(newmember.comet >= edtime) continue;
        newmember.isVip = tb;
        mem.push_back(newmember);
    }
    sort(mem.begin(), mem.end(), cmp);
    scanf("%d %d", &k, &m);
    for(int i = 0; i < k; i++) {
        inittable.snum = 0;
        inittable.endt = sttime;
        inittable.isVip = false;
        tab.push_back(inittable);
    }
    for(int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        tab[t - 1].isVip = true;
    }
    while(!mem.empty()) {
        int idx, minedtime = 0x7fffffff;
        for(int i = 0; i < k; i++) {
            if(minedtime > tab[i].endt) {
                idx = i;
                minedtime = tab[i].endt;
            } 
        }
        if(tab[idx].isVip) {
            if(mem[0].comet >= tab[idx].endt) vipprocess(0, idx);
            else {
                if(mem[0].isVip) {
                    vipprocess(0, idx);
                } else {
                    int vipid = 0;
                    for(int i = 1; i < mem.size(); i++) {if(mem[i].isVip) {vipid = i; break;}}
                    vipprocess(vipid, idx);
                }
            }
        } else {
            if(mem[0].isVip) {
                int vipidx, minvipedtime = 0x7fffffff;
                for(int i = 0; i < k; i++) {
                    if(tab[i].isVip) {
                        if(tab[i].endt < minvipedtime) {
                            vipidx = i;
                            minvipedtime = tab[i].endt;
                        }
                    } 
                }
                if(tab[vipidx].endt <= mem[0].comet) vipprocess(0, vipidx);
                else vipprocess(0, idx);
            } else vipprocess(0, idx);
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        int t = ans[i].startt - ans[i].comet + 30;
        show(ans[i].comet);
        show(ans[i].startt);
        printf("%d\n", t / 60);
    }
    for(int i = 0; i < k; i++) {
        if(i != 0) printf(" ");
        printf("%d", tab[i].snum);
    }
    return 0;
}