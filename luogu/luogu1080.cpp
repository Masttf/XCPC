//如何贪心
//先假设最小案例比如说排两个人
//假设国王左手为s
//第一个人a1 b1，第二个人a2，b2
//假设1排在前面比2排在前面好
//max(s/b1，s*a1/b2)<max(s/b2,s*a2/b1);
//易得s*a1/b2>s/b2
//假设s*a1/b2>s*a2/b1>s/b1
//同时s*a1/b2>s/b2
//即第一个排在前的最大值大于第二个不服
//所以排在前的是a1/b2>a2/b1;
#include<bits/stdc++.h>
using namespace std;
struct dc{
	int left;
	int right;
}s[10005];
bool cmp(dc x,dc y){
	return x.left*x.right<y.left*y.right;
}
int ans[4004],sum[4004],lsum=1,lans=0;
void f(int t){
	int d[4004]={0},ld=lsum;
	for(int i=lsum;i>=1;i--){
		d[i]+=sum[i];
		d[i-1]+=d[i]%t*10;//向下取整
		d[i]/=t;
	}
	while(d[ld]==0&&ld>1)ld--;//消去前导0
	bool flag=0;
	if(lans==ld){
		for(int i=ld;i>=1;i--){
			if(ans[i]>d[i]){
				break;
			}else if(ans[i]<d[i]){
				flag=1;
				break;
			}
		}
	}else if(lans<ld)
		flag=1;
	if(flag){
		lans=ld;
		for(int i=1;i<=ld;i++){
			ans[i]=d[i];
		}
	}
}
int main(){
	int n,b;
	cin>>n>>sum[1]>>b;
	for(int i=1;i<=n;i++){
		cin>>s[i].left>>s[i].right;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		f(s[i].right);
		for(int j=1;j<=lsum;j++){
			sum[j]*=s[i].left;
		}
		for(int j=1;j<=lsum;j++){
			sum[j+1]+=sum[j]/10;
			sum[j]%=10;
			if(sum[lsum+1]>0)lsum++;
		}
	}
	for(int i=lans;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
