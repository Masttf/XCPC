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
const int Max=1e18;
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	vector pre(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pre[i][j]=pre[i][j-1];
			if(a[i][j]=='*')pre[i][j]++;
		}
	}
	int ans=0;
	auto check = [&](int i,int j)->void{
		//dbg(i,j);
		int x=i,y=j;
		int l=j,r=j;
		l--,r++;i++;
		for(;i<=n&&l>=1&&r<=m;i++,l--,r++){
			if(a[i][l]=='*'&&a[i][r]=='*'){
				if(pre[i][r]-pre[i][l]==r-l){
					ans++;
					//if(x==40&&y==124)dbg(i,l,r);
				}
			}else break;
		}
	};
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){
				int temp=ans;
				check(i,j);
				int d=ans-temp;
				dbg(i,j,d);
				
				//cout<<i<<' '<<j<<' '<<d<<'\n';
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
