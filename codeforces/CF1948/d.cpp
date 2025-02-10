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
struct node{
	int lmx,rmx,mx;
};
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	int ans=0;
	for(int len=2;len<=n;len+=2){
		int cnt=0;
		for(int i=1;i<=len/2;i++){
			if(s[i]=='?'||s[i+len/2]=='?')continue;
			if(s[i]!=s[i+len/2])cnt++;
		}
		if(!cnt)ans=max(ans,len);
		//dbg(len,cnt);
		for(int i=2;i+len-1<=n;i++){
			//dbg(i,i+len/2-1,i+len/2,i+len-1);
			//dbg(s[i-1],s[i-1+len/2]);
			if(s[i-1]!='?'&&s[i-1+len/2]!='?'&&s[i-1]!=s[i-1+len/2])cnt--;
			if(s[i+len/2-1]!='?'&&s[i+len-1]!='?'&&s[i+len/2-1]!=s[i+len-1])cnt++;
			if(!cnt)ans=max(ans,len);
			//dbg(i,cnt);
		}
		//dbg(len,ans);
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