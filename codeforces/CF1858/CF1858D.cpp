#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	s=' '+s;
	vector<int>p0(n+5),p1(n+5);
	for(int i=1;i<=n;i++){
		p0[i]+=p0[i-1];
		p1[i]+=p1[i-1];
		if(s[i]=='1')p1[i]++;
		else p0[i]++;
	}
	//vector<vector<int>>t0(n+5,vector<int>(k+5));
	//vector<vector<int>>t1(n+5,vector<int>(k+5));
	vector<vector<int>>s0(n+5,vector<int>(k+5));
	vector<vector<int>>s1(n+5,vector<int>(k+5));
	for(int i=n;i>=1;i--){
		for(int j=0;j<=k;j++){
			int l=i,r=n;
			int ans=i-1;
			while(l<=r){
				int mid=(l+r)>>1;
				int d=p1[mid]-p1[i-1];
				if(d<=j)ans=mid,l=mid+1;
				else r=mid-1;
			}
			s0[i][j]=max(s0[i+1][j],ans-i+1);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<=k;j++){
			int l=i,r=n;
			int ans=i-1;
			while(l<=r){
				int mid=(l+r)>>1;
				int d=p0[mid]-p0[i-1];
				if(d<=j)ans=mid,l=mid+1;
				else r=mid-1;
			}
			s1[i][j]=max(s1[i+1][j],ans-i+1);
		}
	}
	vector<int>r0(n+1,-1),r1(n+1,-1);
	for(int i=0;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			int r=j+i-1;
			int l=j;
			if(p1[r]-p1[l-1]>k)continue;
			int d=k-(p1[r]-p1[l-1]);
			r0[i]=max(r0[i],s1[r+1][d]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			int r=j+i-1;
			int l=j;
			if(p0[r]-p0[l-1]>k)continue;
			int d=k-(p0[r]-p0[l-1]);
			r1[i]=max(r1[i],s0[r+1][d]);
		}
	}
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=0;j<=n;j++){
			if(r0[j]!=-1)mx=max(mx,i*j+r0[j]);
			if(r1[j]!=-1)mx=max(mx,i*r1[j]+j);
		}
		cout<<mx<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
