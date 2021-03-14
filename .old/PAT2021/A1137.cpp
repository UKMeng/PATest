#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

struct Node{
    string name;
    vector<int> s;
};

bool cmp(Node a, Node b){
    if(a.s[3] != b.s[3]) return a.s[3] > b.s[3];
    else return a.name < b.name;
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> stu_score;
    unordered_map<string, int> stu;
    unordered_map<string, bool> is_stu;
    int count = 0;
    for(int i = 0; i < n; i++){
        string name;
        int score;
        cin >> name >> score;
        if(score >= 200){
            vector<int> temp(4, -1);
            temp[0] = score;
            is_stu[name] = true;
            stu[name] = count++;
            stu_score.push_back(temp);
        }
    }
    for(int i = 0; i < m; i++){
        string name;
        int score;
        cin >> name >> score;
        if(is_stu[name]){
            int id = stu[name];
            stu_score[id][1] = score;
        }
    }
    vector<Node> student;
    for(int i = 0; i < k; i++){
        string name;
        int score;
        cin >> name >> score;
        if(is_stu[name]){
            int id = stu[name];
            stu_score[id][2] = score;
            if(stu_score[id][1] > stu_score[id][2]){
                stu_score[id][3] = round(stu_score[id][1]*0.4 + stu_score[id][2]*0.6);
            } else{
                stu_score[id][3] = score;
            }
            if(stu_score[id][3] >= 60){
                Node temp;
                temp.name = name;
                temp.s = stu_score[id];
                student.push_back(temp);
            }
        }
    }
    sort(student.begin(), student.end(), cmp);
    for(int i = 0; i < student.size(); i++){
        cout << student[i].name;
        printf(" %d %d %d %d\n", student[i].s[0], student[i].s[1], student[i].s[2], student[i].s[3]);
    }
    return 0;
}