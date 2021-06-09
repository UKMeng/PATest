#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int table[100010];
stack<int> st;
int blockSize = (int)sqrt(100001*1.0); // 分块排序

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

int getMedian(const int block[]){
    int k = st.size()/2 + st.size()%2;
    int sum = 0;
    int i = st.size();
    for(i = 0; i < blockSize; i++){
        if(sum + block[i] < k){
            sum += block[i];
        } else{
            break;
        }
    }
    int num;
    int start = i * blockSize;
    int end = (i+1) * blockSize;
    for(num = start; num < end; num++){
        if(sum + table[num] < k){
            sum += table[num];
        } else{
            break;
        }
    }
    return num;
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
        } else if(str=="Push"){
            int temp;
            scanf("%d", &temp);
            push(block, temp);
        } else{
            if(st.empty()){
                printf("Invalid\n");
            } else{
                printf("%d\n", getMedian(block));
            }            
        }
    }
    return 0;
}