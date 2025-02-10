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
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node{
	int v1,v2,v3,cnt,val;
	bool operator == (const node &y)const{
		return (v1==y.v1&&v2==y.v2&&v3==y.v3);
	}
};
bool cmp1(node &x,node &y){
	if(x.v1!=y.v1)return x.v1<y.v1;
	if(x.v2!=y.v2)return x.v2<y.v2;
	return x.v3<y.v3;
}
bool cmp2(node &x,node &y){
	return x.v2<y.v2;
}
void solve(){
	int n,k;cin>>n>>k;
	vector<node>a(n+1);
	for(int i=1;i<=n;i++){
		int x,y,z;cin>>x>>y>>z;
		a[i]={x,y,z,0,0};
	}
	sort(a.begin()+1,a.end(),cmp1);
	int m=0;
	vector<node>res(n+1);
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&a[i]==a[j]){
			j++;
		}
		m++;
		res[m]=a[i];
		res[m].cnt=j-i;
		//cout<<res[m].v1<<' '<<res[m].v2<<' '<<res[m].v3<<'\n';
		i=j-1;
	}
	
	vector<int>tr(k+1);
	auto updata = [&](int x,int val)->void{
		while(x<=k){
			tr[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=tr[x];
			x-=lowbit(x);
		}
		return res;
	};
	auto cdq = [&](auto self,int l,int r)->void{
		if(l==r){
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid);
		self(self,mid+1,r);
		for(int j=mid+1,i=l;j<=r;j++){
			while(i<=mid&&res[i].v2<=res[j].v2){
				updata(res[i].v3,res[i].cnt);
				i++;
			}
			res[j].val+=ask(res[j].v3);
		}
		for(int j=mid+1,i=l;j<=r;j++){
			while(i<=mid&&res[i].v2<=res[j].v2){
				updata(res[i].v3,-res[i].cnt);
				i++;
			}
		}
		sort(res.begin()+l,res.begin()+r+1,cmp2);
	};
	cdq(cdq,1,m);
	vector<int>cnt(n+1);
	for(int i=1;i<=m;i++){
		cnt[res[i].val+res[i].cnt-1]+=res[i].cnt;
	}
	for(int i=0;i<n;i++){
		cout<<cnt[i]<<'\n';
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