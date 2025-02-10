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
	cout<<6<<'\n';
	vector ans(10,vector<int>(n+1));
	auto color = [&](int i,vector<int>&a,vector<int>&b)->void{
		int num=1;
		for(auto x:a){
			ans[i][num++]=x;
		}
		for(auto x:b){
			ans[i][num++]=x;
		}
	};
	if(n%2==0){
		vector a(4,vector<int>());
		int block=n/2;
		for(int i=1;i<=2*n;i++){
			int num=(i-1)/block;
			a[num].push_back(i);
		}
		int cnt=1;
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				color(cnt++,a[i],a[j]);
			}
		}
	}else{
		vector a(4,vector<int>());
		int block=(n-3)/2;
		for(int i=7;i<=2*n;i++){
			int num=(i-1-6)/block;
			a[num].push_back(i);
		}
		int cnt=1;
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				color(cnt++,a[i],a[j]);
			}
		}
		ans[1][2*block+1]=1;
		ans[1][2*block+2]=2;
		ans[1][2*block+3]=3;
		ans[2][2*block+1]=1;
		ans[2][2*block+2]=4;
		ans[2][2*block+3]=5;
		ans[3][2*block+1]=1;
		ans[3][2*block+2]=3;
		ans[3][2*block+3]=6;
		ans[4][2*block+1]=2;
		ans[4][2*block+2]=4;
		ans[4][2*block+3]=6;
		ans[5][2*block+1]=2;
		ans[5][2*block+2]=5;
		ans[5][2*block+3]=6;
		ans[6][2*block+1]=3;
		ans[6][2*block+2]=4;
		ans[6][2*block+3]=5;
	}
	for(int i=1;i<=6;i++){
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