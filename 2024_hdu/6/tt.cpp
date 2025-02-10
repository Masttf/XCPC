
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 9;
ll dp[N][5];
char s[N];
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s+1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if(j)
			dp[i][j] += dp[i - 1][j - 1];
			for(int k = i-1;k>=1&&(i-k)<=j;k--)
			{
				if(s[k]==s[i])
				{
					dp[i][j] -= dp[k-1][j-(i-k)];
					//[j-(i-k)] k-1 删了几个字符
					break;
				}
			}
		}
	}
	ll ans = 0;
	for(int  i = 0;i<=3;i++)
	ans += dp[n][i];
	cout<<ans<<"\n";
}