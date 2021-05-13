#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string fname, mname, fid, mid;
    int highF = -1, lowM = 101;
    for(int i = 0; i < n; i++){
        string tempName, tempG, tempid;
        int tempScore;
        cin >> tempName >> tempG >> tempid >> tempScore;
        if(tempG == "M"){
            if(tempScore < lowM){
                lowM = tempScore;
                mname = tempName;
                mid = tempid;
            }
        } else{
            if(tempScore > highF){
                highF = tempScore;
                fname = tempName;
                fid = tempid;
            }
        }
    }
    bool flag = true;
    if(highF == -1) {
        flag = false;
        cout << "Absent" << endl;
    } else cout << fname << " " << fid << endl;
    if(lowM == 101){
        flag = false;
        cout << "Absent" << endl;
    } else cout << mname << " " << mid << endl;
    if(flag) cout << highF - lowM << endl;
    else cout << "NA" << endl;
    return 0;
}