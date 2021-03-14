#include <iostream>    // 字符串
#include <cstring>
using namespace std;
int main() {
	string s;
	int n1, n2, N;
	cin >> s;
	N = s.length();
	for(n2 = 2; n2 <= N; n2++) {
		if((N + 2 - n2) % 2 == 0) {
			n1 = (N + 2 - n2) / 2;
			if(n1 <= n2) break;
		}
	}
	char ans[n1][n2];
	int cnt = 0;
	for(int i = 0; i < n1 - 1; i++) {
		for(int j = 0; j < n2 - 1; j++) {
			if(j == 0) {
				ans[i][j] = s[cnt++];
			} else ans[i][j] = ' ';
		}
	}
	for(int i = 0; i < n2; i++) ans[n1 - 1][i] = s[cnt++];
	for(int i = 0; i < n1 - 1; i++) ans[n1 - 2 - i][n2 - 1] = s[cnt++];
	for(int i = 0; i < n1; i++) {
		for(int j = 0; j < n2; j++) {
			printf("%c%s", ans[i][j], j == n2 - 1 ? "\n" : "");
		}
	}
	return 0;
}