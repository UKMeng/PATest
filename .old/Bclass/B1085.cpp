#include <iostream>
#include <map>
#include <vector>
#include <algorithm>    //transform sort
#include <cctype>   //tolower
using namespace std;
typedef struct {
    double sum;
    int cnt;
    string name;
}UNI;
bool cmp(UNI a,UNI b) {
    if (a.sum!=b.sum)
        return a.sum>b.sum;
    else {
        if (a.cnt!=b.cnt)
            return a.cnt<b.cnt;
        else
            return a.name<b.name;
    }
}
int main(){
    int n,cnt=1;
    double score;
    char level;
    string name,id;
    map<string,int> unilist;
    vector<UNI> uni;
    cin>>n;
    for (int i=0; i<n; ++i) {
        cin>>id>>score>>name;
        if (id[0]=='B')
            score/=1.5;
        else if (id[0]=='T')
            score*=1.5;
        transform(name.begin(),name.end(),name.begin(),::tolower);
        if (unilist.find(name)==unilist.end()) {
            uni.push_back(UNI{score,1,name});
            unilist[name]=uni.size()-1;
        }else {
            uni[unilist[name]].sum+=score;
            ++uni[unilist[name]].cnt;
        }
    }
    for (int i=0; i<uni.size(); ++i)
            uni[i].sum=(int)uni[i].sum;
    sort(uni.begin(),uni.end(),cmp);
    cout<<uni.size()<<endl;
    for (int i=0,cnt=1; i<uni.size(); ++i) {
        if (i>0 && uni[i].sum!=uni[i-1].sum)
            cnt=i+1;
        cout<<cnt<<" ";
        cout<<uni[i].name<<" "<<uni[i].sum<<" "<<uni[i].cnt<<endl;
    }
}
