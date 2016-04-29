/* TIMUS MAXIMUM SUM- TO FIND max sum SUBmatrix*/


#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int col[n][n],row[n][n];
	col[0][0]=row[0][0]=a[0][0];

	for(i=0;i<n;i++)
		row[i][0]=a[i][0];

	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			row[i][j]=row[i][j-1]+a[i][j];
		}
	}

	for(i=0;i<n;i++)
		col[0][i]=a[0][i];

	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			col[i][j]=col[i-1][j]+a[i][j];
		}
	}

	int mat[n][n];
	mat[0][0]=a[0][0];
	for(i=0;i<n;i++)
		mat[0][i]=row[0][i];
	for(i=0;i<n;i++)
		mat[i][0]=col[i][0];

	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			mat[i][j]=mat[i-1][j-1]+a[i][j]+row[i][j-1]+col[i-1][j];
		}
	}

	int x,y,max=-1000000;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(x=0;x<=i;x++)
			{
				for(y=0;y<=j;y++)
				{
					int temp=mat[i][j];
					if(x!=0) temp-=mat[x-1][j];
					if(y!=0) temp-=mat[i][y-1];
					if(x!=0 && y!=0) temp+=mat[x-1][y-1];
					if(temp > max)
						{
							max=temp;
							//printf("%d %d %d %d\n", i, j,x,y);
						}
				}
			}
		}
	}
	//printf("\n");
	/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			printf("%d ",mat[i][j]);
			printf("\n");
		}*/
	printf("%d\n",max);
	return 0;

}
