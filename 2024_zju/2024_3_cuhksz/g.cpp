#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)
 
void err() {
    cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
constexpr int Max=1e18;
void solve(){
    int n;cin>>n;
    vector<array<int,2>>q(n+1);
    vector tr(2,vector<int>(n+1));
    vector<int>p;
    for(int i=1;i<=n;i++){
        int t,x;cin>>t>>x;
        q[i]={t,x};
        if(t==1)p.push_back(x);
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    auto get = [&](int x)->int{
        return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
    };
    auto add = [&](int x,int val)->void{
        while(x<=n){
            tr[0][x]++;
            tr[1][x]+=val;
            x+=lowbit(x);
        }
    };
    auto ask = [&](int x)->pair<int,int>{
        int cnt=0;
        int sum=0;
        while(x){
            cnt+=tr[0][x];
            sum+=tr[1][x];
            x-=lowbit(x);
        }
        return {cnt,sum};
    };
    int num=0;
    auto check = [&](int cnt,int x)->bool{
        int tot=cnt*x;
        int now=upper_bound(p.begin(),p.end(),cnt)-p.begin();
        auto [c,s]=ask(now);
        int live=num-c;
        int res=live*cnt+s;
        return res>=tot;
    };
    int ss=0;
    for(int i=1;i<=n;i++){
        auto [t,x]=q[i];
        if(t==1){
            add(get(x),x);
            num++;
            ss+=x;
        }else{
            int l=0,r=(ss+x-1)/x;
            int ans=0;
            while(l<=r){
                int mid=(l+r)>>1;
                if(check(mid,x)){
                    ans=mid;
                    l=mid+1;
                }else r=mid-1;
            }
            cout<<ans<<'\n';
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}