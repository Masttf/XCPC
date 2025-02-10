#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...)\
do{\
	cout<<#x<<" -> ";\
	err(x);\
}while(0)
void err(){
	cout<<endl<<endl;
}
template <class T,class ...Ts>
void err(T arg,Ts &... args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int sum=0;
	vector<int>res;
	for(int i=n;i>=1;i--){
		if(s[i]=='0'){
			res.push_back(i);
		}
	}
	vector<int>ans(n+1);
	for(int i=res.size()+1;i<=n;i++)ans[i]=-1;
	for(int i=0,j=n;i<res.size();i++,j--){
		ans[i+1]=ans[i]+j-res[i];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}