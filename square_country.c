#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
	return a<b?a:b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int dp[60005] = {0};
	int i,j;

	for(i=0;i<60005;i++)
		dp[i] = 1e7;
	for(i=0;i*i < 60005;i++)
		dp[i*i] = 1;

	for(i=1;i<60005;i++)
	{
		for(j=1;j*j < i;j++)
		{
			if(i-j*j >0)
				dp[i] = min(dp[i],dp[i-j*j]+1);
		}
	}

	printf("%d\n",dp[n]);
	return 0;

}
