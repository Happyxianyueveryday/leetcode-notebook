

// 较为基础的题目，可以使用排序后再用双指针的标准解法，时间复杂度为O(nlogn)，这里给出使用哈希表的解法，时间复杂度为O(n)，需要特别注意cpp的哈希表为unordered_map而不是map
// 算法基本思路：遍历一遍给定的数组，对于每个数组元素num[i]，首先查找哈希表中是否存在键target-num[i]，若存在，直接返回该键对应的值；然后将该数组元素以"元素值-下标"的键值对的形式写入哈希表中
// 附注：为什么可以直接使用一遍遍历进行查找呢？因为加法的对称性，即使a+b=target，当a加入哈希表中时，b没有加入，这时也无关紧要，因为当b加入时，a已经加入哈希表，这时仍然可以查找到组合a+b符合要求

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> dic;    // 用于记录数字的字典，将数值num[i]作为键，下标i作为值

        vector<int> res;     // 结果数组

        for(int i=0;i<nums.size();i++)
        {
            // 先判断字典中是否存在与当前值nums[i]相加得到target的值
            if(dic.count(target-nums[i]))
            {
                res.push_back(dic[target-nums[i]]);
                res.push_back(i);

                return res;
            }

            // 然后将当前的数组元素值加入字典中
            dic[nums[i]]=i;
        }

        return res;
    }
};