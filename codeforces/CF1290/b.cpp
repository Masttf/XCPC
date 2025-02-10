#include<bits/stdc++.h>
#define int int long long
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
	int l,r,sum;
};
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'a'+1;
	vector pre(30,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++)pre[j][i]=pre[j][i-1];
			pre[a[i]][i]++;
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		if(l==r){
			cout<<"Yes\n";
		}else{
			if(a[l]!=a[r]){
				cout<<"Yes\n";
			}else{
				int cnt=0;
				for(int j=1;j<=26;j++){
					int dd=pre[j][r]-pre[j][l-1];
					if(dd)cnt++;
				}
				if(cnt>=3){
					cout<<"Yes\n";
				}else cout<<"No\n";
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}