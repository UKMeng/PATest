#include <iostream>  // bug
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
    double price;
    double dis;
    double dismax;
}gstation[510];

bool cmp(node a, node b)
{
    return a.dis < b.dis;
}
int main()
{
    int cap, num_gs;
    double total_d, apug;
    cin >> cap >> total_d >> apug >> num_gs;
    double capmaxdis = cap * apug;
    for(int i = 0; i < num_gs; i++)
    {
        cin >> gstation[i].price >> gstation[i].dis;
        gstation[i].dismax = gstation[i].dis + capmaxdis;
    }
    sort(gstation, gstation + num_gs, cmp);
    double total_price = 0.0;
    int tempgasid = 0;
    if(gstation[num_gs - 1].dismax < total_d)
    {
        printf("The maximum travel distance = %.2f",gstation[num_gs - 1].dismax);
    }
    else
    {
        for(int i = 0; i < num_gs; i++)
        {
            double lastgas = 0.0;
            if (i != tempgasid) continue;
            if (gstation[i].dismax < total_d)
            {
                for(int j = i + 1; j < num_gs; j++)
                {
                    if(gstation[j].dis <= gstation[i].dismax)
                    {
                        double minpri = 100.0;
                        if(gstation[j].price < gstation[i].price)
                        {
                            tempgasid = j;
                            total_price += gstation[i].price * ((gstation[tempgasid].dis - gstation[i].dis) / apug);
                            printf("%d %d %.2f ", i, tempgasid, total_price);
                            break;
                        }
                        else
                        {
                            if(gstation[j].price < minpri)
                            {
                                minpri = gstation[j].price;
                                tempgasid = j;
                            }
                            else if(gstation[j].price == minpri)
                            {
                                if(gstation[j].price >= gstation[i].price)
                                {
                                    tempgasid = j;
                                }
                            }
                        }
                    }
                    else break;
                }
                printf("%d %d %.2f ", i, tempgasid, total_price);
            }
            else if(gstation[i].dismax >= total_d)
            {
                for(int j = i + 1; j < num_gs; j++)
                {
                    if(gstation[j].dis <= gstation[i].dismax)
                    {
                        if(gstation[j].price < gstation[i].price)
                        {
                            tempgasid = j;
                        }
                        else continue;
                    }
                    else break;
                }
                if(tempgasid != i)
                {
                    total_price += gstation[i].price * ((gstation[tempgasid].dis - gstation[i].dis) / apug);
                    printf("%d %d %.2f ", i, tempgasid, total_price);
                }
                else
                {
                    total_price += gstation[i].price * ((total_d - gstation[i].dis) / apug);
                    printf("%.2f", total_price);
                    break;
                }  
            }
        }
    }
    return 0;
}