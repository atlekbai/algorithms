#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,i,j=0,ans=1,m=pow(10,9)+7,r;
		cin>>n;
		long long a[n];
		long long count[n];
		fill(count,count+n,1);
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n,greater<int>());

		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				count[j]++;
			else j++;
		}
		r=n;
		n=j+1;
		for(i=0;i<n;i++)
		{
			if(count[i]<=0) continue;
			if(count[i]%2==0)
			{
				for(j=count[i]-1;j>2;j-=2)
				{
					ans*=j;
					ans=ans%m;
				}
			}
			else
			{
				for(j=count[i];j>2;j-=2)
				{
					ans*=j;
					ans=ans%m;
				}
				if(i!=n-1)
					ans*=count[i+1];
				count[i+1]--;
				ans=ans%m;
			}
		}
		cout<<ans<<endl;
	}
	return (0);
}