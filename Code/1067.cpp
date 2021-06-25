#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main(){
    unordered_map<int, int> place;
    set<int> dis;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        place[temp] = i;
        if(temp != i && temp != 0) dis.insert(temp);
    }
    int cnt = 0;
    while(dis.size() != 0){
        if(place[0] != 0){
            int temp = place[0];
            place[0] = place[temp];
            place[temp] = temp;
            dis.erase(temp);
        } else{
            int temp = *dis.begin();
            place[0] = place[temp];
            place[temp] = 0;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}