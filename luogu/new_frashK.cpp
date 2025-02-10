#include<bits/stdc++.h>
#define int long long
using namespace std;
//枚举2的每一位考虑这一位是0得到什么结果这一位是1是什么结果
int res1[35],res2[35];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	//1&2|3^
	int id,a;
	int s=0,s1=(1<<30)-1;
	for(int i=1;i<=n;i++){
		cin>>id>>a;
		if(id==1) s&=a,s1&=a;
		else if(id==2) s|=a,s1|=a;
		else s^=a,s1^=a;
	}
	for(int i=0;i<=30;i++){
		res1[i]=s&1;
		res2[i]=s1&1;
		s1>>=1;
		s>>=1;
	}
	int r;
	for(int i=1;i<=q;i++){
		cin>>r;
		int len=log2(r);//其他几位都固定好的
		int base=1<<(len);
		int sum=0;
		for(int j=len;j>=0;j--){//因为要让y尽量大所以我应该从答案的高位开始枚举
			if(res1[j]!=1&&res2[j]==1){
				if(sum+base<=r)sum+=base;
			}
			base>>=1;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
/*
暴力枚举然后t了
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int ans[maxn];
pair<int,int>res[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	//1&2|3^
	int id,a;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>id>>a;
		res[i]={id,a};
		if(id==1) s&=a;
		else if(id==2) s|=a;
		else s^=a;
	}
	int mx=s;
	ans[0]=0;
	for(int i=1;i<=maxn;i++){
		int temp=i;
		for(int j=1;j<=n;j++){
			if(res[j].first==1) temp&=res[j].second;
			else if(res[j].first==2) temp|=res[j].second;
			else temp^=res[j].second;
		}
		if(mx<temp)ans[i]=i,mx=temp;
		else ans[i]=ans[i-1];
	}
	int x;
	for(int i=1;i<=q;i++){
		cin>>x;
		cout<<ans[x]<<'\n';
	}
	return 0;
}
*/
