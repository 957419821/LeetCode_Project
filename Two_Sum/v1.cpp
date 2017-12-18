/*
    思路：
        来源：hash
        步骤：
            1. 取原数列nums中的最小值min和最大值max；
            2. 更新target：new_target = target - 2*min；
            3. 创建长度为max+1的新数列，并初始化为其长度值；
            4. 在新数列中，把位置 nums[i]-min 处的值改为 newtarget-nums[i] + min；
               这样，就会使该数列有价值的地方存在：indice+value=target；
            5. 寻找满足条件 newArray[newArray[i]] = i 的i；
            6. 查找i和newArray[i]在原数列中的位置；
            7. 返回上面得到的位置。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int min = getMin(nums);
        int max = getMax(nums);
        int newTarget = target - 2 * min;
        int newLength = max - min + 1;
        int newArray[newLength];
        vector<int> result = {newLength, newLength};
        //initial newArray with newLength
        for(int i = 0; i < newLength; i++)
            newArray[i] = newLength;
        //set value to the differ between newTarget and (nums[i]-min) in position (nums[i]-min)
        for(int i = 0; i < nums.size(); i++)
            newArray[nums[i] - min] = newTarget - nums[i] + min;
        //search value that satisfies newArray[newArray[value]] = value
        int value = newLength;
        for(int i = 0; i < newLength; i++){
            if(newArray[i] > (newLength - 1) || newArray[i] < 0) continue;
            if(newArray[newArray[i]] == i) {value = i; break;}
        }
        //search indices for values
        if(value == newLength) return result;
        for(int i = 0; i < nums.size(); i++)
            if((value + min) == nums[i]){result[0] = i; break;}
        for(int i = 0; i < nums.size(); i++)
            if((target - value - min) == nums[i] && i != result[0]){result[1] = i; break;}
        return result;
    }
private:
    int getMin(vector<int>& nums){
        int min = nums[0];
        for(int i = 1; i < nums.size(); i++)
            if(min > nums[i])
                min = nums[i];
        return min;
    }
    int getMax(vector<int>& nums){
        int max = nums[0];
        for(int i = 1; i < nums.size(); i++)
            if(max < nums[i])
                max = nums[i];
        return max;
    }
};
