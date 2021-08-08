#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
   
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long int>ans;
        
        stack<long long int>s;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty()==true)
            {
                ans.push_back(-1);
            }
            else if (arr[i]<s.top())
            {
                ans.push_back(s.top());
            }
            else
            {
                while(s.empty()==false && arr[i]>=s.top())
                {
                    s.pop();
                }
                
                if(s.empty()==true)
                ans.push_back(-1);
                else
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  
