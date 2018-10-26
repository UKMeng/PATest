#include <iostream>
using namespace std;
struct stu
{
	char name[11],cid[11];
	char gender;
	int score;
}worstm,bestg,temp;
bool wo(stu a,stu b)//如果a成绩比b差，则返回1
{
	return a.score<b.score;
}
bool be(stu a,stu b)//如果a成绩比b好，则返回1
{
	return a.score>b.score;
}
void init()
{
	worstm.score = 101;
	bestg.score=-1;
}
int main()
{
	init();
	int k;
	scanf("%d",&k);
	for(int i;i<k;i++)
	{
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.cid,&temp.score);
		if(temp.gender=='M')
		{
			if(wo(temp,worstm))
				worstm=temp;
		}
		else 
		{
			if(be(temp,bestg))
				bestg=temp;
		}
	}
	if(bestg.score==-1)
		cout<<"Absent"<<endl;
	else cout<<bestg.name<<" "<<bestg.cid<<endl;
	if(worstm.score==101)
		cout<<"Absent"<<endl;
	else cout<<worstm.name<<" "<<worstm.cid<<endl;
	if(bestg.score==-1||worstm.score==101)
		cout<<"NA"<<endl;
	else cout<<bestg.score-worstm.score<<endl;
	return 0;
}