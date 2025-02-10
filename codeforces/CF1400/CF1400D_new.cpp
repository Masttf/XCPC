
#include<iostream>
#define int long long
using namespace std;
const int N=3005;
int t,n,sum[N][N],a[N],ans;
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			for(int j=1;j<=n;++j)
				sum[i][j]=sum[i-1][j];
			sum[i][a[i]]++;
			//统计每个数出现次数的前缀和 
		}
		//枚举 j,k O(1) 计算答案 
		for(int j=2;j<=n;++j)
			for(int k=j+1;k<=n-1;++k)
				//(sum[n][a[j]]-sum[k][a[j]])当j前面没有这个数的等0即对答案无影响
				ans+=(sum[j-1][a[k]])*(sum[n][a[j]]-sum[k][a[j]]);
		cout<<ans<<'\n';
	}
	return 0;
}
