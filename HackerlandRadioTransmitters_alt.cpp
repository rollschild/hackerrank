#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n+1);
    for(int x_i = 1;x_i <= n;x_i++){
       cin >> x[x_i];
    }
    int result = 0;
    int i = 1;
    int j = 0;
    int md = 0;
    sort(x.begin(), x.end());
    while(i <= n) {
        md = x[i] + k;
        ++result;
        j = i;
        while(j <= n && x[j] <= md) {
            i = j;
            ++j;
        }
        j = i;
        md = x[i] + k;
        while(j <= n && x[j] <= md) {
            i = j;
            ++j;
        }
        ++i;
    }
    cout << result << endl;
    return 0;
}

