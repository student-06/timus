n=int(raw_input())
k=int(raw_input())
a=[1,k-1,k*(k-1)]

for i in range(3,n+1):
    a.append((k-1)*(a[i-1]+a[i-2]))
print a[n]
