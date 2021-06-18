#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct People{
    string id;
    int virtue, talent, total;
};

bool cmp(People a, People b){
    if(a.total != b.total) return a.total > b.total;
    else if(a.virtue != b.virtue) return a.virtue > b.virtue;
    else return a.id < b.id;
}

void print(vector<People> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i].id << " " << a[i].virtue << " " << a[i].talent << endl;
    }
}

int main(){
    int n, l, h;
    cin >> n >> l >> h;
    vector<People> sage, nobleman, foolman, rest;
    for(int i = 0; i < n; i++){
        People temp;
        string s;
        int v, t;
        cin >> temp.id >> temp.virtue >> temp.talent;
        temp.total = temp.virtue + temp.talent;
        if(temp.virtue >= h && temp.talent >= h){
            sage.push_back(temp);
        } else if(temp.virtue >= h && temp.talent >= l){
            nobleman.push_back(temp);
        } else if(temp.virtue >= l && temp.talent >= l && temp.virtue >= temp.talent) {
            foolman.push_back(temp);
        } else if(temp.virtue >= l && temp.talent >= l){
            rest.push_back(temp);
        }
    }
    int count = sage.size() + nobleman.size() + foolman.size() + rest.size();
    sort(sage.begin(), sage.end(), cmp);
    sort(nobleman.begin(), nobleman.end(), cmp);
    sort(foolman.begin(), foolman.end(), cmp);
    sort(rest.begin(), rest.end(), cmp);
    cout << count << endl;
    print(sage);
    print(nobleman);
    print(foolman);
    print(rest);
    return 0;
}