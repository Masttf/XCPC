#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
//性质发现当1的位置可以通过移动左右移动控制1是否在里面
//来达到它的前缀和的数全部出现或者后缀和
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	
	vector<int>t(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
			t[x]+=val;
			x+=lowbit(x);
		}
	};

	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	for(int i=1;i<=n;i++)updata(i,a[i]);
	auto get = [&](int x,int d)->int{
		int l=x+1,r=n;
		int res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(ask(mid)-d==2*(mid-x)){
				l=mid+1;
				res=mid-x;
			}else r=mid-1;
		}
		return res;
	};
	for(int i=1;i<=m;i++){
		int t;cin>>t;
		if(t==1){
			int x;cin>>x;
			int l=1,r=n;
			int res=-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(ask(mid)>=x)res=mid,r=mid-1;
				else l=mid+1;
			}
			if(res==-1){
				cout<<"No\n";
			}else{
				int d=ask(res);
				if(d==x){
					cout<<"Yes\n";
					continue;
				}
				//assert(d!=x+1);
				
				if(a[1]==1){
					cout<<"Yes\n";
					continue;
				}
				if(res==n){
					cout<<"No\n";
					continue;
				}
				int cnt1=get(1,a[1])+1;
				int cnt2=get(res,d)+1;
				
				if(res+min(cnt2,cnt1)<=n){
					cout<<"Yes\n";
				}else cout<<"No\n";
				// int ok=0;
				// for(int i=res,j=1;i<=n;i++,j++){
				// 	if(a[i]==1||a[j]==1){
				// 		ok=1;
				// 		break;
				// 	}
				// }
				// if(!ok)cout<<"No\n";
				// else cout<<"Yes\n";
			}

		}else{
			int p,x;cin>>p>>x;
			updata(p,x-a[p]);
			a[p]=x;
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