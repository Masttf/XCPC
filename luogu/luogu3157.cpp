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
	int time,val,cnt;
	bool operator <(const node &y)const{
		return time>y.time;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector<node>b(n+1);
	vector<int>pos(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
		b[i].val=a[i];
		b[i].time=m+1;
	}
	vector<int>c(m+1);
	for(int i=1;i<=m;i++){
		cin>>c[i];
		b[pos[c[i]]].time=i;
	}
	int ans=0;
	vector<int>tr(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
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
	for(int i=n;i>=1;i--){
		ans+=ask(a[i]);
		updata(a[i],1);
	}
	tr=vector<int>(n+1);
	auto cdq = [&](auto self,int l,int r)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid);
		self(self,mid+1,r);
		int i=l,j=mid+1;
		//dbg(l,r);
		for(;j<=r;j++){
			while(i<=mid&&b[i].time>=b[j].time){
				updata(b[i].val,1);
				i++;
			}
			b[j].cnt+=ask(n)-ask(b[j].val);
			//dbg(b[j].time,b[j].cnt,b[j].val);
		}
		for(i--;i>=l;i--){
			updata(b[i].val,-1);
		}
		i=l,j=mid+1;
		for(;i<=mid;i++){
			while(j<=r&&b[j].time>=b[i].time){
				updata(b[j].val,1);
				j++;
			}
			b[i].cnt+=ask(b[i].val);
			//dbg(b[i].time,b[i].cnt);
		}
		for(j--;j>=mid+1;j--)updata(b[j].val,-1);
		sort(b.begin()+l,b.begin()+r+1);
	};
	cdq(cdq,1,n);
	vector<int>res(m+5);
	for(int i=1;i<=n;i++){
		res[b[i].time]=b[i].cnt;
	}
	cout<<ans<<'\n';
	for(int i=1;i<m;i++){
		ans-=res[i];
		cout<<ans<<'\n';
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