#include <iostream>
#include <vector>
using namespace std;

int main(){
    int np, ng;
    scanf("%d %d",&np,&ng);
    vector<int> mice(np);
    vector<int> order(np);
    vector<int> rank(np);
    for(int i = 0; i < np; i++) {scanf("%d", &mice[i]);}
    for(int i = 0; i < np; i++) {scanf("%d", &order[i]);}
    //
    int num = np;
    while(num != 0){
        if(num == 1){
            rank[order[0]] = 1;
            break;
        }
        int teamNum = num / ng;
        if(num % ng != 0) teamNum += 1;
        int ranknow = teamNum + 1;
        vector<int> loser;
        vector<int> winner;
        int index = 0;
        for(int i = 0; i < teamNum; i++){
            if(index == order.size()) break;
            int maxNum = mice[order[index]];
            int maxindex = order[index];
            index++;
            for(int j = 1; j < ng; j++){
                if(index == order.size()) break;
                if(mice[order[index]] > maxNum){
                    maxNum = mice[order[index]];
                    loser.push_back(maxindex);
                    maxindex = order[index];
                } else{
                    loser.push_back(order[index]);
                }
                index++;
            }
            winner.push_back(maxindex);
        }
        //for(int i = 0; i < loser.size(); i++) cout << loser[i] << endl;
        order = winner;
        num = order.size();
        for(int i = 0; i < loser.size(); i++){
            rank[loser[i]] = ranknow;
        }
    }


    // output
    for(int i = 0; i < np; i++){
        if(i != 0) printf(" %d", rank[i]);
        else printf("%d", rank[i]);
    }
    return 0;
}