// #include <cmath>
// #include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// int nodes = 0;
int n = 0;
int m = 0;;
std::vector< std::vector<bool> > visited; 
int IsConnected( unsigned int i, unsigned int j, vector< vector<int> >& vec) {
    int nodes = 0;
	visited[i][j] = true;
    if(vec.at(i).at(j) == 0) return nodes;
    ++nodes;
	if(i > 0 && j > 0) {
        nodes += (!visited[i-1][j-1] ? IsConnected(i - 1, j - 1, vec) : 0);
        if(i < n-1) {
            nodes += (!visited[i+1][j-1] ? IsConnected(i + 1, j - 1, vec) : 0); 
        }
        if(j < m-1) {
            nodes += (!visited[i-1][j+1] ? IsConnected(i - 1, j + 1, vec) : 0);
        }
    }
    if(i > 0) {
        nodes += (!visited[i-1][j] ? IsConnected(i - 1, j, vec) : 0);
    }
   	if(j > 0) {
        nodes += (!visited[i][j-1] ? IsConnected(i, j - 1, vec) : 0);
    }

    // to the right
    if(i < n-1 && n < m-1) {
        nodes += (!visited[i+1][j+1] ? IsConnected(i + 1, j + 1, vec) : 0);
    }
    if(i < n -1) {
		nodes += (!visited[i+1][j] ? IsConnected(i + 1, j, vec) : 0);
	}
    if(j < m -1) {
        nodes += (!visited[i][j+1] ? IsConnected(i, j + 1, vec) : 0);
    }
    return nodes;
}

void SetToZero(vector< vector<bool> >& visited, int n, int m) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			visited[i][j] = false;	
		}	
	}	
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> m;
    std::vector< std::vector<int> > vec(n, vector<int>(m, 0));
	visited.resize(n);
	for(int k = 0; k < n; ++k) {
		visited[k].resize(m);	
	}
	SetToZero(visited, n, m);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int temp = 0;
            cin >> temp;
            vec[i][j] = temp;
        }
    }
	cout << "before calling IsConnected()" << endl;	
	cout << IsConnected(2, 2, vec) << endl;
	cout << "after calling IsConnected()" << endl;
    int fakenodes = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
			SetToZero(visited, n, m);
			int nodes = 0;
            nodes = IsConnected(i, j, vec);
            fakenodes = max(nodes, fakenodes);
        }
    }
    cout << fakenodes << endl;
    return 0;
}

