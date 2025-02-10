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
	int n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	s=' '+s;
	t=' '+t;
	auto check = [&](int p)->bool{
		bool ok =0;
		for(int i=1;i<=m;i++){
			//dbg(i+p-1);
			if(s[i+p-1]!='#'&&s[i+p-1]!=t[i]){
				return false;
			}
			if(s[i+p-1]==t[i])ok=1;
		}
		return ok;
	};
	auto change = [&](int p)->void{
		for(int i=0;i<m;i++){
			s[i+p]='#';
		}
		return ;
	};
	queue<int>q;
	for(int i=1;i<=n-m+1;i++){
		//dbg(i);
		if(check(i)){
			change(i);
			q.push(i);
		}
	}
	while(!q.empty()){
		int rt=q.front();
		q.pop();
		for(int i=rt-m+1;i<=rt+m-1;i++){
			if(i<=0||i>n-m)continue;
			if(check(i)){
				change(i);
				q.push(i);
			}
		}
	}
	int ok=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='#')ok=0;
	}
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}