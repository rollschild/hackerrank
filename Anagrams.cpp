#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int cases;
  scanf("%d", &cases);
  getchar();
  while (cases--) {
    unordered_map<string, int> mp;
    string s;
    getline(cin, s);
    int n = s.size();
    for (int len = 1; len < n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        string t = s.substr(i, len);
        sort(t.begin(), t.end());
        mp[t]++;
      }
    }
    long long ans = 0;
    for (auto t : mp) {
      ans += (long long)t.second * (t.second - 1) / 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
