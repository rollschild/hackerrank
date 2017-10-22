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
string winner = "";

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int round = 0;
        int n;
        cin >> n;
        // vector<int> vec(n);
        int temp = 0;
        int max = 0;
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            if(max < temp) {
                max = temp;
                ++round;
            }
        
        }
        if(round % 2 == 0) winner = "ANDY";
        else winner = "BOB";
        cout << winner << endl;
    }
    return 0;
}
