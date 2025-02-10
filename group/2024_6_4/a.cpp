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
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	auto check = [&](int l,int r)->bool{
		int cnt=0;
		for(int i=l;i<=r;i++){
			if(s[i]=='0')cnt++;
		}
		return cnt==4;
	};
	auto pf = [&](int l,int r)->void{
		if(check(l,r)){
			cout<<0;
		}else{
			int flag=0;
			for(int i=l;i<=r;i++){
				if(s[i]!='0')flag=1;
				if(flag)cout<<s[i];
			}
		}
		return ;
	};
	vector<int>val(10);
	for(int i=1;i<=8;i++){
		int l=5*(i-1)+1;
		int r=l+3;
		if(check(l,r))val[i]=1;
		else val[i]=0;
	}
	int mx=-1;
	vector<int>vis(10);
	for(int i=1;i<=8;i++){
		if(val[i]){
			int j=i;
			while(j<=8&&val[j]==1)j++;
			mx=max(mx,j-i);
			for(int k=i;k<j;k++)vis[k]=j-i;
			i=j-1;
		}
	}
	// for(int i=1;i<=8;i++){
	// 	dbg(i,val[i]);
	// 	dbg(i,vis[i]);
	// }
	int flag=0;
	//dbg(mx);
	for(int i=1;i<=8;i++){
		if(vis[i]==mx){
			cout<<"::";
			while(i<=8&&vis[i]==mx)i++;
			mx=-1;
			flag=0;
			i--;
		}else{
			if(flag)cout<<':';
			flag=1;
			int l=5*(i-1)+1;
			int r=l+3;
			pf(l,r);
		}
		//cout<<endl;
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}