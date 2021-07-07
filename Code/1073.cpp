#include <iostream>
#include <string>
using namespace std;

int main(){
    string s, ans = "";
    cin >> s;
    if(s[0] == '-'){
        ans.push_back('-');
    }
    s.erase(s.begin());
    int pos = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'E'){
            pos = i;
            break;
        }
    }
    string s1, s2;
    s1 = s.substr(0, pos);
    s2 = s.substr(pos+1);
    int pl = s1.size() - 2;
    s1.erase(s1.begin()+1);
    int a2 = stof(s2);
    a2 -= pl;
    if(a2 == 0){
        ans.append(s1);
    } else if(a2 > 0){
        ans.append(s1);
        for(int i = 0; i < a2; i++){
            ans.push_back('0');
        }
    } else{
        if((-a2) >= s1.size()){
            ans.append("0.");
            for(int i = 0; i < (-a2) - s1.size(); i++){
                ans.push_back('0');
            }
            ans.append(s1);
        } else{
            int pindex = s1.size() + a2;
            for(int i = 0; i < s1.size(); i++){
                if(pindex == i){
                    ans.push_back('.');
                }
                ans.push_back(s1[i]);
            }
        }
    }
    cout << ans;
    return 0;
}