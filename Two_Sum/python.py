class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashMap = {nums[i]:i for i in range(len(nums))}
        for i in range(len(nums)):
            if target-nums[i] in hashMap and hashMap[target-nums[i]] != i:
                result = [i, hashMap[target-nums[i]]]; break
        return result
