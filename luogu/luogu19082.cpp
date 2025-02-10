#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
	int l,r,val,id,cnt;
};
bool cmp1(node &x,node &y){
	if(x.l!=y.l)return x.l<y.l;
	if(x.r!=y.r)return x.r>y.r;
	return x.cnt>y.cnt;
}
bool cmp2(node &x,node &y){
	return x.r>y.r;
}
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	auto cdq = [&](auto self,int l,int r)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid);
		self(self,mid+1,r);
		int i=l,j=mid+1;
		for(int )
	};
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}