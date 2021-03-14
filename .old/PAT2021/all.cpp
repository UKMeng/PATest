#include <iostream>
#include <vector>
#include <set> // set multiset
#include <cctype> // isalnum isalpha

using namespace std;

int main(){
    vector<int> test;
    multiset<int> t;
    test.push_back(1);
    test.push_back(2);
    test.push_back(4);
    test.push_back(9);
    t.insert(999);
    t.insert(231);
    t.insert(2143);
    t.insert(12091);
    for(auto a: test){
        cout << a;
    }
    cout << endl;
    int count = 10;
    for(auto &a:test){
        a = count--;
    }
    for(auto a:t){
        cout << a;
    }
    return 0;
}