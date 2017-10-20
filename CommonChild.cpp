#include <bits/stdc++.h>

using namespace std;

int commonChild(string s1, string s2){
    // Complete this function
    unsigned long l1 = s1.length();
    unsigned long l2 = s2.length();
    vector<vector<int>> arr(l1, vector<int>(l2));
    // int arr[l1][l2] = {0};
    for(unsigned long i = 0; i < l1; ++i) {
        for(unsigned long j = 0; j < l2; ++j) {
            if(s2[j] == s1[i]) {
                    if(i == 0) ++arr[i][j];
                    else {
                        if(j == 0) {
                            arr[i][j] = min(0, arr[i-1][j]) + 1;
                        }
                        else {
                            arr[i][j] = arr[i-1][j-1] + 1;
                        }
                    }
            }
            else {
                if(j == 0) arr[i][j] = 0;
                else if(i == 0) 
                    arr[i][j] = arr[i][j-1];
                else
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    return arr[l1-1][l2-1];
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}
