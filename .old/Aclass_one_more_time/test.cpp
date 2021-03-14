#include <iostream>
#include <set>
using namespace std;

struct stu{
    string info;
    int score;
    bool operator < (const stu &b) const{
        if(score != b.score) {
            return score > b.score;
        }
        return info < b.info;
    }
}

int main() {
    set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(7);
    for(auto i = s.begin(); i != s.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    s.insert(5);
    for(auto i = s.begin(); i != s.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}