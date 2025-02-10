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
	int cnt=0;
	for(int i=30;i>=0;i--){
		if(n>>i&1){
			cnt=i+1;
			break;
		}
	}
	if((1<<(cnt-1))==n)cnt--;
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		vector<int>temp;
		for(int j=1;j<=n;j++){
			if(j>>(i-1)&1)temp.push_back(j);
		}
		cout<<temp.size()<<' ';
		for(auto x:temp)cout<<x<<' ';
		cout<<endl;
	}
	string s;cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')ans+=1<<i;
	}
	if(ans==0)cout<<n<<endl;
	else cout<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}