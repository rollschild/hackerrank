#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> array(200);
    int carry = 0;
    array[0] = 1;
    int k = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j ) {
            array[j] = array[j] * i + carry;
            carry = array[j] / 10;
            array[j] = array[j] % 10;
            // carry = array[j] / 10;
        }
        while(carry) {
            ++k;
            array[k] = carry % 10;
            carry /= 10;
        }
    }
    for(int i = k; i >= 0; --i) {
        cout << array[i];
    }
    cout << endl;
    return 0;
}

