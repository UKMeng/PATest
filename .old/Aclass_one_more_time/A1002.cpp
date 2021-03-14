#include <iostream>
#include <vector>
using namespace std;

double poly[1010];

int main(){
    for(int i = 0; i < 2; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int N;
            double K;
            cin >> N >> K;
            poly[N] += K;
        }
    }
    vector<pair<int, double> > ans;
    for(int i = 1009; i >= 0; i--){
        if(poly[i] != 0) {
            ans.push_back(make_pair(i, poly[i]));
        }
    }
    cout << ans.size();
    for(int i = 0; i < ans.size(); i++){
        //cout << " " << ans[i].first << " " << ans[i].second;
        printf(" %d %.1f", ans[i].first, ans[i].second);
    }
    return 0;
}