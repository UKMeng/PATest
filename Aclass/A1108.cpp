#include <iostream>
#include <cstring>
using namespace std;
bool isNum(string num) {
    int cntde = 0;
    bool dot = false;
    for(int i = 0; i < num.size(); i++) {
        if(i == 0 && num[i] == '-') continue;
        else if(dot == false && num[i] == '.') dot = true;
        else if(num[i] <= '9' && num[i] >= '0') {
            if(dot == true) cntde++;
            if(cntde > 2) return false;
            continue;
        }
        else return false;
    }
    double temp = stof(num);
    if(temp <= 1000 && temp >= -1000) return true;
    else return false;
}
int main() {
    int n, cnt = 0;
    double sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string num;
        cin >> num;
        if(!isNum(num)) cout << "ERROR: " << num << " is not a legal number" << endl;
        else {
            double temp = stof(num);
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 0) cout << "The average of 0 numbers is Undefined" << endl;
    else if(cnt == 1) printf("The average of 1 number is %.02f\n", sum);
    else printf("The average of %d numbers is %.02f\n", cnt, sum / cnt);
    return 0;
}