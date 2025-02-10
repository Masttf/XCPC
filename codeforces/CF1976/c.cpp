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
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+m+2),b(n+m+2);
    for(int i=1;i<=n+m+1;i++)cin>>a[i];
    for(int i=1;i<=n+m+1;i++)cin>>b[i];
    vector<int>pre(n+m+5),prea(n+m+5),preb(n+m+5);
    vector<int>cnt1(n+m+5),cnt2(n+m+5);
    for(int i=1;i<=n+m+1;i++){
        prea[i]=prea[i-1]+a[i];
        preb[i]=preb[i-1]+b[i];
        pre[i]=pre[i-1];
        cnt1[i]=cnt1[i-1];
        cnt2[i]=cnt2[i-1];
        if(a[i]>b[i]){
            cnt1[i]++;
            pre[i]+=a[i];
        }else cnt2[i]++,pre[i]+=b[i];
    }
    int sum=0;
    int ln=n;
    int lm=m;
    auto check = [&](int l,int r)->bool{
        if(cnt1[r]-cnt1[l]>ln)return false;
        if(cnt2[r]-cnt2[l]>lm)return false;
        return true;
    };
    for(int i=1;i<=n+m+1;i++){
        int l=i+1,r=n+m+1;
        int ans=i;
        while(l<=r){
            //dbg(i,l,r);
            int mid=(l+r)>>1;
            if(check(i,mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        //dbg(i,sum);
        // dbg(i,ans,sum);
        // dbg(cnt1[ans]-cnt1[i]);
        // dbg(cnt2[ans]-cnt2[i]);
        if(cnt1[ans]-cnt1[i]==ln){
            cout<<sum+pre[ans]-pre[i]+preb[n+m+1]-preb[ans]<<' ';
        }else cout<<sum+pre[ans]-pre[i]+prea[n+m+1]-prea[ans]<<' ';
        
        if(a[i]>b[i]){
            if(ln){
                ln--;
                sum+=a[i];
            }else{
                lm--;
                sum+=b[i];
            }
        }else{
            if(lm){
                lm--;
                sum+=b[i];
            }else{
                ln--;
                sum+=a[i];
            }
        }
    }
    cout<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}