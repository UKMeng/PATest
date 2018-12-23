#include <iostream>
using namespace std;

int main()
{
    int hashtable[1000] = {0};
    int num;
    scanf("%d", & num);
    for(int i = 0; i < num; i++)
    {
        int id, member, score;
        scanf("%d-%d %d", & id, &member, &score);
        hashtable[id-1] += score;
    }
    int max_id, max_score = 0;
    for(int i = 0; i < 1000; i++)
    {
        if (hashtable[i] > max_score)
        {
            max_id = i + 1;
            max_score = hashtable[i];
        }
    }
    cout << max_id << " " << max_score;
    return 0;
}
