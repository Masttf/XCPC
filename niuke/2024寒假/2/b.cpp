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
double dx[]={-0.5,0.5,0,0};
double dy[]={0,0,-0.5,0.5};
void solve(){
	int n,m,k;cin>>n>>m>>k;
	set<pair<double,double>>s;
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		for(int j=0;j<4;j++){
			double tx=x+dx[j];
			double ty=y+dy[j];
			s.insert({tx,ty});
		}
	}
	cout<<s.size()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}