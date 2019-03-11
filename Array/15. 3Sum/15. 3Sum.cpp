

// 本题最简单的方法就是使用两次2Sum的解法，先将数组元素加入哈希表中，然后对于数组中的每一个元素nums[i]，求解剩下的数组中是否存在两个数的和等于-nums[i]（将问题转换为2Sum），时间复杂度为O(n^2)，空间复杂度为O(n)
// 但是上述算法在计算过程中，虽然能够找到所有的三数之和等于0，但是会出现大量重复，因此还要花费额外的时间去进行去重
// 因此我们推荐使用传统的双指针法解决转化后的2Sum问题，而不是使用哈希表，在双指针法中，可以通过精确的条件设计和判断来保证不产生重复，而上述方法则只能使用set这样的数据结果来保证不产生重复结果

// 基本算法思路：注意去重的三个条件
// 1. 将数组使用快速排序进行排序
// 2. 遍历整个数组，对于数组元素nums[i]，执行下面的算法步骤：若排序后nums[i]!=nums[i-1]，则在下标范围[i+1, nums.size()-1]内查找两个数组元素之和等于-nums[i]以避免重复
// 3. 创建两个游标指针pos1和pos2，将pos1初始化

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;     // 结果数组

        // 1. 将原始输入数组进行排序
        sort(nums.begin(),nums.end());

        // 2. 遍历整个数组的每一个元素nums[i]
        for(int i=0;i<nums.size();i++)
        {
            // 附注： 请特别注意如下步骤中，去重的三个判断条件，缺一不可
            // 2.0 因为数组经过排序，因此若nums[i]已经在前面出现过，则必定有nums[i]==nums[i-1]，这时无需再次计算nums[i]，这是去重的第一个判断条件
            if(i!=0&&nums[i]==nums[i-1])
                continue;  

            // 2.1 问题转换为在下标范围[i+1,nums.size()-1]内查找数组的两个数之和等于-nums[i]，这是去重的第二个判断条件
            int pos1=i+1;  
            int pos2=nums.size()-1;

            // 2.2 使用双指针法查找相加等于-nums[i]的数组元素
            // 附注：在双指针pos1和pos2移动时，同样需要避免重复，即若计算了pos1和pos2的结果后，需要将pos1前移直到第一个与当前值nums[pos1]不相等的位置，需要将pos2后移直到与第一个与当前值nums[pos2]不相等的位置
            while(pos1<pos2)
            {
                if(nums[pos1]+nums[pos2]==-nums[i])
                {
                    vector<int> tempres;
                    tempres.push_back(nums[i]);
                    tempres.push_back(nums[pos1]);
                    tempres.push_back(nums[pos2]);
                    res.push_back(tempres);

                    pos1+=1;
                    pos2-=1;

                    while(pos1<pos2&&nums[pos1]==nums[pos1-1])
                    {
                        pos1+=1;
                    }
                    while(pos1<pos2&&nums[pos2]==nums[pos2+1])
                    {
                        pos2-=1;
                    }
                }
                else if(nums[pos1]+nums[pos2]<-nums[i])
                {
                    pos1+=1;
                }
                else if(nums[pos1]+nums[pos2]>-nums[i])
                {
                    pos2-=1;
                }
            }
        }

        return res;
    }
};