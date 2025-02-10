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
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int mod=998244353;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>tr(n+1);
	vector<int>ans(n+1);
	auto add = [&](int x,int val)->void{
		int pre=k;
		x+=lowbit(x);
		int cnt=0;
		while(x<=n){
			tr[x]+=pre*val%mod;
			if(tr[x]>=mod)tr[x]-=mod;
			if(tr[x]<0)tr[x]+=mod;
			x+=lowbit(x);
			cnt++;
			pre=pre*(k+cnt)%mod*qmi(cnt+1,mod-2)%mod;
		}
	};
	for(int i=1;i<=n;i++){
		ans[i]=(a[i]-tr[i]+mod)%mod;
		add(i,ans[i]);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}