#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;

vector<int> post, in;
unordered_map<int, int> pos;
int parents[1010], lc[1010], rc[1010], height[1010];
bool is_full = true;
struct Node{
    Node* left;
    Node* right;
    int val;
};

Node* create(int pl, int pr, int il, int ir){
    if(pl > pr) return nullptr;
    Node* root = new Node();
    root->val = post[pr];
    int in_pos = pos[root->val];
    int rlen = ir - in_pos;
    root->left = create(pl, pr-rlen-1, il, in_pos-1);
    root->right = create(pr-rlen, pr-1, in_pos+1, ir);
    return root;
}

void dfs(Node* root, int h, int p){
    int val = root->val;
    parents[val] = p;
    height[val] = h;
    bool fl = false, fr = false;
    if(root->left != nullptr){
        lc[val] = root->left->val;
        dfs(root->left, h+1, val);
        fl = true;
    } else{
        lc[val] = -1;
    }
    if(root->right != nullptr){
        rc[val] = root->right->val;
        dfs(root->right, h+1, val);
        fr = true;
    } else{
        rc[val] = -1;
    }
    if((fl || fr) && !(fl && fr)) is_full = false;
}

int main(){
    int n;
    cin >> n;
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++){cin >> post[i];}
    for(int i = 0; i < n; i++){
        cin >> in[i];
        pos[in[i]] = i;
    }
    Node* root = create(0, n-1, 0, n-1);
    dfs(root, 1, -1);
    int k;
    cin >> k;
    getchar();
    for(int i = 0; i < k; i++){
        string q;
        getline(cin, q);
        if(q.find("root") < q.size()){ // 15 is the root
            int test;
            for(int j = 0; j < q.size(); j++){ 
                if(!isdigit(q[j])){
                    test = stoi(q.substr(0, j));
                    break;
                }
            }
            if(root->val == test) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if(q.substr(q.size()-4, 4) == "ings") { // 8 and 2 are siblings  
            int t1, t2;
            int count = 0;
            for(count; count < q.size(); count++){
                if(!isdigit(q[count])) break;
            }
            t1 = stoi(q.substr(0, count));
            count += 5;
            int start = count;
            for(count; count < q.size(); count++){
                if(!isdigit(q[count])) break;
            }
            t2 = stoi(q.substr(start, count - start));
            if(parents[t1] == parents[t2]) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if(q == "It is a full tree") {
            if(is_full) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if(q.substr(q.size()-4, 4) == "evel") {  // 7 and 11 are on the same level
            int t1, t2;
            int count = 0;
            for(count; count < q.size(); count++){
                if(!isdigit(q[count])) break;
            }
            t1 = stoi(q.substr(0, count));
            count += 5;
            int start = count;
            for(count; count < q.size(); count++){
                if(!isdigit(q[count])) break;
            }
            t2 = stoi(q.substr(start, count - start));
            if(height[t1] == height[t2]) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if(q.find("parent") < q.size()){
            int t1, t2;
            int count = 0;
            for(count; count < q.size(); count++){
                if(!isdigit(q[count])) break;
            }
            t1 = stoi(q.substr(0, count));
            count = q.size()-1;
            for(count; count >= 0; count--){
                if(!isdigit(q[count])) break;
            }
            t2 = stoi(q.substr(count+1, q.size()-count-1));
            if(parents[t2] == t1) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if(q.find("left") < q.size()){
            int t1, t2;
            int count = 0;
            for(count; count < q.size(); count++){
                if(!isdigit(q[count])) break;
            }
            t1 = stoi(q.substr(0, count));
            count = q.size()-1;
            for(count; count >= 0; count--){
                if(!isdigit(q[count])) break;
            }
            t2 = stoi(q.substr(count+1, q.size()-count-1));
            if(lc[t2] == t1) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if(q.find("right") < q.size()){
            int t1, t2;
            int count = 0;
            for(count; count < q.size(); count++){
                if(!isdigit(q[count])) break;
            }
            t1 = stoi(q.substr(0, count));
            count = q.size()-1;
            for(count; count >= 0; count--){
                if(!isdigit(q[count])) break;
            }
            t2 = stoi(q.substr(count+1, q.size()-count-1));
            if(rc[t2] == t1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}