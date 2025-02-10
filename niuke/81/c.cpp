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
void err(T arg, Ts &... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	map<int,int>m1;
	map<int,int>m2;
	for(int i=1;i<=n;i++){
		int t,x;cin>>t>>x;
		if(t==1){
			for(int j=2;j*j<=x;j++){
				while(x%j==0){
					x/=j;
					m1[j]++;
				}
			}
			if(x!=1)m1[x]++;
		}
		else{
			for(int j=2;j*j<=x;j++){
				while(x%j==0){
					x/=j;
					m2[j]++;
				}
				
			}
			if(x!=1)m2[x]++;
		}
	}
	int ok=1;
	
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int t,x;cin>>t>>x;
		if(t==1){
			for(int j=2;j*j<=x;j++){
				while(x%j==0){
					x/=j;
					m2[j]++;
				}
				
			}
			if(x!=1)m2[x]++;
		}
		else{
			for(int j=2;j*j<=x;j++){
				while(x%j==0){
					x/=j;
					m1[j]++;
				}
				
			}
			if(x!=1)m1[x]++;
		}
	}
	
	for(auto it=m1.begin();it!=m1.end();it++){
		if(m2[it->first]!=it->second)ok=0;
		//cout<<it->first<<' '<<it->second<<endl;
	}
	cout<<endl;
	for(auto it=m2.begin();it!=m2.end();it++){
		if(m1[it->first]!=it->second)ok=0;
		//cout<<it->first<<' '<<it->second<<endl;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}