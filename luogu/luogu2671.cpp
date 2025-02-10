/*
  易得只有同颜色的可以计算，只有x和y同为奇数或偶数才行
  1 所以按颜色分组，再把每种颜色分奇偶
  对于同一种颜色偶数为例
  (x1+x2)(y1+y2)+(x1+x3)(y1+y3)...+(x(k-1)+xk)(y(k-1)+yk)
  ==x1(y1*(n-2)+y1+y2+y3+...yk)
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
int color[100005];
int res[100005];
int s[100005][3];
int sum[100005][3];
signed main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	for(int i=1;i<=n;i++){
		cin>>color[i];
		s[color[i]][i%2]++;//分组
		sum[color[i]][i%2]+=res[i];//奇偶组的y1+...+yk
		sum[color[i]][i%2]%=10007;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=i*(res[i]*(s[color[i]][i%2]-2)+sum[color[i]][i%2]);
		ans%=10007;
	}
	cout<<ans;
	return 0;
}
