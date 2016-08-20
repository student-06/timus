dpx = [0]*50005
cdpx = [0]*50005
dpy = [0]*50005
cdpy = [0]*50005

n,a,b = map(int,raw_input().split())

dpx[0] = cdpx[0] = 1
dpy[0] = cdpy[0] = 1

i = 1;
p = 10**9 +7
while(i<=n):
	if(i-1-a >= 0):
		dpx[i] = ( (cdpy[i-1]%p) - cdpy[i-1-a]%p )%p;
	else:
		dpx[i] = (cdpy[i-1]%p);

	if(i-1-b >= 0):
		dpy[i] = ( (cdpx[i-1]%p) - cdpx[i-1-b]%p )%p;
	else:
		dpy[i] = (cdpx[i-1]%p);

		
	cdpx[i] = ((dpx[i]%p) + (cdpx[i-1]%p))%p;
	cdpy[i] = ((dpy[i]%p) + (cdpy[i-1]%p))%p;
	i+=1;

print (dpx[n]+dpy[n])%p
