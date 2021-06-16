#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int hh, mm;
    char c1, c2;
    int cnt = 1;
    for(int i = 0; i < min(s1.length(), s2.length()); i++){
        if(cnt == 1){
            if(s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G')){
                c1 = s1[i];
                cnt++;
            }
        } else if(cnt == 2){
            if(s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N')||isdigit(s1[i]))){
                c2 = s1[i];
                break;
            }
        }
    }
    vector<string> day = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    if(isupper(c2)){
        hh = (c2 - 'A') + 10;
    } else{
        hh = (c2 - '0');
    }    
    for(mm = 0; mm < min(s3.length(), s4.length()); mm++){
        if(s3[mm] == s4[mm] && isalpha(s3[mm])) break;
    }
    printf("%s %02d:%02d", day[c1-'A'].c_str(), hh, mm);
    return 0;
}