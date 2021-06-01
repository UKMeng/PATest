#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int n, start;
    scanf("%d %d", &n, &start);
    unordered_map<int, int> keyOfNode;
    vector<int> nodeIn;
    unordered_map<int, int> ne;
    for(int i = 0; i < n; i++){
        int id, key, neid;
        scanf("%d %d %d", &id, &key, &neid);
        ne[id] = neid;
        keyOfNode[id] = key;
    }
    int now = start;
    while(now != -1){
        nodeIn.push_back(now);
        now = ne[now];
    }
    sort(nodeIn.begin(), nodeIn.end(), [&keyOfNode](int a, int b){return keyOfNode[a] < keyOfNode[b];});
    if(nodeIn.size() == 0){
        printf("0 -1\n");
        return 0;
    }
    printf("%d %05d\n", nodeIn.size(), nodeIn[0]);
    for(int i = 0; i < nodeIn.size(); i++){
        if(i != nodeIn.size()-1){
            printf("%05d %d %05d\n", nodeIn[i], keyOfNode[nodeIn[i]], nodeIn[i+1]);
        } else{
            printf("%05d %d -1\n", nodeIn[i], keyOfNode[nodeIn[i]]);
        }
    }
    return 0;
}