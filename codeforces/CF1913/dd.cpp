#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
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
void solve(){
    int n;cin>>n;
    vector<int>a(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    a[n+1]=INT_MAX;
    vector<int>dp(n+2);
    //定义dp i 为以ai结尾的方案数
    //考虑转移 那么只要考虑倒二个数
    //如果 ai 是最小值自己本身可以是一个方案
    // j aj>ai 向左遍历 都可以都可以操作 j+1,i这个区间让j变成倒二个数
    // ak < ai 都可以操作k+1,i-1这个区间让ak变成到二个数
    vector<int>s(n+2);
    vector<int>stk(1,0);
    int sum=0;
    for(int i=1;i<=n+1;i++){
        while(a[stk.back()]>a[i]){
            sum-=dp[stk.back()];
            sum=(sum%mod+mod)%mod;
            stk.pop_back();
        }
        dp[i]=sum+s[i-1]-s[stk.back()]+(stk.size()==1);
        dp[i]=(dp[i]%mod+mod)%mod;
        s[i]=(s[i-1]+dp[i])%mod;
        stk.push_back(i);
        sum+=dp[i];
        if(sum>=mod)sum-=mod;
    }
    cout<<dp[n+1]<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
} 