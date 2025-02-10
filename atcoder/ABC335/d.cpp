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
	int n;cin>>n;
	vector<vector<int>>ans(n+1,vector<int>(n+1));
	int now=n*n-1;
	int l=1,r=n,h=1,w=n;
	for(int i=1;i<=n/2;i++){
		//dbg(i,"Yes");
		for(int j=l;j<=r;j++){
			ans[i][j]=now--;
			//dbg(l,r,j);
		}
		for(int j=h+1;j<=w;j++){
			ans[j][n-i+1]=now--;
			//dbg(h+1,w,j,n-i+1);
		}
		for(int j=r-1;j>=l;j--)ans[n-i+1][j]=now--;
		for(int j=w-1;j>=h+1;j--)ans[j][i]=now--;
		l++;r--;
		h++;w--;
	}
	//dbg("yes");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==(n+1)/2&&j==(n+1)/2){
				cout<<'T'<<' ';
			}else cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}