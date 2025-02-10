#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
struct node{
	int v,id;
	bool operator <(const node &y)const{
		return v<y.v;
	}
}a[maxn];
void solve(){
	int n;cin>>n;//最多就n/2次，怎么样可以减少移动次数
	for(int i=1;i<=n;i++)cin>>a[i].v,a[i].id=i;
	if(n==2){
		if(a[1].v==1&&a[2].v==2)cout<<0<<'\n';
		else cout<<1<<'\n';
	}else if(n==1)cout<<0<<'\n';
	else{
		sort(a+1,a+1+n);
		int cnt=0;
		if(n%2==0){
			int l=n/2,r=n/2+1;
			int lb,rb;
			if(a[l].id<a[r].id){
				cnt++;
				lb=a[l].id,rb=a[r].id;
				l--,r++;
				while(cnt<n/2){
					if(a[l].id<lb&&a[r].id>rb){
						lb=a[l].id,rb=a[r].id;
						l--,r++;
						cnt++;
					}
					else break;
				}
				cout<<n/2-cnt<<'\n';
			}else cout<<n/2<<'\n';
		}else{
			int l=n/2,r=n/2+2;
			int lb,rb;
			if(a[l].id<a[n/2+1].id&&a[r].id>a[n/2+1].id){
				cnt++;
				lb=a[l].id,rb=a[r].id;
				l--,r++;
				while(cnt<n/2){
					if(a[l].id<lb&&a[r].id>rb){
						lb=a[l].id,rb=a[r].id;
						l--,r++;
						cnt++;
					}
					else break;
				}
				cout<<n/2-cnt<<'\n';
			}else cout<<n/2<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
