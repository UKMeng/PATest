#include <iostream>
#include <algorithm>
using namespace std;
double last_gas = 0.0;
double total_cost = 0.0;
struct node
{
    double price;
    double dis;
    double dismax;
}gastation[510];

bool cmp(node a, node b)
{
    return a.dis < b.dis;
}

double cal(double a, double b)
{
    if (a >= b)
    {
        return a - b;
    }
    else
    {
        return 0.0;
    }
}

int main()
{
    int cap, num_gs;
    double total_d, apug;
    cin >> cap >> total_d >> apug >> num_gs;
    double capmaxdis = cap * apug;
    for(int i = 0; i < num_gs; i++)
    {
        cin >> gastation[i].price >> gastation[i].dis;
        gastation[i].dismax = gastation[i].dis + capmaxdis;
    }
    gastation[num_gs].price = 0.0;     // 把终点站也添加进去方便算法
    gastation[num_gs].dis = total_d;
    gastation[num_gs].dismax = 0.0;
    sort(gastation, gastation + (num_gs + 1), cmp);
    int nextid = 0;
    if(gastation[0].dis != 0)
        printf("The maximum travel distance = 0.00");
    else if(gastation[num_gs - 1].dismax < total_d)
    {
        printf("The maximum travel distance = %.2f", gastation[num_gs - 1].dismax);
    }
    else
    {
        for(int i = 0; i < num_gs + 1; i++)
        {
            if(nextid != i) continue;
            double minprice = 100.0;
            bool flag = false;
            for(int j = i + 1; j < num_gs + 1; j++)
            {
                if(gastation[j].dis <= gastation[i].dismax)
                {
                    if(gastation[j].price <= gastation[i].price)
                    {
                        nextid = j;
                        double need_gas = (gastation[j].dis - gastation[i].dis) / apug;
                        total_cost += gastation[i].price * cal(need_gas, last_gas);
                        last_gas = 0.0;
                        // printf("%d %d %.2f\n", i, nextid, total_cost);
                        flag = true;
                        break;
                    }
                    if(gastation[j].price < minprice)
                    {
                        minprice = gastation[j].price;
                        nextid = j;
                    }
                    else if(gastation[j].price == minprice)
                    {
                        if(gastation[j].price >= gastation[i].price)
                        {
                            nextid = j;
                        }
                    }
                }
                else break;
            }
            if(flag == false)
            {
                total_cost += gastation[i].price * cal(50.0, last_gas);
                last_gas = 50.0 - (gastation[nextid].dis - gastation[i].dis) / apug;
                // printf("%d %d %.2f\n", i, nextid, total_cost);
            }
        }
        printf("%.2f", total_cost);
    }
    return 0;
}