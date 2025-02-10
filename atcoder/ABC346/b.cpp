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
	string s="wbwbwwbwbwbw";
	int a,b;cin>>a>>b;
	
	string temp=s;
	while((a+b)*2>temp.size()){
		temp+=s;
	}
	temp=' '+temp;
	int n=temp.size()-1;
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(temp[i]=='w')pre[i]++;
	}
	for(int i=1;i+a+b-1<=n;i++){
		int l=i,r=i+a+b-1;
		int d2=a+b;
		int d=pre[r]-pre[l-1];
		d2-=d;
		if(d==a&&d2==b){
			cout<<"Yes\n";
			return ;
		}
	}
	cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}