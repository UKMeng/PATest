#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> stk;
    multiset<int> rank;
    int n;
    scanf("%d", &n);
    while(n){
        string str;
        cin >> str;
        if(str == "Pop"){
            if(stk.size() == 0){
                cout << "Invalid" << endl;
            } else{
                int temp = stk.back();
                stk.pop_back();
                rank.erase(temp);
                cout << temp << endl;
            }
        } else if(str == "PeekMedian"){
            int k = stk.size();
            if(k == 0) cout << "Invalid" << endl;
            else{
                int index;
                if(k % 2 == 0) index = k / 2 - 1;
                else index = (k + 1) / 2 - 1;
                auto it = rank.begin();
                for(int i = 0; i < index; i++) it++;
                cout << *it << endl;
            }
        } else if(str == "Push"){
            int temp;
            cin >> temp;
            stk.push_back(temp);
            rank.insert(temp);
        }
        n--;
    }
    return 0;
}