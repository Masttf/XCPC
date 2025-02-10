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
	string s;cin>>s;
	string a;cin>>a;
	int n=0;
	for(int i=2;i<s.size();i++){
		n=n*10+s[i]-'0';
	}
	n=n/2+1;
	int cnt1=0,cnt2=0;
	for(auto x:a){
		if(x=='R'){
			cnt1++;
		}else cnt2++;
		if(cnt1==n){
			cout<<"kou!\n";
			cout<<cnt1+cnt2<<'\n';
			return ;
		}
		if(cnt2==n){
			cout<<"yukari!\n";
			cout<<cnt1+cnt2<<'\n';
			return ;
		}
	}
	cout<<"to be continued.\n";
	cout<<cnt1+cnt2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}