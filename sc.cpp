#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	pair<int, int> a[n];
	for(int i =0;i<n;i++)
	{
		int st,end;
		cin >> st >> end;
		a[i].first = end;
		a[i].second = st;
	}

	sort(a,a+n);
	
	vector < pair< int, int> > ans;
	for(int i=0;i<n;i++)
	{
		if(ans.size() == 0)
			ans.push_back(a[i]);
		else
		{
			if(ans[ans.size() - 1].first < a[i].second)
				ans.push_back(a[i]);
		}
	}

	cout << ans.size()<<endl;
	return 0;
}