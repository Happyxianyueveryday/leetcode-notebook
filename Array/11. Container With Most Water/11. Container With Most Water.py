# 较为典型的题目，本题和栈tag下的接雨水一题类似，但是需要注意数组元素所表示的线本身没有体积，不会影响接水的多少
# 最基本的暴力解法就是每两条不同的线之间进行组合，时间复杂度为O(n^2)，
# 基本算法思路：本题经过双指针法tag提示可以想到使用双指针法进行求解：
#              1. 创建两个指针，指针pos1指向数组的首元素，指针pos2指向数组的末元素，创建最大盛水值res，初始化res=0
#              2. 计算由两个指针指向的数组元素的盛水值v=min(height[pos1],height[pos2])*(pos2-pos1)
#              3. 若当前两个元素的盛水值v大于之前的最大盛水值res，则更新res=v
#              4. 更新指针pos1和pos2，若height[pos1]<height[pos2]，则向右移动pos1直到第一个大于pos1的元素为止；若height[pos1]>height[pos2]，则向左移动pos2直到第一个大于pos2的元素为止


#  附注：更新pos1和pos2时的规则为什么是这样？我们可以按照如下方式考虑：
#        1. 若在pos1右侧的元素小于pos1，且在pos2左侧的元素小于pos2，这时可以确定这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量，故可以不计算
#        2. 若在pos1右侧的元素大于pos1，且在pos2左侧的元素大于pos2，这时这两个元素组成的容器的盛水量可能大于pos1和pos2组成的盛水量，故需要计算来验证
#        3. 若在pos1右侧的元素大于pos1，且在pos2左侧的元素小于pos2，若pos2<pos1，则无需进行计算，这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量，其他情况均不可确定，因此需要继续计算来验证
#        4. 若在pos1右侧的元素小于pos1，且在pos2左侧的元素大于pos2，若pos1<pos2，则无需进行计算，这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量，其他情况均不可确定，因此需要继续计算来验证
#        5. 综上所述，只需要pos1右侧的元素和pos2左侧的元素中存在一个元素小于min(pos1,pos2)，则无需进行计算，这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量
#        6. 根据第5点的总结，因此移动双指针的规定为：若height[pos1]<height[pos2]，则向右移动pos1直到第一个大于pos1的元素为止；若height[pos1]>height[pos2]，则向左移动pos2直到第一个大于pos2的元素为止


class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # 1. 创建两个指针，指针pos1指向数组的首元素，指针pos2指向数组的末元素，创建最大盛水值res，初始化res=0
        res=0
        pos1=0
        pos2=len(height)-1

        # 2. 遍历数组height，循环进行下列的操作，直到pos1>=pos2时停止，这时退出循环
        while pos1<pos2:
            # 2.1 计算pos1和pos2指向的元素所围成的容器的盛水量
            tempres=min(height[pos1],height[pos2])*abs(pos1-pos2)

            # 2.2 判断tempres和res的大小关系，若tempres>res，则更新res=tempres
            res=tempres if tempres>res else res

            # 2.3 更新指针pos1和pos2，更新规则为：若height[pos1]<=height[pos2]，则更新pos1为pos1右侧第一个大于height[pos1]的数组元素的下标；若height[pos1]>height[pos2]，则更新pos2为pos2左侧第一个大于height[pos2]的数组元素的下标
            if height[pos1]<=height[pos2]:
                for i in range(pos1+1,pos2+1):
                    if height[i]>height[pos1]:
                        pos1=i
                        break
                pos1=i
            else:
                for i in range(pos2-1,pos1-1,-1):
                    if height[i]>height[pos2]:
                        pos2=i
                        break
                pos2=i
        

        return res
