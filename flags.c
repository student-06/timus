/* Timus DP 1225 Flags*/

#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	long long int dp[50]={0};
	dp[0]=2;
	dp[1]=2;
	dp[2]=2;
	int i;
	for(i=3;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	printf("%lld\n",dp[n]);
	return 0;

}

/* Breif Explanation : When you have n stripes, nth is R/W then what you place next determines what comes after it. 
Consider blue strip specialy similar to how you treated 0 in question "K based number" */
