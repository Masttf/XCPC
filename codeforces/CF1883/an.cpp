#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<set>
using namespace std;

int solve(multiset<int>a,multiset<int>b,int k){
    a.insert(k);
    int n = a.size();
    int ans = 0,curr = 0;
    for(int i = 0; i < n; i++){
        while(!b.empty() and (*b.begin()) <= (*a.begin())){
            b.erase(b.begin());
        }
        
        if(b.empty())break;
        b.erase(b.begin());
        ans++;
        a.erase(a.begin());
    }
    return n - ans;
}

int main(){
    int tt;cin >> tt;
    while(tt--){
        int n,m;cin >> n >> m;
        multiset<int>a,b;
        for(int i = 0; i < n - 1; i++){
            int k;cin >> k;
            a.insert(k);
        }
        for(int j = 0; j < n; j++){
            int k;cin >> k;
            b.insert(k);
        }
        int x = solve(a,b,1);
        int lo = 1,hi = m,ans = m + 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(solve(a,b,mid) > x){
                hi = mid - 1;
                ans = mid;
            }
            else lo = mid + 1;
        }
        cout << x*1ll*m + (m - ans + 1) << endl;
    }
}
