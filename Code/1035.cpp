#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<string, string>> ans;
    for(int i = 0; i < n; i++){
        string id, pw;
        cin >> id >> pw;
        bool flag = true;
        for(int j = 0; j < pw.size(); j++){
            if(pw[j] == '0'){
                pw[j] = '%';
                flag = false;
            } else if(pw[j] == '1'){
                pw[j] = '@';
                flag = false;
            } else if(pw[j] == 'l'){
                pw[j] = 'L';
                flag = false;
            } else if(pw[j] == 'O'){
                pw[j] = 'o';
                flag = false;
            }
        }
        if(!flag){
            ans.push_back({id, pw});
        }
    }
    if(ans.size() == 0){
        if(n == 1){
            cout << "There is 1 account and no account is modified" << endl;
        } else{
            cout << "There are " << n << " accounts and no account is modified" << endl;
        }
    } else{
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}