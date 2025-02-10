#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve()
{
    int m,k,h;cin>>m>>k>>h;
    if(h<=m)return h;
    if(h==0)return 0;
    if(m==k)return m;
    int l=1,r=h,res=h;
    auto check = [&](int mid){
        if(mid<m)return mid;
        int res=mid;
        int t=(mid-m)/(m-k)+1;
        return mid+t*k;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)>=h){
            res=mid;r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;while(T--)cout<<solve()<<"\n";
    return 0;
}