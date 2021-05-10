#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string str;
    cin >> str;
    int N = str.size();
    int n1 = (N + 2) / 3;
    int n2 = N - 2 * n1;
    string s1 = str.substr(0, n1);
    string s2 = str.substr(n1, n2);
    string s3 = str.substr(n1+n2, n1);
    reverse(s3.begin(), s3.end());
    for(int i = 0; i < n1; i++){
        cout << s1[i];
        for(int j = 0; j < n2; j++) {
            if(i == n1-1){
                cout << s2[j];
            }
            else cout << " ";
        }
        cout << s3[i] << endl;
    }
    return 0;
}