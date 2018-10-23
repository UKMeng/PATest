#include <iostream>
#include <cstring>
using namespace std;
struct stu
{
	string id;
	int num;
}stu[1010];
int main()
{
	int N,sj;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string id_;
		int num_;
		cin>>id_>>sj>>num_;
		stu[sj].id=id_;
		stu[sj].num=num_;
	}
	int cha,M;
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>cha;
		cout<<stu[cha].id<<" "<<stu[cha].num<<endl;
	}
	return 0;
}