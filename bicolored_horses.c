#include <stdio.h>

int a[550],o[550],z[550];
int dp[550][550];
int n,k;

int min(int a,int b)
{
	return a < b ? a:b;
}
int f(int i,int k)
{
	int j;
	
	if(k==0)
	{
		dp[i][k] = o[i]*z[i];
		return dp[i][k];
	}

	if(i==0 )
		return 0;
	
	if(dp[i][k] != -1)
		return dp[i][k];

	int c = 1e9;
	for(j=0;j<i;j++)
		c = min(f(j,k-1) + (o[i]-o[j])*(z[i] - z[j]),c);

	dp[i][k] = c;
	return dp[i][k];
}


int main()
{
	
	scanf("%d %d",&n,&k);
	int i;
	o[0] = 0;
	z[0] = 0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		o[i+1] = o[i] + a[i];
		z[i+1] = z[i] + !a[i];
	}
	int j;
	for(i=0;i<=n;i++)
		for(j=0;j<=k;j++)
			dp[i][j] = -1;

	printf("%d\n",f(n,k-1));


	return 0;
}
