#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int cal(int pre, int now, char op){
    if(op == '+') return pre + now;
    else if(op == '-') return pre - now;
    else if(op == '*') return pre * now;
    else return pre / now;
}

int calculate(string s) {
    stack<char> ops;
    string num;
    int ans = 0;
    stack<int> nums;
    nums.push(0);
    ops.push('+');
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            num += s[i];
        } else{
            if(s[i] == ' ') continue;
            if(num.size() != 0){
                int temp = stoi(num);
                num = "";
                if(ops.top() == '*' || ops.top() == '/'){
                    int pre = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    temp = cal(pre, temp, op);
                    nums.push(temp);
                } else{
                    nums.push(temp);
                }
                ops.push(s[i]);
            }
        }
    }
    if(num.size() != 0){
        int temp = stoi(num);
        num = "";
        if(ops.top() == '*' || ops.top() == '/'){
            int pre = nums.top(); nums.pop();
            char op = ops.top(); ops.pop();
            temp = cal(pre, temp, op);
            nums.push(temp);
        } else{
            nums.push(temp);
        }
    }
    while(!ops.empty()){
        char op = ops.top(); ops.pop();
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        a = cal(a, b, op);
        nums.push(a);
    }
    return nums.top();
}

int main(){
    string s = " 2*2*2 + 1 ";
    int a = calculate(s);
    cout << a << endl;
    return 0;
}