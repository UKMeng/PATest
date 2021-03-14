#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Car_record{
    int time, status;
    string id;
};
bool cmp1(Car_record a, Car_record b) {
    if(a.id != b.id) return a.id < b.id;
    else return a.time < b.time;
}
bool cmp2(Car_record a, Car_record b) {return a.time < b.time;}
/*
void show(vector<Car_record> a){
    int len = a.size();
    for(int i = 0; i < len; i++) {
        cout << a[i].id << " " << a[i].time << " " << a[i].status << endl;
    }
}
*/
int main() {
    int record_num, query_num;
    cin >> record_num >> query_num;
    vector<Car_record> records;
    for(int i = 0; i < record_num; i++){
        Car_record temp;
        string tid, ttime, tstatus;
        cin >> tid >> ttime >> tstatus;
        temp.time = stoi(ttime.substr(0, 2)) * 3600 + stoi(ttime.substr(3, 2)) * 60 + stoi(ttime.substr(6, 2));
        temp.id = tid;
        if(tstatus == "in") temp.status = 1;
        else temp.status = -1;
        records.push_back(temp);
    }
    sort(records.begin(), records.end(), cmp1);
    // show(records);
    int max_time = 0, park_time = 0;
    string pre = records[0].id;
    vector<Car_record> clean_records;
    vector<string> max_id;
    for(int i = 0; i < record_num - 1; i++){
        if(records[i].id == records[i+1].id && records[i].status == 1 && records[i+1].status == -1) {
            clean_records.push_back(records[i]);
            clean_records.push_back(records[i+1]);
            if(records[i].id != pre){
                if(max_time < park_time) {
                    max_time = park_time;
                    max_id.clear();
                    max_id.push_back(pre);
                } else if(max_time == park_time) {
                    max_id.push_back(pre);
                }
                pre = records[i].id;
                park_time = 0;
            }
            park_time += (records[i + 1].time - records[i].time);
        }
    }
    if(max_time < park_time) {
        max_time = park_time;
        max_id.clear();
        max_id.push_back(pre);
    } else if(max_time == park_time) {
        max_id.push_back(pre);
    }

    sort(clean_records.begin(), clean_records.end(), cmp2);
    // show(clean_records);
    int time_index = 0, count = 0;
    for(int i = 0; i < query_num; i++){
        string ttime;
        cin >> ttime;
        int query_time = stoi(ttime.substr(0, 2)) * 3600 + stoi(ttime.substr(3, 2)) * 60 + stoi(ttime.substr(6, 2));
        while(time_index < clean_records.size() && clean_records[time_index].time <= query_time){
            count += clean_records[time_index].status;
            time_index++;
        }
        cout << count << endl;
    }
    for(int i = 0; i < max_id.size(); i++) {
        cout << max_id[i] << " ";
    }
    printf("%02d:%02d:%02d", max_time / 3600, max_time % 3600 / 60, max_time % 60);
    return 0;
}