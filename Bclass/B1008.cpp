#include <iostream>
using namespace std;
int main() {
	int ans[100];
	int N, M;
	cin >> N >> M;
	int m = M % N;
	for(int i = 0;i < N; i++) {
		if(N - i > m)
			cin >> ans[i+m];
		else cin >> ans[m-N+i];	
	}
	cout << ans[0];
	for(int i = 1; i < N; i++) {
		cout <<" "<< ans[i];
	}
	return 0;
}