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
const int mod=1e9+7;
const int Max=1e18;
//要求每行异或值想等，每列异或值想等
//先考虑n最小的情况4
// 0 1
// 2 3
//又考虑一下为什么是4的倍数
//每四个都可以加到一个矩形
void solve(){
	int n;cin>>n;
	vector ans(n+1,vector<int>(n+1));
	int x=1,y=1;
	int nw=0;
	for(int i=1;i<=n*n/4;i++){
		
		ans[x][y]=nw++;
		ans[x+n/2][y]=nw++;
		ans[x][y+n/2]=nw++;
		ans[x+n/2][y+n/2]=nw++;
		y++;
		if(y>n/2){
			x++;
			y=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
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