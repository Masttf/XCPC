#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,m,a,b,mx;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>m>>a>>b;
		if(n==1||m==1)
		{
			cout<<n*m<<'\n';
			continue;
		}
		mx=0;
		if(a!=1&&a!=n)mx=max(mx,m-2);
		if(b!=1&&b!=m)mx=max(mx,n-2);
		cout<<n*2+m*2-4+mx<<'\n';
	}
	return 0;
}
