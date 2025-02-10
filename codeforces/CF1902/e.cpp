#include<bits/stdc++.h>
//#define int long long
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
	int n;cin>>n;
	vector<string>a(n);
	vector<string>b(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i].size();
		b[i]=a[i];
		reverse(b[i].begin(),b[i].end());
	}
	vector tr(27,vector<int>(sum));
	vector<int> val(sum);
	int cnt=1;
	auto insert = [&](string s)->void{
		int p=1;
		for(auto x:s){
			int d=x-'a';
			if(!tr[d][p])tr[d][p]=++cnt;
			p=tr[d][p];
			val[p]+=2;
		}
	};
	auto ask = [&](string s)->int{
		int res=0;
		int p=1;
		for(auto x:s){
			int d=x-'a';
			if(!tr[d][p])break;
			p=tr[d][p];
			res+=val[p];
		}
		return res;
	};
	for(int i=0;i<n;i++)insert(a[i]);
	
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=1ll*sum+n*b[i].size()-ask(b[i]);
		//dbg(ask(b[i]));
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