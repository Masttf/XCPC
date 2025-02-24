#include<bits/stdc++.h>
using namespace std;
long long kxor(long long a,long long b,long long k){
	long long ans=0,w=1,c;
	while(a>0||b>0)
	{
		c=(a+b)%k;
		a/=k;
		b/=k;
		ans+=c*w;
		w*=k;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	long long a,b,c,ans,i;
	for(cin>>T;T>0;T--)
	{
		cin>>a>>b>>c;
		if(a+b<c)
		{
			cout<<"0\n";
			continue;
		}
		if(a+b==c)
		{
			cout<<"-1\n";
			continue;
		}
		ans=0;
		for(i=2;i<=45000;i++)
		{
			if(kxor(a,b,i)==c)ans++;
		}
		if(a+b-c>45000&&kxor(a,b,a+b-c)==c)ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
