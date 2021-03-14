#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> panda(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &panda[i]);
    }
    vector<int> milk(n, 200);
    for(int i = 1; i < n; i++){
        /*
        for(int j = 0; j < n; j++){
            cout << milk[j] << " ";
        }
        cout << endl;
        */
        if(panda[i] > panda[i-1]) milk[i] = milk[i-1] + 100;
        else if(panda[i] == panda[i-1]){
            milk[i] = milk[i-1];
        } else{
            for(int j = i-1; j >= 0; j--){
                if(panda[j] > panda[j+1] && milk[j] == milk[j+1]){
                    milk[j] += 100;
                } else if(panda[j] == panda[j+1] && milk[j] != milk[j+1]){
                    milk[j] = milk[j+1];
                } else if(panda[j] < panda[j+1]){
                    break;
                }
            }
        }
    }
    // sum
    int sum = 0;
    for(int i = 0; i < n; i++){
        //cout << milk[i] << " ";
        sum += milk[i];
    }
    printf("%d", sum);
    return 0;
}