#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;

struct stu{
    string info;
    int score;
    bool operator<(const stu &b) const{        // 重制运算符就可以用set来自动排序了
        if (score != b.score)
            return score > b.score;
        return info < b.info;
    }
};


struct site{
    int id;
    int num;
    bool operator < (const site &b) const{
        if(num != b.num) return num > b.num;
        return id < b.id;
    }
};

int main(){
    int num, que;
    cin >> num >> que;
    set<stu> level[3];
    int site_num[1000] = {0};
    int site_score[1000] = {0};
    unordered_map<int, unordered_map<int, int>> date;
    for(int i = 0; i < num; i++){
        string info;
        int score;
        cin >> info >> score;
        if(info[0] == 'B') level[0].insert({info, score});
        else if(info[0] == 'A') level[1].insert({info, score});
        else level[2].insert({info, score});
        int temp_site = stoi(info.substr(1, 3));
        site_num[temp_site] += 1;
        site_score[temp_site] += score;
        int temp_date = stoi(info.substr(4, 6));
        if(date.count(temp_date) == 0) date[temp_date][temp_site] = 1;
        else {
            if(date[temp_date].count(temp_site) == 0)
                date[temp_date][temp_site] = 1;
            else date[temp_date][temp_site] += 1;
        }
    }
    for(int i = 1; i <= que; i++){
        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n",i, type, term.c_str());
        if(type == 1) {
            int level_index;
            if(term == "B") level_index = 0;
            else if(term == "A") level_index = 1;
            else level_index = 2;
            if(level[level_index].empty()) printf("NA\n");
            else {
                for(const auto& it : level[level_index])
                    printf("%s %d\n", it.info.c_str(), it.score);
            }

        }
        else if(type == 2){
            if(site_num[stoi(term)] == 0)
                printf("NA\n");
            else printf("%d %d\n", site_num[stoi(term)], site_score[stoi(term)]);
        }
        else{
            if(date.count(stoi(term)) == 0) printf("NA\n");
            else {
                set<site> ans;
                for(auto &it:date[stoi(term)]) ans.insert({it.first, it.second});
                for(auto it:ans) printf("%d %d\n",it.id, it.num);
            }
        }
    }
    return 0;
}

