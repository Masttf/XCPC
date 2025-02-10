#include<bits/stdc++.h>
#define int long long
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
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	vector<int>cnt(64);
	vector<int>p;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[i]=x;
		for(int j=60;j>=0;j--){
			if(x>>j&1)cnt[j]++;
		}
	}
	for(int i=60;i>=0;i--){
		if(cnt[i]==n)p.push_back(i);
	}
	for(int _=1;_<=q;_++){
		int k;cin>>k;
		int ans=0;
		vector<int>cct=cnt;
		vector<int>aa=a;
		for(int i=60;i>=0;i--){
			if(cct[i]==n)ans+=1ll<<i;
			else{
				int sum=0;
				for(int j=1;j<=n;j++){
					if(aa[j]>>i&1)sum+=1ll<<i;
					else{
						sum+=aa[j]&((1ll<<i)-1);
					}
				}
				__int128 te=n;
				__int128 tot=te*(1ll<<i)-sum;
				if(k>=tot){
					ans+=1ll<<i;
					k-=tot;
					for(int j=1;j<=n;j++){
						if(aa[j]>>i&1)continue;
						for(int k=0;k<i;k++){
							if(aa[j]>>k&1)cct[k]--;
						}
						aa[j]=0;
					}
				}
			}
		}
		cout<<ans<<'\n';
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