#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct STU{
    string id;
    int score;
    int lid, lrank; 
    int frank;
};

int main(){
    int k;
    cin >> k;
    int totalN = 0;
    vector<STU> totalStu;
    for(int i = 1; i <= k; i++){
        int tempN;
        cin >> tempN;
        totalN += tempN;
        vector<STU> tempStu;
        for(int j = 0; j < tempN; j++){
            string tempid;
            int tempS;
            cin >> tempid >> tempS;
            STU temp;
            temp.id = tempid;
            temp.lid = i;
            temp.score = tempS;
            tempStu.push_back(temp);
        }
        sort(tempStu.begin(), tempStu.end(), [](STU a, STU b){
            if(a.score != b.score) return a.score > b.score;
            else return a.id < b.id;
        });
        int carry = 1;
        tempStu[0].lrank = 1;
        for(int j = 1; j < tempN; j++){
            if(tempStu[j].score == tempStu[j-1].score){
                tempStu[j].lrank = tempStu[j-1].lrank;
                carry += 1;
            } else{
                tempStu[j].lrank = tempStu[j-1].lrank + carry;
                carry = 1;
            }
        }
        totalStu.insert(totalStu.end(), tempStu.begin(), tempStu.end());
    }
    sort(totalStu.begin(), totalStu.end(),[](STU a, STU b){
            if(a.score != b.score) return a.score > b.score;
            else return a.id < b.id;
    });
    int carry = 1;
    totalStu[0].frank = 1;
    for(int i = 1; i < totalN; i++){
        if(totalStu[i].score == totalStu[i-1].score){
            totalStu[i].frank = totalStu[i-1].frank;
            carry += 1;
        } else{
            totalStu[i].frank = totalStu[i-1].frank + carry;
            carry = 1;
        }
    }
    cout << totalN << endl;
    for(int i = 0; i < totalN; i++){
        cout << totalStu[i].id << " " << totalStu[i].frank << " " << totalStu[i].lid << " " << totalStu[i].lrank << endl;
    }
    return 0;
}