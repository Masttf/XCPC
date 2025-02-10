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
	int n,m,x,y;cin>>n>>m>>x>>y;
	x--;y--;
	vector<string>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int p,q;cin>>p>>q;
	vector<pair<int,int>>query(q);
	for(int i=0;i<q;i++){
		cin>>query[i].first>>query[i].second;
		query[i].second--;
	}
	auto cgx = [&](int x)->void{
		char temp=a[x][m-1];
		for(int i=m-1;i>=1;i--){
			a[x][i]=a[x][i-1];
		}
		a[x][0]=temp;
	};
	auto cgy = [&](int x)->void{
		char temp=a[n-1][x];
		for(int i=n-1;i>=1;i--){
			a[i][x]=a[i-1][x];
		}
		a[0][x]=temp;
	};
	for(int j=1;j<=p;j++){
		for(int i=0;i<q;i++){
			if(query[i].first==1)cgx(query[i].second);
			else cgy(query[i].second);
			//for(int i=0;i<n;i++)cout<<a[i]<<'\n';
		}

		 
	}

	cout<<a[x][y]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
