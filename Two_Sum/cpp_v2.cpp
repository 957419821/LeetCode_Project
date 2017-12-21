//unordered_map用来散列

#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using namespace std;
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++)
            myMap[nums[i]] = i;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
            if(myMap.find(target - nums[i]) != myMap.end() && myMap[target-nums[i]] != i){
                result.push_back(i);
                result.push_back(myMap[target-nums[i]]);
                break;
            }
        return result;
    }
};
