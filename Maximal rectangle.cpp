class Solution {
public:
    vector<int> leftele(vector<int>arr,int n)
    {
        vector<int>left;
        stack<pair<int,int>>s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty()==true)
            {
                left.push_back(-1);
            }
            else if(s.top().first<arr[i])
            {
                left.push_back(s.top().second);
            }
            else
            {
                while(s.empty()==false && s.top().first>=arr[i])
                    s.pop();
                
                if(s.empty()==true)
                    left.push_back(-1);
                else
                    left.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        
        
        
        return left;
    }
    vector<int> rightele(vector<int>arr,int n)
    {
        vector<int>right;
        stack<pair<int,int>>s;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty()==true)
            {
                right.push_back(n);
            }
            else if(s.top().first<arr[i])
            {
                right.push_back(s.top().second);
            }
            else
            {
                while(s.empty()==false && s.top().first>=arr[i])
                    s.pop();
                
                if(s.empty()==true)
                    right.push_back(n);
                else
                    right.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        
       
        reverse(right.begin(),right.end());
        
        return right;
    }
    int largestRectangleArea(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        
        vector<int>left=leftele(arr,n);
        vector<int>right=rightele(arr,n);
        
        for(int i=0;i<n;i++)
        {
            int area=arr[i]*(right[i]-left[i]-1);
            ans=max(ans,area );
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<int>v1;
        
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j]=='1')
            v1.push_back(1);
            else if(matrix[0][j]=='0')
            v1.push_back(0);
            
            
        }
        //cout<<endl;
        int ans=largestRectangleArea(v1);
        
        for(int i=1;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                    v1[j]=0;
                else
                    v1[j]+=1;
                
            }
            ans=max(largestRectangleArea(v1),ans);
        }
        
        return ans;
    }
};
