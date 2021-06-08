#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int table[100010];
stack<int> st;
int blockSize = (int)sqrt(100001*1.0);

void push(int block[], int x){
    st.push(x);
    table[x]++;
    block[x/blockSize]++;
}

int pop(int block[]){
    int x = st.top();
    st.pop();
    table[x]--;
    block[x/blockSize]--;
    return x;
}

int main(){
    int block[blockSize];
    memset(block, 0, sizeof(block));
    int n;
    scanf("%d", &n);
    string str;
    int num;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str=="Pop"){
            if(st.empty()){
                printf("Invalid\n");
            } else{
                printf("%d\n", pop(block));
            }
        }
    }
}