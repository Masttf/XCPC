#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	string s1,s2;cin>>s1>>s2;

	s1=' '+s1;
	s2=' '+s2;
	int ok=1;
	vector<int>vis(5);
	for(int i=1;i<n;i++){
		if(s1[i]==s1[i+1]){
			ok=0;
			vis[s1[i]-'0']=1;
		}
	}
	if(ok){
		cout<<"YES\n";
		return ;
	}
	ok=1;
	for(int i=1;i<m;i++){
		if(s2[i]==s2[i+1])ok=0;
	}
	if(!ok)cout<<"NO\n";
	else{
		ok=1;
		for(int i=1;i<n;i++){
			if(s1[i]==s1[i+1]){
				ok=0;
				vis[s1[i]-'0']=1;
			}
		}
		if(ok){
			cout<<"YES\n";
		}else{
			if(m%2==0)cout<<"NO\n";
			else{
				int cnt=0;
				for(int i=0;i<2;i++){
					if(vis[i])cnt++;
				}
				if(cnt==2)cout<<"NO\n";
				else{
					cnt=0;
					for(int i=0;i<2;i++){
						if(vis[i])cnt=i;
					}
					if(s2[1]-'0'==cnt)cout<<"NO\n";
					else cout<<"YES\n";
				}
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}