#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPalin(vector<int> a) {
	vector<int> b = a;
	reverse(a.begin(), a.end());
	if(a == b) return true;
	else return false;
}
vector<int> base_change(int num, int base) {
	vector<int> ans;
	do {
		ans.push_back(num % base);
		num /= base;
	} while(num);
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	int num, base;
	cin >> num >> base;
	vector<int> a = base_change(num, base);
	if(isPalin(a)) cout << "Yes" << endl;
	else cout << "No" << endl;
	for(int i = 0; i < a.size(); i++) {
		if(i != 0) cout << " " ;
		cout << a[i];
	}
	return 0;
}