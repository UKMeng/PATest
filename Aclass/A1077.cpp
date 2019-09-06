#include <iostream> // 字符串
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	getchar();
	string s, ans;
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		reverse(s.begin(), s.end());
		if(i == 0) ans = s;
		else {
			for(int j = 0; j < ans.length(); j++) {
				if(ans[j] != s[j]) {
					ans = s.substr(0, j);
					break;
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	if(ans.length() == 0) cout << "nai" << endl;
	else cout << ans << endl;
	return 0;
}