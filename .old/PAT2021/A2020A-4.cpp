#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// DFS Djisktra TopologicalOrder

int N, M;
int score[1005][1005];
int voucher[1005][1005];
int inDegree[1005];
vector<int> adj[1005]; // 邻接表
unordered_set<int> zero_degree;

bool topological_order(){
    queue<int> q;
    int count = 0;
    for(int num:zero_degree) {
        q.push(num);
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        count++;
        for(int vertex: adj[t]){
            inDegree[vertex]--;
            if(inDegree[vertex] == 0){
                q.push(vertex);
            }
        }
    }    
    return count == N;
}

void not_consistent(vector<int> query, int K){
    for(int i = 0; i < K; i++){
        if(zero_degree.find(query[i]) != zero_degree.end()){
            printf("You may take test %d directly.",query[i]);
        } else{
            printf("Error.");
        }
        if(i < K-1) printf("\n");
    }
}

int dis[1005];
int money[1005];
bool visited[1005];
int pre[1005]; // 用于存储最佳路径节点的前置节点

void Dijsktra(int start){
    fill(dis, dis+1005, 0x7fffffff);
    dis[start] = 0;
    for(int i = 0; i < N+1; i++){
        int min_dis = 0x7fffffff;
        int min_v = -1;
        for(int j = 0; j < N+1; j++){
            if(!visited[j] && dis[j] < min_dis){
                min_v = j;
                min_dis = dis[j];
            }
        }
        if(min_v == -1) return;
        visited[min_v] = true;
        for(int j = 0; j < adj[min_v].size(); j++){
            int v = adj[min_v][j];
            if(!visited[v]){
                if(dis[v] > dis[min_v] + score[min_v][v]){
                    dis[v] = dis[min_v] + score[min_v][v];
                    money[v] = money[min_v] + voucher[min_v][v];
                    pre[v] = min_v;
                } else if(dis[v] == dis[min_v] + score[min_v][v] && money[v] < money[min_v] + voucher[min_v][v]){
                    money[v] = money[min_v] + voucher[min_v][v];
                    pre[v] = min_v;
                }
            }
        }
    }
}

void DFS(int end){
    if(pre[end] == N){
        printf("%d", end);
        return;
    }
    DFS(pre[end]);
    printf("->%d", end);
}

void consistent(vector<int> query, int K){
    Dijsktra(N);
    for(int i = 0; i < K; i++){
        if(zero_degree.find(query[i]) != zero_degree.end()){
            printf("You may take test %d directly.",query[i]);
        } else{
            DFS(query[i]);
        }
        if(i < K-1) printf("\n");
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        scanf("%d %d", &score[a][b], &voucher[a][b]);
        inDegree[b]++;
        adj[a].push_back(b);
    }
    for(int i = 0; i < N; i++){
        if(inDegree[i] == 0){
            adj[N].push_back(i);    // 对于多起点，增加一个共同的起点，从而只需要执行一次Dijsktra；
            zero_degree.insert(i);
        }
    }
    int K;
    scanf("%d", &K);
    vector<int> query(K);
    for(int i = 0; i < K; i++){
        scanf("%d", &query[i]);
    }
    bool isOK = topological_order();
    if(isOK){
        printf("Okay.\n");
        consistent(query, K);
    } else{
        printf("Impossible.\n");
        not_consistent(query, K);
    }                                                                                                                                
    return 0;
}