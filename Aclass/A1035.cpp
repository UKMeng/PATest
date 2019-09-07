#include <iostream> // 字符串
#include <cstring>
#include <map>
#include <vector>
using namespace std;
map<string, string> password;
vector<string> ans;
int main() {
	int k;
	cin >> k;
	for(int i = 0; i < k; i++) {
		string id, str;
		bool flag = false;
		cin >> id >> str;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '1') {flag = true; str[i] = '@';}
			if(str[i] == '0') {flag = true; str[i] = '%';}
			if(str[i] == 'l') {flag = true; str[i] = 'L';}
			if(str[i] == 'O') {flag = true; str[i] = 'o';}
		}
		if(flag) {
				password[id] = str;
				ans.push_back(id);
		}
	}
	if(ans.size() == 0) {
		if(k == 1) cout << "There is 1 account and no account is modified" << endl;
		else cout << "There are " << k << " accounts and no account is modified" << endl;
	} else {
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " " << password[ans[i]] << endl;
	}
	return 0;
}