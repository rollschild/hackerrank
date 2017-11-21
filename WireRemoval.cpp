#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> forest(100001);
vector<bool> occupied(100001);
vector<int> tree(100001);
int n = 0;
long long nodes = 0;
long long total_distance = 0;

void dfs(int root, int distance) {
    occupied[root] = 1;
    tree[root] = 1;
    for(auto i : forest[root]) {
        if(!occupied[i]) {
            dfs(i, distance + 1);
            tree[root] += tree[i];
            // dfs(i, distance + 1);
        }
    }
    if(root != 1) {
        nodes += distance * 1LL * (n - tree[root]);
        total_distance += distance;
    }
}

int main() {
    
    cin >> n;
    for(int a0 = 0; a0 < n-1; a0++){
        int x;
        int y;
        cin >> x >> y;
        forest[x].push_back(y);
        forest[y].push_back(x);
    }
    // Write Your Code Here
    dfs(1, 0);
    long double result = (long double)nodes / (long double)total_distance;
    cout << fixed << setprecision(10);
    cout << result << endl;
    return 0;
}

