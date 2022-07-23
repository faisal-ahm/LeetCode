class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        long long left[n],right[n]; //stores index of the first num smaller than arr[i] from right and from left
        //boundaries for arr[i] to form a rectange
        
        stack<long long> st; //we store indexes in the stack
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            if(st.empty()) left[i]=-1;
            else{
                left[i]= st.top();
            }
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            if(st.empty()) right[i]=n;
            else
            {
                 right[i]=st.top();
            }
            st.push(i);
            
            }
            
            long long ans=0,area=0;
            for(int i=0;i<n;i++)
            {
                area=(right[i]-left[i]-1)*arr[i];
                ans=max(ans,area);
            }
            
           
            return ans;
    }
    
};