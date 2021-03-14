#include <iostream>
using namespace std;
int main() {
	int n, minMG = 101, maxFG = -1, flag = 1; 
	string minMn, minMcid, maxFn, maxFcid;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string name, gender, classid;
		int grade;
		cin >> name >> gender >> classid >> grade;
		if(gender == "F" && grade > maxFG) {
			maxFG = grade;
			maxFn = name;
			maxFcid = classid;
		} else if(gender == "M" && grade < minMG) {
			minMG = grade;
			minMn = name;
			minMcid = classid;
		}
	}
	if(maxFG == -1) {
		flag = 0;
		cout << "Absent" << endl;
	} else cout << maxFn << " " << maxFcid << endl;
	if(minMG == 101) {
		flag = 0;
		cout << "Absent" << endl;
	} else cout << minMn << " " << minMcid << endl;
	if(flag == 0) cout << "NA" << endl;
	else cout << maxFG - minMG << endl;
	return 0;
}