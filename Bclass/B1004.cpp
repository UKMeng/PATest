#include <iostream>
#include <cstring>
using namespace std;
struct stu
{
	string name;
	string classid;
	int score;
}stu[10000];
int main()
{
	int num,max,maxid,min,minid;
	max=-1,min=101;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>stu[i].name>>stu[i].classid>>stu[i].score;
		if(stu[i].score>max)
		{
			max=stu[i].score;
			maxid=i;
		}
		if(stu[i].score<min)
		{
			min=stu[i].score;
			minid=i;
		}
	}
	cout<<stu[maxid].name<<" "<<stu[maxid].classid<<endl;
	cout<<stu[minid].name<<" "<<stu[minid].classid<<endl;
	return 0;
}