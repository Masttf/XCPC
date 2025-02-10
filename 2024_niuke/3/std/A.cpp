#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500007;
int n,L,R,k;
int a[N];
signed main(){
    cin>>n>>L>>R; k=(n-L-1)/(R-L);
    int sum=0;
    for (int i=1;i<=n;++i) cin>>a[i], a[i]=(a[i]-1)/2, sum+=min(a[i],k);
    if (sum>=k*L) cout<<"Yes";
    else cout<<"No";
    return 0;
}
