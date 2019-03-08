
# 本题为数组问题中的最经典问题，如果答不出来基本就是面试一轮游
# 本题至少掌握两种方法，第一种是先使用快速排序，然后使用双指针法求解，时间复杂度为O(nlogn)，空间复杂度为O(1)；第二种是使用哈希表（python中的哈希表是dict类型，cpp中的哈希表为unordered_map），时间复杂度为O(n)，空间复杂度为O(1)
# 下面主要介绍第二种方法：算法基本思路：遍历一次数组num，对于遍历到的数组元素nums[i]，首先判断哈希表中是否存在值target-nums[i]，若存在，将下标i和下标dic[target-nums[i]]加入结果中并返回，若不存在，则将键值对"nums[i] - i"，加入哈希表dict中


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        dic={}

        res=[]

        for i in range(len(nums)):
            if target-nums[i] in dic:
                res.append(dic[target-nums[i]])
                res.append(i)
            
            else:
                dic[nums[i]]=i;
        
        return res;
        