#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int n, int k, vector < int > c){
    // Complete this function
    long long cost = 0;
    int ave = 0;
    int rem = 0;
    int sum = 0;
    int temp = 0;
    if(n < k) {
        k = n;
    }
    if(n > k) {
        ave = n / k;
        rem = n % k;
    }
    else {
        ave = n / k;
    }
    
    sort(c.begin(), c.end());
    
    for(int i = 1; i <= k; ++i) {
        if(i == 1 && rem > 0) {
            int x = 0;
            sum = ave + rem;
            temp = sum;
            while(x < sum) {
                cost += c[--temp] * (x + 1);
                // c[temp] = 0;
                // --temp;
                ++x;
            }
            
        }
        else {
            int y = 0;
            sum += ave;
            temp = sum;
            while(y < ave) {
                cost += c[--temp] * (y + 1);
                // c[temp] = 0;
                // --temp;
                ++y;
            }
        }
    }
    return cost;
}   

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int minimumCost = getMinimumCost(n, k, c);
    cout << minimumCost << endl;
    return 0;
}

