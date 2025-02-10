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
const int maxn=1e6+5;
vector<int>t1[maxn];
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			t1[s[i]-'0'].push_back(i);
		}
	}
	if(t1[1].empty()){
		for(int i=1;i<=n;i++){
			cout<<-1<<' '<<0<<'\n';
		}
		return ;
	}
	cout<<t1[1][0]<<' '<<t1[1].size()<<'\n';
	for(int i=2;i<=n;i++){
		int d=i>>1;
		int x=i%2;
		int sz=t1[d].size();
		int len=__lg(i)+1;
		for(int j=1;j<sz;j++){
			int p=t1[d][j];
			if(p+len-1>n)break;
			//dbg(i,p,p+len-1,x,s[p+len-1]);
			if(s[p+len-1]-'0'==x){
				t1[i].push_back(p);
				//dbg(i,p);
			}
		}
		if(t1[i].empty()){
			cout<<-1<<' '<<0<<'\n';
		}else cout<<t1[i][0]<<' '<<t1[i].size()<<'\n';
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