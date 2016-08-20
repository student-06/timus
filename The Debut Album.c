#include <stdio.h>

long long int dpx[50005],dpy[50005],cdpx[50005],cdpy[50005];

int main()

{
	int long long p = 1e9 + 7;
	long long  n,a,b;
	scanf("%lld %lld %lld",&n,&a,&b);

	long long int i;

	cdpx[0] = dpx[0] = 1ll;
	cdpy[0] = dpy[0] = 1ll;

	i = 1;
	while(i<=n)
	{
		if(i-1-a >= 0)
			dpx[i] = ( (cdpy[i-1]%p) - (cdpy[i-1-a]%p) )%p;
		else
			dpx[i] = (cdpy[i-1]%p);

		if(i-1-b >= 0)
			dpy[i] = ( (cdpx[i-1]%p) - (cdpx[i-1-b]%p) )%p;
		else
			dpy[i] = (cdpx[i-1]%p);

		if(dpx[i] < 0) dpx[i] += p;
		if(dpy[i] < 0) dpy[i] += p;
		if(cdpx[i] <0) cdpx[i] += p;
		if(cdpy[i] <0) cdpy[i] += p;

		
		cdpx[i] = ((dpx[i]%p) + (cdpx[i-1]%p))%p;
		cdpy[i] = ((dpy[i]%p) + (cdpy[i-1]%p))%p;

		//if(cdpx[i] <0 || cdpy[i] < 0 || dpx[i] < 0 || dpy[i] < 0) {printf("%lld %lld %lld %lld %lld\n",dpx[i-1],dpy[i-1],cdpx[i-1],cdpy[i-1],p);break;}

		if(dpx[i] < 0) dpx[i] += p;
		if(dpy[i] < 0) dpy[i] += p;
		if(cdpx[i] <0) cdpx[i] += p;
		if(cdpy[i] <0) cdpy[i] += p;

		i++;

	}

	//printf("%lld\n",(489383514%p + 112984749%p)%p );
	printf("%lld\n",(dpx[n]+dpy[n])%p);

	//for(i=0;i<=n;i++)
	//	printf("%lld %lld \n",dpx[i],dpy[i]);
	return 0;


}
