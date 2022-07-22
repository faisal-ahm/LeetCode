class Solution {
public:
int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    int m = 1e9+7;
    priority_queue<vector<int>>buy;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>sell;
        
    for(auto o : orders){
        if(o[2] == 0){
            buy.push(o);
        }else{
            sell.push(o);
        }
            
        while(!buy.empty() && !sell.empty() && buy.top()[0] >= sell.top()[0]){
            int k = min(buy.top()[1], sell.top()[1]);
            vector<int>temp = buy.top();
            buy.pop();
            temp[1]-=k;
            if(temp[1])buy.push(temp);
                
            temp = sell.top();
            sell.pop();
            temp[1]-=k;
            if(temp[1])sell.push(temp);
        }
    }
    int ans = 0;
    while(buy.size()){
        ans = (ans + buy.top()[1])%m;
        buy.pop();
    }
    while(sell.size()){
        ans = (ans + sell.top()[1])%m;
        sell.pop();
    }
    return ans;
}
};