#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int a,b,c,m;cin>>a>>b>>c>>m;
	vector<vector<vector<int>>> g(a+5,vector<vector<int>>(b+5,vector<int>(c+5)));
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			for(int k=1;k<=c;k++)cin>>g[i][j][k];
		}
	}
	vector<array<int,7>>q(m+1);
	for(int i=1;i<=m;i++){
		for(int j=0;j<7;j++)cin>>q[i][j];
	}
	auto check = [&](int t)->bool{
		vector<vector<vector<int>>> cnt(a+5,vector<vector<int>>(b+5,vector<int>(c+5)));
		for(int i=1;i<=t;i++){
			auto [lx,rx,ly,ry,lz,rz,h]=q[i];
			cnt[lx][ly][lz]+=h;
			cnt[rx+1][ly][lz]-=h;
			cnt[lx][ry+1][lz]-=h;
			cnt[rx+1][ry+1][lz]+=h;
			cnt[lx][ly][rz+1]-=h;
			cnt[rx+1][ly][rz+1]+=h;
			cnt[lx][ry+1][rz+1]+=h;
			cnt[rx+1][ry+1][rz+1]-=h;
		}
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				for(int k=1;k<=c;k++){
					cnt[i][j][k]+=cnt[i-1][j][k]+cnt[i][j-1][k]+cnt[i][j][k-1]-cnt[i-1][j-1][k]-cnt[i-1][j][k-1]-cnt[i][j-1][k-1]+cnt[i-1][j-1][k-1];
					if(cnt[i][j][k]>=g[i][j][k])return true;
				}
			}
		}
		return false;
	};
	int l=1,r=m;
	int ans=m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
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
