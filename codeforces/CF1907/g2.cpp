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
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector<int>a(n+1);
	vector<int>du(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		du[a[i]]++;
	}
	vector<int>ans;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(du[i]==0)q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		//dbg(u);
		if(s[u]=='1'){
			s[u]='0';
			s[a[u]]='1'-s[a[u]]+'0';
			ans.push_back(u);
		}
		du[a[u]]--;
		if(du[a[u]]==0)q.push(a[u]);
	}
	for(int i=1;i<=n;i++){
		if(du[i]){
			int j=i;
			int res=0;
			int last=0;
			int len=0;
			while(du[j]){
				if(s[j]=='1')last^=1;
				res+=last;
				du[j]--;
				j=a[j];
				len++;
			}
			if(last){
				cout<<-1<<'\n';
				return ;
			}
			for(int k=1;k<=len;k++){
				if(s[j]=='1')last^=1;
				if(last==(res<len-res))ans.push_back(j);
				j=a[j];
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}