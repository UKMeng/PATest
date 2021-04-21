#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    vector<string> numWord = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n.size(); i++){
        sum += n[i] - '0';
    }
    string ans = to_string(sum);
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << numWord[ans[i] - '0'];
        else cout << numWord[ans[i] - '0'];
    }
    return 0;
}