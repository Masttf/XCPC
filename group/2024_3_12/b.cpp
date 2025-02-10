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
void solve(){
	int n;cin>>n;
	int a,b;cin>>a>>b;
	int ans=6;
	vector<int>temp(10);
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			if(i==j)continue;
			for(int k=1;k<=6;k++){
				if(k==i||k==j)temp[k]=b;
				else temp[k]=a;
			}
			int cnt=0;
			int last=0;
			for(int k=1;k<=6;k++){
				if(temp[k]>last){
					last=n;
					cnt++;
				}
				last-=temp[k];
			}
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}