class Solution {
public:
    vector<int> leftelement(vector<int> arr, int n){
        // Your code here
        vector<int>ans;
        int mx=arr[0];
        ans.push_back(mx);
        for(int i=1;i<n;i++)
        {
            if(mx<arr[i])
                mx=arr[i];
            ans.push_back(mx);
        }
        return ans;
    }
    vector<int> rightelement(vector<int> arr, int n){
        // Your code here
        vector<int>ans;
        int mx=arr[n-1];
        ans.push_back(mx);
        for(int i=n-2;i>=0;i--)
        {
            if(mx<arr[i])
                mx=arr[i];
            ans.push_back(mx);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int trap(vector<int>& height) {
        int ans=0,n=height.size();
        
        vector<int>left=leftelement(height,n);
        vector<int>right=rightelement(height,n);
        
        for(int i=1;i<n-1;i++)
        {
            //cout<<left[i]<<" "<<right[i]<<endl;
            ans+=(min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};
