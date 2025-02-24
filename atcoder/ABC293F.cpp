#include<bits/stdc++.h>
#define int __int128
using namespace std;
long long n;
int check(int x,int k){
	int res=0,base=1;
	int f=0;//判断底数是不是已经超过n
	for(int i=0;i<7;i++){
		if(k>>i&1){
			if(f)return 1;//如果超过n还加说明肯定爆了
			res+=base;
			if(res>n||res<0)return 1;
		}
		base*=x;
		if(base>n||base<0)f=1;
	}
	if(res > n) return 1;
	else if(res == n) return 2;
	else return 0;
}
void solve(){
	cin>>n;
	int ans=0;
	for(int i=2;i<=min(1000LL,n);i++){
		int t=n;
		int flag=1;
		while(t){
			if(t%i>1){
				flag=0;
				break;
			}
			t/=i;
		}
		if(flag)ans++;
	}
	for(int i=1;i<128;i++){
		int l=1001,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			int t=check(mid,i);
			if(t==0)l=mid+1;
			else if(t==1)r=mid-1;
			else{
				ans++;
				break;
			}
		}
	}
	long long kk=ans;
	cout<<kk<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long t;cin>>t;
	while(t--)solve();
	return 0;
}
