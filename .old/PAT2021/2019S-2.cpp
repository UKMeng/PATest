#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

bool cmp(string a, string b){
    string sa = a.substr(6, 8), sb = b.substr(6, 8);
    return sa < sb;
}

int main(){
    int n;
    cin >> n;
    unordered_map<string, bool> m;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        m[temp] = true;
    }
    vector<string> al, gu;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        string temp;
        cin >> temp;
        if(m[temp]) al.push_back(temp);
        gu.push_back(temp);
    }
    int num = al.size();
    cout << num << endl;
    if(num == 0){
        sort(gu.begin(), gu.end(), cmp);
        cout << gu[0] << endl;
    } else{
        sort(al.begin(), al.end(), cmp);
        cout << al[0] << endl;
    }
    return 0;
}