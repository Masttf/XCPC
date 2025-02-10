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
	int n,m,k;cin>>n>>m>>k;
	vector g(n,vector<int>(m));
	int x=0,y=0,d=0;
	for(int i=1;i<=k;i++){
		if(g[x][y]==0){
			d+=1;
			d%=4;
			g[x][y]=1;
			if(d==0){
				x--;
			}else if(d==1){
				y++;
			}else if(d==2){
				x++;
			}else y--;
			x+=n;
			x%=n;
			y+=m;
			y%=m;
		}else{
			d+=3;
			d%=4;
			g[x][y]=0;
			if(d==0){
				x--;
			}else if(d==1){
				y++;
			}else if(d==2){
				x++;
			}else y--;
			x+=n;
			x%=n;
			y+=m;
			y%=m;
		}
		//dbg(x,y,i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]==0)cout<<'.';
			else cout<<'#';
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