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
	string a;cin>>a;
	string b;cin>>b;
	int la=a.size();
	int lb=b.size();
	a=' '+a;
	b=' '+b;
	vector<int>p(lb+1);
	p[0]=1;
	for(int i=1;i<=lb;i++){
		p[i]=p[i-1]*131;
	}
	vector<int>fa(la*2+1);
	fa[0]=1;
	for(int i=1;i<=la;i++){
		fa[i]=fa[i-1]*131+a[i]-'A';
	}
	for(int i=la+1;i<=2*la;i++){
		fa[i]=fa[i-1]*131+a[i-la]-'A';
	}
	auto geta = [&](int l,int r)->int{
		return fa[r]-fa[l-1]*p[r-l+1];
	};
	// for(int i=1;i<=2*la;i++){
	// 	//dbg(i,fa[i]);
	// }
	map<int,int>m;
	for(int i=la;i<2*la;i++){
		m[geta(i-la+1,i)]++;
	}
	vector<int>f(lb+1);
	f[0]=1;
	for(int i=1;i<=lb;i++){
		f[i]=f[i-1]*131+b[i]-'A';
		//dbg(i,f[i]);
	}
	auto get = [&](int l,int r)->int{
		return f[r]-f[l-1]*p[r-l+1];
	};
	// dbg(get(2,3));
	// dbg(get(2,2));
	int ans=0;
	for(int i=1;i+la-1<=lb;i++){
		int d=get(i,i+la-1);
		if(m.count(d))ans+=m[d];
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}