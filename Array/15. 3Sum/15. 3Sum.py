class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        res=[]

        # 1. 将原始数组进行快速排序
        nums.sort()

        # 2. 依次访问原始数组nums的每一个结点，将其作为三个数中的第一个加数
        for i in range(len(nums)):
            
            # 2.0 去重的第一个判定条件：若当前元素nums[i]和numss[i-1]相等（注意nums[i]是已经排序的数组），则无需再进行重复查找
            if i!=0 and nums[i]==nums[i-1]:
                continue
            
            # 2.1 现在问题转化为，查找数组nums中的两个值，这两个值相加等于-nums[i]
            pos1=i+1              # 去重的第二个判定条件：第一个指针pos1从下标i+1开始进行移动
            pos2=len(nums)-1

            # 2.2 移动游标指针pos1和pos2以查找到需要的两数之和
            while pos1<pos2:
                
                if nums[pos1]+nums[pos2]==-nums[i]:
                    res.append([nums[i],nums[pos1],nums[pos2]])

                    pos1+=1
                    pos2-=1

                    # 去重的第三个判定条件：指针pos1和指针pos2每一次指向的值不能出现重复，因此将pos1右移直到第一个与当前值nums[pos1]不相等的值，将pos2右移直到第一个与当前值nums[pos2]不相等的值
                    while pos1<pos2 and nums[pos1]==nums[pos1-1]:
                        pos1+=1
                    
                    while pos1<pos2 and nums[pos2]==nums[pos2+1]:
                        pos2-=1
                    
                elif nums[pos1]+nums[pos2]<-nums[i]:
                    pos1+=1
                else:
                    pos2-=1
                
            
        return res
                    
        