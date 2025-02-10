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
void solve(){
	int a,b,c;cin>>a>>b>>c;
	vector<int>vx(65),vy(65);
	for(int i=0;i<=60;i++){
		if(c>>i&1){
			if(a>=b){
				vx[i]=1;
				a--;
			}else{
				vy[i]=1;
				b--;
			}
		}
	}
	if(a!=b){
		cout<<-1<<'\n';
		return ;
	}
	int x=0,y=0;
	for(int i=0;i<=60;i++){
		if(vx[i])x+=(1ll<<i);
		if(vy[i])y+=(1ll<<i);
	}
	for(int i=0;i<60;i++){
		if(!a)break;
		if(!vx[i]&&!vy[i]){
			x+=(1ll<<i);
			y+=(1ll<<i);
			a--;
			b--;
		}
	}
	if(a||b){
		cout<<-1<<'\n';
		return ;
	}
	cout<<x<<' '<<y<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}