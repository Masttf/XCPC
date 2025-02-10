//最终都会形成一个三角形，那么只需要知道这些三角形在最底层所形成的长度即可直接计算
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int vis[maxn];//利用最底层的长度就可以算出面积了
int ans[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	int x,y;
	for(int i=1;i<=k;i++){
		cin>>y>>x;
		vis[x]++;
		vis[x+n-y+1]--;
	}
	for(int i=1;i<=n;i++){
		ans[i]=vis[i]+ans[i-1];
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(ans[i]>0){
			long long l=0;
			while(i<=n&&ans[i]>0)i++,l++;
			sum+=(l+1)*l/2;
		}
	}
	cout<<sum;
	return 0;
}
/*
//如何通过cx和cy即顶点快速算出最后当x=n时y的值cx-cy为定则n-y=cx-cy ->y=n+cy-cx
//如何计算这个面积1+...+n-cx=(1+n-cx)*(n-cx+1)/2
int cx=res[0].first,cy=res[0].second,area=(1+n-cx+1)*(n-cx+1)/2;
int l=cx-cy;
for(int i=1;i<k;i++){
	if(res[i].first>=cx&&res[i].second<=res[i].first+cy-cx)continue;//表示该点已经在黑色里面
	else if(res[i].first<cx&&res[i].first+n-cx>=cx){//表右边部分在黑色里面
		cx=res[i].first;
		cy=cx-l;
		area=(1+n-cx)*(n-cx+1)/2;
	}
	else if(res[i].first>cx&&res[i].first+n-cx>n+cy-cx){//考虑左边在黑色里面
		l=res[i].first-res[i].second;
		cy=cx-l;
		area=(1+n-cx)*(n-cx+1)/2;
	}
	else {//如果形成的三角形不在黑色里面
		area+=
	}
}
cout<<area;
 */
