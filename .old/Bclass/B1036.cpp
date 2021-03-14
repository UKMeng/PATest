#include <iostream>
using namespace std;
int main()
{
	char c;
	int row,col;
	cin>>col>>c;
	row=col/2+col%2;
	for(int i=0;i<col;i++)
	{
		cout<<c;
	}
	cout<<endl;
	for(int i=0;i<row-2;i++)
	{
		cout<<c;
		for(int j=0;j<col-2;j++)
			cout<<" ";
		cout<<c<<endl;
	}
	for(int i=0;i<col;i++)
	{
		cout<<c;
	}
	cout<<endl;
	return 0;
}