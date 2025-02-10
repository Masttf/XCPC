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
	int t,p,x;
};
void solve(){
	int n,m,q;cin>>n>>m>>q;
	vector<node>a(q+1);
	for(int i=1;i<=q;i++){
		int t,p,x;cin>>t>>p>>x;
		a[i]={t,p,x};
	}
	map<int,int>res;
	vector<int>visx(n+1);
	vector<int>visy(m+1);
	int cnt1=0,cnt2=0;
	for(int i=q;i>=1;i--){
		auto [t,p,x]=a[i];
		if(t==1){
			if(visx[p])continue;
			else{
				visx[p]=1;
				if(m-cnt2)res[x]+=m-cnt2;
				cnt1++;
			}
		}else{
			if(visy[p])continue;
			else{
				visy[p]=1;
				if(n-cnt1)res[x]+=n-cnt1;
				cnt2++;
			}
		}
	}
	//dbg(cnt1,cnt2);
	int sum=n*m;
	for(auto [x,y]:res){
		sum-=y;
	}
	if(sum)res[0]+=sum;
	cout<<res.size()<<'\n';
	for(auto [x,y]:res){
		cout<<x<<' '<<y<<'\n';
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