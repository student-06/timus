#include<stdio.h>

long long unsigned int dp[10][85]={{0}};

int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	dp[0][0]=1;
	
	for(i=1;i<10;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(k=0;k<=j && k <10;k++)
			{
				dp[i][j]+= dp[i-1][j-k];
			}
		}
	}

	printf("%lld\n",dp[9][n]+(n==1));
	return 0;

}
