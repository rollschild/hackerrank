#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

bool check(map<char, long> dict, int m) {
    if(dict['A'] <= m && dict['G'] <= m && dict['C'] <= m && dict['T'] <= m) {
        return true;
    }
    else return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long n = 0;
    long m = 0;
    cin >> n;
    m = n/4;
    // long p_least = 0;
    map<char, long> dict;
    string s = "";
	
    for(long i = 0; i < n; ++i) {
        char temp;
        cin >> temp;
        s += temp;
        dict[temp]++;
    }
	// double pointer technique
	long j = 0;
	long l = n;
	for(long i = 0; i < n; ++i) {
        // j = i;
		while( j < n && !check(dict, m)) {
			dict[s[j]]--;
			++j;
		}
		if(check(dict, m)) {
			l = min(l, j - i);	
		}
        dict[s[i]]++;
	}
	cout << l << endl;
    
    return 0;
}
