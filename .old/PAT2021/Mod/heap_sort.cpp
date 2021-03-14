#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void down_adjust(vector<int>& nums, int low, int high){
    int i = low, j = i * 2 + 1;
    while(j <= high){
        if(j + 1 <= high && nums[j+1] > nums[j]) j = j + 1; // 大小根堆只需要调整这两个位置的大小号
        if(nums[i] >= nums[j]) break; // 大小根堆只需要调整这两个位置的大小号
        swap(nums[i], nums[j]);
        i = j;
        j = i * 2 + 1;
    }
}

void build_max_heap(vector<int>& nums, int len){
    for(int i = len / 2; i >= 0; i--){
        down_adjust(nums, i, len);
    }
}

void heap_sort(vector<int>& nums){ // 以大根堆为例
    int len = nums.size() - 1;
    build_max_heap(nums, len);
    for(int i = len; i >= 1; i--){
        swap(nums[i], nums[0]);
        len -= 1;
        down_adjust(nums, 0, len);
    }
}

int main(){
    vector<int> nums = {3,1,2,8,7,5,9,4,6,0};
    for(int num: nums){
        cout << num << " ";
    }
    cout << endl;
    heap_sort(nums);
    for(int num: nums){
        cout << num << " ";
    }
    return 0;
}