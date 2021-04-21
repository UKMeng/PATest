#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, string>> in_record, out_record;
    for(int i = 0; i < n; i++){
        string id;
        cin >> id;
        int ih, im, is, oh, om, os, in, out;
        scanf("%d:%d:%d", &ih, &im, &is);
        scanf("%d:%d:%d", &oh, &om, &os);
        in = ih * 3600 + im * 60 + is;
        out = oh * 3600 + om * 60 + os;
        in_record.push_back({in, id});
        out_record.push_back({out, id});
    }
    sort(in_record.begin(), in_record.end());
    sort(out_record.begin(), out_record.end());
    cout << in_record[0].second << " " << out_record.back().second << endl;
    return 0;
}