#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<string, string> m; // 存储上级
unordered_map<string, bool> is_existed;
unordered_map<int, string> now;

void DFS(string s){
    if(s == "0000") {
        cout << s;
    } else{
        DFS(m[s]);
        cout << "->" << s;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    now[0] = "0000";
    string temp;
    // getline(cin, temp);
    cin.get();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int pos = 0;        
        for(pos; pos < s.size(); pos++){
            if(s[pos] != ' '){
                break;
            }
        }        
        string id = s.substr(pos, 4);
        is_existed[id] = true;
        if(i == 0) continue;
        m[id] = now[pos-1];
        now[pos] = id;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        string a;
        cin >> a;
        if(!is_existed[a]) cout << "Error: " << a << " is not found." << endl;
        else{
            DFS(a);
            cout << endl;
        }
    }
    return 0;
}