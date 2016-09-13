#include<stdio.h>
#include<math.h>


int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	long long int a[1850]={0};
	a[1]=k-1;
	a[2]=k*(k-1);
	int i;
	for(i=3;i<=n;i++)
	{
		a[i]=(k-1)*(a[i-1]+a[i-2]);
	}
	//for (i=0;i<=n;i++)

		printf("%lld ",a[n]);
	return 0;
}
