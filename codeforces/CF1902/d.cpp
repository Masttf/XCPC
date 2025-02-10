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
	int n,q;cin>>n>>q;
	string s;cin>>s;
	s=' '+s;
	map<pair<int,int>,set<int>>m1;
	map<pair<int,int>,set<int>>m2;
	vector<pair<int,int>>a(n+1);
	vector<pair<int,int>>b(n+5);
	a[0]={0,0};
	b[n+1]={0,0};
	for(int i=1;i<=n;i++){
		a[i]=a[i-1];
		if(s[i]=='U')a[i].second++;
		else if(s[i]=='D')a[i].second--;
		else if(s[i]=='L')a[i].first--;
		else a[i].first++;
		//dbg(a[i].first,a[i].second);
		m1[a[i]].insert(i);
	}
	for(int i=n;i>=1;i--){
		b[i]=b[i+1];
		if(s[i]=='U')b[i].second++;
		else if(s[i]=='D')b[i].second--;
		else if(s[i]=='L')b[i].first--;
		else b[i].first++;
		//dbg(b[i].first,b[i].second);
		m2[b[i]].insert(i);
	}
	for(int _=1;_<=q;_++){
		int x,y,l,r;cin>>x>>y>>l>>r;
		if(x==0&&y==0){
			cout<<"Yes\n";
			continue;
		}
		if(x==a[n].first&&y==a[n].second){
			cout<<"Yes\n";
			continue;
		}
		if(m1.count({x,y})){
			set<int>&temp=m1[{x,y}];
			auto it=temp.lower_bound(r);
			if(it!=temp.end()){
				cout<<"Yes\n";
				continue;
			}
			it=temp.upper_bound(l-1);
			if(it!=temp.begin()){
				cout<<"Yes\n";
				continue;
			}
		}
		//dbg(l,r);
		int nx=a[l-1].first;
		int ny=a[l-1].second;
		int nnx=b[r+1].first;
		int nny=b[r+1].second;
		int tx=nnx-nx;
		int ty=nny-ny;
		//dbg(nx,ny,nnx,nny);
		//dbg(tx,ty);
		x+=tx;
		y+=ty;
		//dbg(x,y);
		if(m2.count({x,y})){
			set<int>&temp=m2[{x,y}];
			auto it=temp.lower_bound(l);
			if(it!=temp.end()&&*it<=r){
				cout<<"Yes\n";
				continue;
			}
		}
		cout<<"No\n";
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