#include<bits/stdc++.h>
using namespace std;
int a[300],k;
bool flag=0;
string num;
int main(){
	cin>>num>>k;
	int n=num.length();
	for(int i=1;i<=n;++i)a[i]=num[i-1]-'0';
	int cnt=0;//记录现在已经排了几个
	int min;
	int cur=1;
	int rest=n-k;
	bool flag=0;
	while(cnt<rest){//当cnt==rest时终止即排好了
		min=cur;
		for(int i=cur;i<=k+cur;i++){
			if(a[min]>a[i])min=i;
		}
		if(a[min])flag=1;
		if(flag)cout<<a[min];
		k-=min-cur;
		cur=min+1;
		cnt++;
	}
	if(!flag)cout<<0;
	return 0;
}
