#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct STU{
    int id;
    vector<int> score;
    int total;
    int perfect;
};

int main(){
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> perfect(k);
    for(int i = 0; i < k; i++) cin >> perfect[i];
    unordered_map<int, int> stuIndex;
    vector<STU> ans;
    int count = 1;
    for(int i = 0; i < s; i++){
        int id, qid, score;
        cin >> id >> qid >> score;
        STU temp;
        if(stuIndex[id] != 0){
            temp = ans[stuIndex[id]-1];
            temp.score[qid-1] = max(score, temp.score[qid-1]);
            ans[stuIndex[id]-1] = temp;
        } else{
            stuIndex[id] = count;
            temp.score.resize(k, -2);
            temp.score[qid-1] = max(score, temp.score[qid-1]);
            temp.id = id;
            ans.push_back(temp);
            count++;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        int total = 0;
        int pn = 0;
        bool isVaild = false;
        for(int j = 0; j < k; j++){
            if(ans[i].score[j] > -1){
                isVaild = true;
                total += ans[i].score[j];
                if(ans[i].score[j] == perfect[j]){
                    pn++;
                }
            } else if(ans[i].score[j] == -1){
                ans[i].score[j] = 0;
            }
        }
        if(isVaild) ans[i].total = total;
        else ans[i].total = -1;
        ans[i].perfect = pn;
    }
    sort(ans.begin(), ans.end(), [](STU a, STU b){
        if(a.total != b.total){
            return a.total > b.total;
        } else if(a.perfect != b.perfect){
            return a.perfect > b.perfect;
        } else{
            return a.id < b.id;
        }
    });
    int rank = 1, last = 1;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i].total == -1) break;
        if(i != 0){
            if(ans[i].total == ans[i-1].total){
                rank = last;
            } else{
                rank = i + 1;
                last = i + 1;
            }
        }
        printf("%d %05d %d", rank, ans[i].id, ans[i].total);
        for(int j = 0; j < k; j++){
            if(ans[i].score[j] == -2){
                printf(" -");
            } else{
                printf(" %d", ans[i].score[j]);
            }
        }
        printf("\n");
    }
    return 0;
}