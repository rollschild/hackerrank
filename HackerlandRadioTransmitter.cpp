#include<bits/stdc++.h>
using namespace std;

vector<int>v;
map<int, bool>mp;

int main() {
    v.clear();
    mp.clear();

    int n, k, x, low, center, cnt = 0, lft;

    cin>>n>>k;

    for(int i=0; i<n; i++)
    {
       cin>>x;
       if(mp[x] == 0)
         v.push_back(x);
       mp[x]= 1;
    }

    sort(v.begin(), v.end());

    n = v.size();
    lft = 0;
    while(lft < n)
    {
       x = v[lft]+k;
       low = lower_bound(v.begin(), v.end(), x) - v.begin();
       if(low >= n || v[low] > x)
        low--;
       center = v[low];

       x = center+k;
       low = lower_bound(v.begin(), v.end(), x) - v.begin();
       if(low >= n || v[low] > x)
        low--;

       lft = low+1;

       cnt++;
    }

    cout<<cnt<<endl;
    
    return 0;
}
