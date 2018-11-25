#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int price[24];
int m_day = 0;
struct Bill
{
	char name[30];
	int month,dd,hh,mm;
	bool status;
}bill[1010];

bool cmp(Bill a, Bill b)
{
	int s = strcmp(a.name, b.name);
	if (s != 0) return s < 0;
	else if (a.month != b.month) return a.month < b.month;
	else if (a.dd != b.dd) return a.dd < b.dd;
	else if (a.hh != b.hh) return a.hh < b.hh;
	else if (a.mm != b.mm) return a.mm < b.mm;
}

void time_out(Bill x)
{
	if (x.dd < 10) cout << "0" << x.dd << ":";
	else cout << x.dd << ":";
	if (x.hh < 10) cout << "0" << x.hh << ":";
	else cout << x.hh << ":";
	if (x.mm < 10) cout << "0" << x.mm << " ";
	else cout << x.mm << " ";
}
void record_out(Bill a, Bill b, int time, int money)
{
	time_out(a);
	time_out(b);
	cout << time << " " << "$" << money/100 << ".";	
	if(money%100 == 0)
		cout <<	"00" << endl;
	else if (money%100 < 10)
		cout << "0" << money%100 << endl;
	else cout << money%100 <<endl;
}

void total_out(int total)
{
	cout << "Total amount: $" << total/100 << ".";
	if(total%100 == 0)
		cout <<	"00" << endl;
	else if (total%100 < 10)
		cout << "0" << total%100 << endl;
	else cout << total%100 <<endl;
}

int cal_t(Bill a, Bill b)
{
	return (b.dd * 24 * 60 + b.hh *60 + b.mm) - (a.dd * 24 * 60 + a.hh *60 + a.mm);
}

int cal_m(Bill a, Bill b)
{
	int m = 0;
	if(a.dd != b.dd)
	{
		if(b.dd - a.dd >1)
			m += (b.dd - a.dd - 1) * m_day;
		m += (60 - a.mm) * price[a.hh];
		for (int i = a.hh+1; i < 24; i++)
			m += 60 * price[i];
		for (int i = 0; i < b.hh; i++)
			m += 60 * price[i];
		m += b.mm * price[b.hh];

	}
	else if(a.hh != b.hh)
	{
		m += (60 - a.mm) * price[a.hh];
		for (int i = a.hh + 1; i < b.hh; i++)
			m += 60 * price[i];
		m += b.mm * price[b.hh];
	}
	else 
	{
		m += (b.mm - a.mm) * price[a.hh];
	}
	return m;
}

bool match(Bill a, Bill b)
{
	int s = strcmp (a.name, b.name);
	if (s == 0 && a.status == true && b.status == false) return true;
	else return false;
}

int main()
{
	for (int i = 0; i < 24; i++)
	{
		scanf("%d", &price[i]);
		m_day += 60 * price[i];
	}
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d:%d:%d:%d", bill[i].name, &bill[i].month, &bill[i].dd, &bill[i].hh, &bill[i].mm);
		char line[10];
		scanf("%s", line);
		if (strcmp(line, "on-line") == 0) bill[i].status = true;
		else bill[i].status = false;
	}
	sort(bill, bill + N, cmp);
	int bill_month = 0;
	string bill_name = bill[0].name;
	int total = 0;
	/*for (int i = 0; i < N; i++)
		cout << bill[i].name << " " << bill[i].month << ":" << bill[i].dd << ":" << bill[i].hh << ":" << bill[i].mm << bill[i].status<< endl;
	bool flag = match (bill[0],bill[1]);
	cout << flag;*/
	for (int i = 1; i < N; i++)
	{
		if(match(bill[i-1],bill[i]))
		{
			int time = cal_t(bill[i-1],bill[i]);
			int money = cal_m(bill[i-1],bill[i]);
			if (bill_name == bill[i].name)
			{
				if (bill_month == bill[i].month)
				{
					record_out(bill[i-1], bill[i], time, money);
					total += money;
				}
				else 
				{
					if (total != 0)
						total_out(total);
					total = 0;
					cout << bill[i].name << " ";
					bill_month = bill[i].month;
					if (bill_month < 10)
						cout << "0" << bill_month << endl;
					else cout << bill_month << endl;
					record_out(bill[i-1], bill[i], time, money);
					total += money;
				}
			}
			else
			{
				if (total != 0)
				    total_out(total);
				total = 0;
				bill_name = bill[i].name;
				bill_month = bill[i].month;
				cout << bill[i].name << " ";
				bill_month = bill[i].month;
				if (bill_month < 10)
					cout << "0" << bill_month << endl;
				else cout << bill_month << endl;
				record_out(bill[i-1], bill[i], time, money);
				total += money;
			}
		}
	}
	if (total != 0) total_out(total);
	return 0;
}