#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q = 0; // queries
    int n = 0; // 2n = size
    cin >> q;
    int temp = 0;
    int maxValue = 0;
    int result = 0;
    for(int p = 0; p < q; ++p) {
        cin >> n;
        result = 0;
        vector<vector<int>> arr(2*n, vector<int>(2*n));
        for(int i = 0; i < 2 * n; ++i) {
            for(int j = 0; j < 2 * n; ++j) {
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            vector<int>::iterator maxIt = max_element(arr[i].begin(), arr[i].end());
            if(maxIt >= arr[i].begin() + n) {
                // max value in the other half of vector
                // need to reverse this vector
                for(int j = n; j < 2 * n; ++j) {
                // every column in the other half
                    vector<int> col(2*n);
                    for(int k = 0; k < 2*n ; ++k) {
                        col[k] = arr[k][j];
                    }
                    maxIt = max_element(col.begin(), col.end());
                    if(maxIt >= col.begin() + n) {
                        for(int l = 0; l < n; ++l) {
                            arr[l][j] = temp;
                            arr[l][j] = arr[2 * n - 1 - l][j];
                            arr[2 * n - 1 - l][j] = temp;
                        }
                    }
                
                }
                reverse(arr[i].begin(), arr[i].end());
            }
        }
        for(int m = 0; m < n; ++m) {
            for(int o = 0; o < n; ++o ) {
                result += arr[m][o];
            }
        }
        cout << result << endl;
    }
    
    return 0;
}

