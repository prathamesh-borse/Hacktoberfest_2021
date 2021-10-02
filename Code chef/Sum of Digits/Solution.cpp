#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n--)
	{
	 int t,ans=0;
	 cin>>t;
	while(t>0)
	{
	    ans=ans +t%10;
	    t=t/10;
	}
	ans=ans+t;
	cout<<ans<<endl;
	}
	return 0;
}
