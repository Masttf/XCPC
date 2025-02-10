#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int ne[maxn],f[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a,b;cin>>a>>b;
	ne[0]=-1;//初值 -1
	int la=a.size(),lb=b.size();
	for(int i=1,j=-1;i<lb;i++){//双指针的过程
		while(j>-1&&b[i]!=b[j+1])j=ne[j];//如果不能匹配j=ne[j]
		if(b[i]==b[j+1])j++;//能匹配
		ne[i]=j;
	}
	for(int i=0,j=-1;i<la;i++){
		while(j>-1&&(j==lb-1||a[i]!=b[j+1]))j=ne[j];//j到最后一个或者不匹配
		if(a[i]==b[j+1])j++;
		f[i]=j;
		if(f[i]==lb-1){
			cout<<i+1-lb+1<<'\n';
		}
	}
	for(int i=0;i<lb;i++)cout<<ne[i]+1<<' ';
	return 0;
}
