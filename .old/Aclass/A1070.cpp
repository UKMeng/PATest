#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    double storage;
    double total_price;
    double perprice;
} mooncake[1010];
bool cmp(node a, node b) {
    if (a.perprice != b.perprice) return a.perprice > b.perprice;
    else return a.storage > b.storage;
}
int main()
{
    int N, total_mo;
    double highest_profit = 0.0;
    cin >> N >> total_mo;
    for(int i = 0; i < N; i++) cin >> mooncake[i].storage;
    for(int i = 0; i < N; i++) {
        cin >> mooncake[i].total_price;
        mooncake[i].perprice = mooncake[i].total_price / mooncake[i].storage;
    }
    sort(mooncake, mooncake + N, cmp);
    for(int i = 0; i < N; i++) {
        if(total_mo > mooncake[i].storage) {
            highest_profit += mooncake[i].total_price;
            total_mo -= mooncake[i].storage;
        } else {
            highest_profit += total_mo * mooncake[i].perprice;
            break;
        }
    }
    printf("%.2f", highest_profit);
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct node {
//     int storage;
//     double total_price, perprice;
// };
// vector<node> mooncake;
// bool cmp(node a, node b) {
//     if (a.perprice != b.perprice) return a.perprice > b.perprice;
//     else return a.storage > b.storage;
// }
// int main() {
//     int n, need;
//     cin >> n >> need;
//     for(int i = 0; i < n; i++) {
//         int temp;
//         cin >> temp;
//         node tt;
//         tt.storage = temp;
//         mooncake.push_back(tt);
//     }
//     for(int i = 0; i < n; i++) {
//         double temp;
//         cin >> temp;
//         mooncake[i].total_price = temp;
//         mooncake[i].perprice = mooncake[i].total_price / (mooncake[i].storage * 1.0);
//     }
//     sort(mooncake.begin(), mooncake.end(), cmp);
//     double ans = 0.0;
//     for(int i = 0; i < n; i++) {
//         if(need > mooncake[i].storage) {
//             ans += mooncake[i].total_price;
//             need -= mooncake[i].storage;
//         } else {
//             ans += mooncake[i].perprice * (need * 1.0);
//             break;
//         }
//     }
//     printf("%.2f", ans);
//     return 0;
// }
