#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void CountArray(vector<pair<int, string>> vec) {
    int sizeOfVec = vec.size();
    int array[sizeOfVec] = {0};
    for(int i = 0; i < sizeOfVec; ++i) {
        ++array[vec[i].first];
    }
    int oi;
    for(int i = 0; i < sizeOfVec; ++i) {
        oi = 0;
        while(array[i]--) {
            while(vec[oi].first != i) ++oi;
            cout << vec[oi].second << " ";
            ++oi;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    cin >> n;
    int x = 0;
    string s = "";
    vector<pair<int, string>> ss;
    for(int i = 0; i < n; ++i) {
        cin >> x >> s;
        if(i < n/2) ss.push_back(make_pair(x, "-"));
        else ss.push_back(make_pair(x, s));
    }
    CountArray(ss);
    return 0;
}

