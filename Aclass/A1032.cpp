#include <iostream>
using namespace std;
const int maxn = 100010;
int ne[maxn], table[maxn];
char alpha[maxn];
bool flag[maxn];
int main() {
  int first1, first2, n, temp, pos1, pos2;
  scanf("%d %d %d", &first1, &first2, &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    scanf("%s %d", &alpha[temp], &ne[temp]);
  }
  for(int i = first1; i != -1; i = ne[i]) flag[i] = true;
  for(int i = first2; i != -1; i = ne[i]) {
      if(flag[i] == true) {
        printf("%05d", i); 
        return 0;
      }
  }
  printf("-1");
  return 0;
}