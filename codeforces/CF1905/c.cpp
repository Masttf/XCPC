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
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	stack<int>ss;
	for(int i=1;i<=n;i++){
		while(!ss.empty()&&s[i]>s[ss.top()]){
			ss.pop();
		}
		ss.push(i);
	}
	vector<pair<int,int>>res;
	vector<int>p;
	//cout<<ss.size()<<endl;
	while(!ss.empty()){
		res.push_back({s[ss.top()],ss.top()});
		p.push_back(ss.top());
		ss.pop();
	}
	//dbg("yes");
	sort(res.begin(),res.end());
	int sz=p.size();
	for(int i=0;i<sz;i++){
		s[p[sz-i-1]]=res[i].first;
	}
	for(int i=1;i<n;i++){
		if(s[i]>s[i+1]){
			cout<<-1<<'\n';
			return ;
		}
	}
	//dbg(s);
	
	for(int i=n;i>=1;i--){
		if(s[i]==s[n])sz--;
		else break;
	}
	cout<<sz<<'\n';
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}