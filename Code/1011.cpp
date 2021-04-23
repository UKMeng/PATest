#include <iostream>
using namespace std;
int main() {
    string text = "WTL";
    double ans = 1.0;
	for(int i = 0; i < 3; i++){
        double maxOdd = 0;
        int id;
        for(int j = 0; j < 3 ; j++){
            double odd;
            cin >> odd;
            if(maxOdd < odd){
                maxOdd = odd;
                id = j;
            }
        }
        cout << text[id] << " ";
        ans *= maxOdd;
    }
	ans = (ans * 0.65 - 1.0) * 2;
	printf("%.2f", ans);
	return 0;
}