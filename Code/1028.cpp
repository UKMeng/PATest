#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct STU{
    string id, name;
    int score;
};

int main(){
    int n, c;
    cin >> n >> c;
    vector<STU> students;
    for(int i = 0; i < n; i++){
        STU temp;
        cin >> temp.id >> temp.name >> temp.score;
        students.push_back(temp);
    }
    if(c == 3) {
        sort(students.begin(), students.end(), [](STU a, STU b){
            if(a.score != b.score) return a.score < b.score;
            else return a.id < b.id;
        });
    } else if(c == 2){
        sort(students.begin(), students.end(), [](STU a, STU b){
            if(a.name != b.name) return a.name < b.name;
            else return a.id < b.id;
        });
    } else if(c == 1){
        sort(students.begin(), students.end(), [](STU a, STU b){
            return a.id < b.id;
        });
    }

    for(int i = 0; i < n; i++){
        STU temp = students[i];
        cout << temp.id << " " << temp.name << " " << temp.score << endl;
    }
    return 0;
}