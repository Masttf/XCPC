#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max=1e18;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    int mi=Max;
    for(int i=1;i<=n;i++)cin>>a[i];
    auto check = [&](int x)->bool{
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]<x){
                sum+=x-a[i];
            }
        }
        return sum<=k;
    };
    for(int i=1;i<=n;i++){
        mi=min(mi,a[i]);
    }
    int ans=mi;
    int l=mi,r=mi+k;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
    }
    int res=(ans-1)*n+1;
    for(int i=1;i<=n;i++){
        if(a[i]<ans){
            k-=ans-a[i];
            a[i]=ans;
        }
        a[i]-=ans;
        if(a[i])res++;
    }
    res+=k;
    cout<<res<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}