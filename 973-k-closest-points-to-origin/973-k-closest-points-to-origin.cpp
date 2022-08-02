class Solution {
public:
    struct compare {
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), compare());
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};