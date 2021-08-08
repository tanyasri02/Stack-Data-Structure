#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to calculate span
// price[]: price array in input
// n: size of array
vector <int> calculateSpan(int a[], int n)
{
    vector <int> ans;
    stack<pair<int,int>> s;
    
   for(int i=0;i<n;i++)
   {
       if(s.empty())
       ans.push_back(1);
       else
       {
           while(!s.empty() && s.top().first<=a[i])
           s.pop();
           
           if(s.empty())
            ans.push_back(i+1);
            else
            ans.push_back(i-s.top().second);
       }
       s.push({a[i],i});
   }
   return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
