#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define dbg(x...) \
do{ \
    cout<<#x<<"->"; \
    err(x); \
}while(0)
void err(){
    cout<<endl;
}
template<class T,class...Ts>
void err(T arg,Ts...args){
    cout<<fixed<<setprecision(10)<<arg<<' ';
    err(args...);
}
const int mod=1e9+9;
int qmi(long long a,int b){
    long long res=1;
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
void solve(){
    int m,k;cin>>m>>k;
    vector<int>ans(k+1);
    vector<int>leaf(k+1);
    vector<int>cnt(k+1);
    cnt[0]=1;
    for(int i=1;i<=k;i++){
        cnt[i]=1+i*(m-1);
        //dbg(i,cnt[i]);
    }
    leaf[0]=0;
    for(int i=1;i<=k;i++){
        ans[i]=(ans[i-1]+1ll*m*(leaf[i-1]+1))%mod;
        leaf[i]=(1ll*leaf[i-1]*cnt[i-1]-leaf[i-1]+1ll*m*(leaf[i-1]+1))%mod*qmi(cnt[i],mod-2)%mod;
        //dbg(i,leaf[i],ans[i]);
        //dbg(qmi(cnt[i],mod-2));
    }
    cout<<ans[k]<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
/*
6 2
18

2 6
600000038

83 613210
424200026
*/
