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
	int n;cin>>n;
	vector<int>a(n+5);
	for(int i=1;i<=n;i++)cin>>a[i];
	map<int,int>p;
	map<int,int>s;
	int tot=n;
	a[0]=Max;
	a[n+1]=Max+1;
	s[a[0]]=a[1];
	for(int i=1;i<=n;i++){
		p[a[i]]=a[i-1];
		s[a[i]]=a[i+1];
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int x,y;cin>>x>>y;
			int ss=s[x];
			s[x]=y;
			p[ss]=y;
			p[y]=x;
			s[y]=ss;
		}else{
			int x;cin>>x;
			int pp=p[x];
			int ss=s[x];
			s[pp]=ss;
			p[ss]=pp;
		}
	}
	int now=s[Max];
	while(now!=Max+1){
		cout<<now<<' ';
		now=s[now];
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