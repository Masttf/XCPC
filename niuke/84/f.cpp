#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	errr(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	vector<int>a(n);
	//首先想到第一位一定可以填0,然后填了第一位可以填n位,然后我们想填第n-1位必须知道第二位是什么
	//以此类推发现我们只需要n/2向上取整的位其他可以计算出来
	//如果有解第一位一定可以是0
	for(int i=1;i<n;i++)cin>>a[i];
	string s;
	auto check = [&](int ff)->bool{
		s=string(n,'0');
		for(int i=0;i<=(n-1)/2+1;i++){
			if(ff>>i&1)s[i]='1';
		}
		for(int len=n-1;len>=1;len--){
			int cnt=0;
			for(int i=0,j=len;j<n;j++,i++){
				if(s[i]=='0'&&s[j]=='1')cnt++;
			}
			if(cnt!=a[len]){
				if(len>=(n-1)/2+1&&cnt==a[len]-1&&s[0]=='0')s[len]='1';
				else return false;
			}
		}
		return true;
	};
	for(int i=0;i<(1<<((n-1)/2+1));i++){
		if(check(i)){
			cout<<s<<'\n';
			return ;
		}
	}
	cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}