#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
int c[3];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,ans;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>s1>>s2>>s3;
		for(i=0;i<3;i++)c[i]=0;
		ans=0;
		for(i=0;i<n;i++)
		{
			if(s1[i]!=s2[i]&&s1[i]!=s3[i])c[0]++;
			else if(s2[i]!=s1[i]&&s2[i]!=s3[i])c[1]++;
			else if(s3[i]!=s1[i]&&s3[i]!=s2[i])c[2]++;
			else ans++;
		}
		sort(c,c+3);
		cout<<ans+c[0]+c[1]+(c[2]-c[1])/2<<'\n';
	}
	return 0;
}
