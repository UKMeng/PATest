#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();
    unordered_map<string, set<string>> NAME;
    unordered_map<string, set<string>> AUTHOR;
    unordered_map<string, set<string>> KEY;
    unordered_map<string, set<string>> PRINT;
    unordered_map<string, set<string>> YEAR;
    for(int i = 0; i < n; i++){
        string id, name, author, key, print, year;
        getline(cin, id);
        getline(cin, name);
        getline(cin, author);
        getline(cin, key);
        getline(cin, print);
        getline(cin, year);
        NAME[name].insert(id);
        AUTHOR[author].insert(id);
        PRINT[print].insert(id);
        YEAR[year].insert(id);
        int start = 0;
        for(int i = 0; i < key.size(); i++){
            if(key[i] == ' '){
                //cout << "SS" << key.substr(start, i-start) << endl;
                KEY[key.substr(start, i-start)].insert(id);
                start = i+1;
            }
        }
        //cout << "SS" << key.substr(start, key.size()-start) << endl;
        KEY[key.substr(start, key.size()-start)].insert(id);

    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int type;
        scanf("%d: ", &type);
        string q;
        getline(cin, q);
        cout << type << ": " << q << endl;
        if(type == 1){
            if(NAME[q].size() != 0){
                for(auto name: NAME[q]){
                    cout << name << endl;
                }
                continue;
            }
        }
        if(type == 2){
            if(AUTHOR[q].size() != 0){
                for(auto name: AUTHOR[q]){
                    cout << name << endl;
                }
                continue;
            }
        }
        if(type == 3){
            if(KEY[q].size() != 0){
                for(auto name: KEY[q]){
                    cout << name << endl;
                }
                continue;
            }
        }
        if(type == 4){
            if(PRINT[q].size() != 0){
                for(auto name: PRINT[q]){
                    cout << name << endl;
                }
                continue;
            }
        }
        if(type == 5){
            if(YEAR[q].size() != 0){
                for(auto name: YEAR[q]){
                    cout << name << endl;
                }
                continue;
            }          
        }
        cout << "Not Found" << endl;
    }
    return 0;
}