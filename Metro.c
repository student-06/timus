/* TIMUS DP METRO*/

#include <stdio.h>
#include <math.h>

float min(float a, float b)
{
	return a<b?a:b;
}

int roundNo(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

int main()
{
	int n,m;
	scanf("%d %d", &n ,&m);
	int a[n+1][m+1],i,j;
	float dis[n+1][m+1];
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			dis[i][j]=0;
			a[i][j]=0;
		}
	int k;
	scanf("%d", &k);
	
	for(i=0;i<k;i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		a[x][y]=1;
	}
	dis[0][0]=0;
	dis[1][0]=100.0;
	dis[0][1]=100;
	
	for(i=1;i<=n;i++)
		dis[i][0]=100+dis[i-1][0];
	

	for(i=1;i<=m;i++)
		dis[0][i]=100+dis[0][i-1];
	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j] && ((100.0*sqrt(2.0)+dis[i-1][j-1]))<((min(dis[i-1][j],dis[i][j-1])+100)))
				{
					dis[i][j]=(100.0*sqrt(2.0)+dis[i-1][j-1]);
					/*if(i==3 && j==2)
					{
						printf("%d %f", a[i][j], dis[i-1][j-1]);
					}*/
				}
			else
				{
					dis[i][j]=(min(dis[i-1][j],dis[i][j-1])+100);
				}
		}
	}
	/*-for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			printf("%f ",dis[i][j]);
			printf("\n");
		}
	*/
	//printf("%d",a[3][2]);
	printf("%d",roundNo(dis[n][m]));
	return 0;

}
