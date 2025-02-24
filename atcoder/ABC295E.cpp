#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++){
		if (A[i] == 0){
			cnt++;
		}
	}
	int mx = max(M, cnt);
	vector<long long> inv(mx + 1);
	inv[1] = 1;
	for (int i = 2; i <= mx; i++){
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
	}
	vector<long long> fact(cnt + 1), finv(cnt + 1);
	fact[0] = 1;
	finv[0] = 1;
	for (int i = 1; i <= cnt; i++){//预处理阶乘和逆元
		fact[i] = fact[i - 1] * i % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
	long long ans = 0;
	for (int i = 1; i <= M; i++){
		int cnt1 = 0;
		for (int j = 0; j < N; j++){
			if (A[j] >= i){//统计大于这个数的个数
				cnt1++;
			}
		}
		long long p = (M + 1 - i) * inv[M] % MOD;//选大于等于i的概率
		long long q = (i - 1) * inv[M] % MOD;//选小于i的概率
		vector<long long> POWp(cnt + 1), POWq(cnt + 1);
		POWp[0] = 1;
		POWq[0] = 1;
		for (int j = 0; j < cnt; j++){//计算出选这个的概率
			POWp[j + 1] = POWp[j] * p % MOD;
			POWq[j + 1] = POWq[j] * q % MOD;
		}
		for (int j = 0; j <= cnt; j++){
			if (cnt1 + j >= N + 1 - K){//如果选j个已经大于等于k的位置
				ans += fact[cnt] * finv[j] % MOD * finv[cnt - j] % MOD * POWp[j] % MOD * POWq[cnt - j] % MOD;
				ans %= MOD;
			}
		}
	}
	cout << ans << endl;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=2005;
int a[maxn],inv[maxn],f[maxn],finv[maxn];
int sum[maxn];
void init(){
	inv[1]=1;
	for(int i=2;i<maxn;i++){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	}
	f[0]=1,finv[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		sum[a[i]]++;
		if(!a[i])cnt++;
	}
	for(int i=maxn-2;i>=1;i--)sum[i]+=sum[i+1];
	int ans=0;
	for(int i=1;i<=m;i++){
		int c=sum[i];
		int p=(m-i+1)*inv[m]%mod;
		int q=(i-1)*inv[m]%mod;
		vector<int>pp(cnt+1),qq(cnt+1);
		pp[0]=1,qq[0]=1;
		for(int i=1;i<=cnt;i++){
			pp[i]=pp[i-1]*p%mod;
			qq[i]=qq[i-1]*q%mod;
		}
		for(int j=0;j<=cnt;j++){
			if(j+c>=n-k+1){
				ans+=f[cnt]*finv[j]%mod*finv[cnt-j]%mod*pp[j]%mod*qq[cnt-j]%mod;
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
*/
