#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string n1, n2;
    cin >> n1;
    n1.insert(0, 4-n1.length(), '0');
    do{
        sort(n1.begin(), n1.end());
        n2 = n1;
        reverse(n2.begin(), n2.end());
        int temp = stoi(n2) - stoi(n1);
        string nextStr = to_string(temp);
        while(nextStr.size() < 4){
            nextStr.insert(0, "0");
        }
        cout << n2 << " - " << n1 << " = " << nextStr << endl;
        n1 = nextStr;
    } while(n1 != "6174" && n1 != "0000");  
    return 0;
}