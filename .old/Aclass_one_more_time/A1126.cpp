#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[501];
int count = 0;
bool visited[501] = {false};
void dfs(int index){
    count++;
    for(int i = 0; i < graph[index].size(); i++){
        if(!visited[graph[index][i]]) {
            visited[graph[index][i]] = true;
            dfs(graph[index][i]);
        }
    }
}

int main(){
    int num_vertice, num_edge;
    bool first = true;
    int odd = 0;
    cin >> num_vertice >> num_edge;
    for(int i = 0; i < num_edge; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 1; i <= num_vertice; i++){
        if(first) {
            cout << graph[i].size();
            first = false;
        } else cout << " " << graph[i].size();
        if(graph[i].size() % 2 != 0) odd++;
    }
    cout << endl;
    visited[1] = true;
    if(odd == 0) {
        dfs(1);
        if(count == num_vertice) cout << "Eulerian" << endl;
        else cout << "Non-Eulerian" << endl;
    } else if(odd == 2){
        dfs(1);
        if(count == num_vertice) cout << "Semi-Eulerian" << endl;
        else cout << "Non-Eulerian" << endl;
    } else cout << "Non-Eulerian" << endl;
    return 0;
}
