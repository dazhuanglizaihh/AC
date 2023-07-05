class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};
        vector<long long> ans;
        for(long long i=2;i<=finalSum;i+=2) {
            ans.push_back(i);
            finalSum-=i;
        }
        ans.back()+=finalSum;
        return ans;
    }
};
