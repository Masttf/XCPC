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
const int mod=1e9+7;
void solve(){
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	reverse(b.begin(),b.end());
	b=' '+b;
	a=' '+a;
	if(a[1]!=b[1]||a.back()!=b.back()){
		cout<<-1<<'\n';
		return ;
	}
	vector f(2,vector<int>(n+5));
	vector<int>p(n+5);
	p[0]=1;
	for(int i=1;i<=n;i++){
		f[0][i]=f[0][i-1]*131+a[i]-'a';
		p[i]=p[i-1]*131;
	}
	for(int i=n;i>=1;i--){
		f[1][i]=f[1][i+1]*131+a[i]-'a';
	}
	auto get = [&](int t,int l,int r)->int{
		if(t==0)return f[t][r]-f[t][l-1]*p[r-l+1];
		else return f[t][l]-f[t][r+1]*p[r-l+1];
	};
	vector<int>pre(n+5,-1);
	vector<int>suf(n+5,-1);
	for(int i=1;i<=min(n,m);i++){
		if(a[i]!=b[i])break;
		if(get(0,1,i)==get(1,1,i))pre[i]=i;
	}
	for(int i=n,j=m;i&&j;i--,j--){
		if(a[i]!=b[j])break;
		if(get(0,i,n)==get(1,i,n))suf[min(i,j)]=n-i+1;
	}
	int ans=-1;
	for(int i=1;i<=n;i++)pre[i]=max(pre[i-1],pre[i]);
	for(int i=n;i>=1;i--)suf[i]=max(suf[i+1],suf[i]);
	for(int i=1;i<n;i++){
		if(pre[i]!=-1&&suf[i+1]!=-1){
			ans=max(pre[i]+suf[i+1],ans);
		}
	}
	assert(ans!=-1);
	cout<<ans*2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}