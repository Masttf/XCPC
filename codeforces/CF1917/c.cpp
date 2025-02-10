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
	int n,k,d;cin>>n>>k>>d;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>b(k+1);
	for(int i=1;i<=k;i++)cin>>b[i];
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++){
		if(a[i]<=i)cnt[i-a[i]]++;
	}
	int ans=(d-1)/2+cnt[0];
	vector<int>temp=a;
	int last=cnt[0];
	for(int s=1;s<=10*n;s++){
		if(s>d-1)break;
		int i=s;
		if(i>k){
			i%=k;
			if(i==0)i=k;
		}
		for(int j=1;j<=b[i];j++){
			if(temp[j]==j)last--;
			temp[j]++;
			if(temp[j]==j)last++;
		}
		ans=max(ans,last+(d-(s+1))/2);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}