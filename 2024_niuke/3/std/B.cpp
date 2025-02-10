#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=107;
int n,x;
int a[N];
signed main(){
    cin>>n>>x;
    int g=0;
    for (int i=0;i<n;++i) cin>>a[i], g=__gcd(a[i],g);
    sort(a,a+n); x%=g; 
    cout<<min(x,g-x);
}
