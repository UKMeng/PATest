#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    string name;
    int age, worth;
};

bool cmp(Node a, Node b){
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age < b.age;
    else return a.name < b.name;
}

int main(){
    vector<Node> nodes;
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        Node temp;
        char name[9];
        scanf("%s %d %d", name, &temp.age, &temp.worth);
        temp.name = name;
        nodes.push_back(temp);
    }
    sort(nodes.begin(), nodes.end(), cmp);
    for(int i = 1; i <= k; i++){
        cout << "Case #" << i << ":" << endl;
        int maxNum, Amin, Amax; 
        scanf("%d %d %d", &maxNum, &Amin, &Amax);
        int temp = maxNum;
        for(int j = 0; j < n; j++){
            if(nodes[j].age <= Amax && nodes[j].age >= Amin){
                cout << nodes[j].name << " " << nodes[j].age << " " << nodes[j].worth << endl;
                maxNum--;
            }
            //if(nodes[j].age > Amax) break;
            if(maxNum == 0) break;
        }
        if(temp == maxNum) {
            cout << "None" << endl;
        }
    }
    return 0;
}