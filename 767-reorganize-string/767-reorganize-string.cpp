class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>> pq;
        for(char c : s){
            mp[c]++;
        }
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        
        while(pq.size() > 1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            ans += top1.second;
            ans += top2.second;
            top1.first--;
            top2.first--;
            if(top1.first) pq.push(top1);
            if(top2.first) pq.push(top2);
        }
        if(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(top.first > 1)return "";
            else ans += top.second;
        }
        return ans;
    }
};