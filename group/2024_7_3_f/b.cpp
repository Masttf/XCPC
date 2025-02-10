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
	int n;cin>>n;
	vector val(n+1,vector<int>(n+1));
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='W')val[i+1][j+1]=0;
			else val[i+1][j+1]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			val[i][j]+=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
		}
	}
	auto get = [&](int x1,int y1,int x2,int y2)->int{
		return val[x2][y2]-val[x1-1][y2]-val[x2][y1-1]+val[x1-1][y1-1];
	};
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int p=i;p<=n;p++){
				for(int q=j;q<=n;q++){
					if(get(i,j,p,q)==0)ans++;
				}
			}
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