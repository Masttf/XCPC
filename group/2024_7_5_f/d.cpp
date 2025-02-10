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
	string a,b;cin>>a>>b;
	int n=a.size();
	int m=b.size();
	int xx=0;int y=0;
	for(int i=0;i<n;i++){
		xx=xx*10+a[i]-'0';
	}
	for(int i=0;i<m;i++){
		y=y*10+b[i]-'0';
	}
	if(a.size()!=b.size()){
		int t=5;
		for(int i=1;i<n;i++)t*=10;
		while(t<=y){
			if(t>=xx&&t<=y){
				cout<<t<<'\n';
				return ;
			}
			t*=10;
		}
		t=a[0]-'0';
		int num=1;
		for(int i=1;i<n;i++){
			t*=10;
			num*=10;
		}
		//dbg(t,num);
		for(int i=0;i<=10;i++){
			int d=t+num*i;
			if(xx<=d&&d<=y){
				cout<<d<<'\n';
				return ;
			}
		}
	}
	if(a==b){
		cout<<a<<'\n';
		return ;
	}
	int x=0;
	int flag=0;
	int num=1;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])flag=1;
		if(!flag)x=x*10+a[i]-'0';
		else{
			x*=10;
			num=num*10;
		}
	}
	num/=10;
	if(xx<=x&&x<=y){
		cout<<x<<'\n';
		return ;
	}
	//dbg()
	if(xx<=x+5*num&&x+5*num<=y){
		cout<<x+5*num<<'\n';
		return ;
	}
	for(int i=1;i<=10;i++){
		x+=num;
		if(xx<=x&&x<=y){
			cout<<x<<'\n';
			return ;
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