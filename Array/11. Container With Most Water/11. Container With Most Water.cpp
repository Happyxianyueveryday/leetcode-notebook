
// 较为典型的题目，本题和栈tag下的接雨水一题类似，但是需要注意数组元素所表示的线本身没有体积，不会影响接水的多少
// 最基本的暴力解法就是每两条不同的线之间进行组合，时间复杂度为O(n^2)，
// 基本算法思路：本题经过双指针法tag提示可以想到使用双指针法进行求解：
//              1. 创建两个指针，指针pos1指向数组的首元素，指针pos2指向数组的末元素，创建最大盛水值res，初始化res=0
//              2. 计算由两个指针指向的数组元素的盛水值v=min(height[pos1],height[pos2])*(pos2-pos1)
//              3. 若当前两个元素的盛水值v大于之前的最大盛水值res，则更新res=v
//              4. 更新指针pos1和pos2，若height[pos1]<height[pos2]，则向右移动pos1直到第一个大于pos1的元素为止；若height[pos1]>height[pos2]，则向左移动pos2直到第一个大于pos2的元素为止


//  附注：更新pos1和pos2时的规则为什么是这样？我们可以按照如下方式考虑：
//        1. 若在pos1右侧的元素小于pos1，且在pos2左侧的元素小于pos2，这时可以确定这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量，故可以不计算
//        2. 若在pos1右侧的元素大于pos1，且在pos2左侧的元素大于pos2，这时这两个元素组成的容器的盛水量可能大于pos1和pos2组成的盛水量，故需要计算来验证
//        3. 若在pos1右侧的元素大于pos1，且在pos2左侧的元素小于pos2，若pos2<pos1，则无需进行计算，这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量，其他情况均不可确定，因此需要继续计算来验证
//        4. 若在pos1右侧的元素小于pos1，且在pos2左侧的元素大于pos2，若pos1<pos2，则无需进行计算，这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量，其他情况均不可确定，因此需要继续计算来验证
//        5. 综上所述，只需要pos1右侧的元素和pos2左侧的元素中存在一个元素小于min(pos1,pos2)，则无需进行计算，这两个元素组成的容器的盛水量必然小于pos1和pos2组成的盛水量
//        6. 根据第5点的总结，因此移动双指针的规定为：若height[pos1]<height[pos2]，则向右移动pos1直到第一个大于pos1的元素为止；若height[pos1]>height[pos2]，则向左移动pos2直到第一个大于pos2的元素为止

class Solution {
public:
    int maxArea(vector<int>& height) {

        // 1. 创建两个指针，指针pos1指向数组的首元素，指针pos2指向数组的末元素，创建最大盛水值res，初始化res=0
        int res=0;        // 历史最大盛水量
        int pos1=0;                  // 游标指针1
        int pos2=height.size()-1;    // 游标指针2

        // 2. 循环移动双指针直到pos1>=pos2时停止
        while(pos1<pos2)
        {
            // 2.1 计算由两个指针指向的数组元素的盛水值tempres=min(height[pos1],height[pos2])*(pos2-pos1)
            int tempres=((height[pos1]<height[pos2])?height[pos1]:height[pos2])*abs(pos1-pos2);

            // 2.2 若当前两个元素的盛水值tempres大于之前的最大盛水值res，则更新res=tempres
            res=(tempres>res)?tempres:res;

            // 2.3 更新双指针pos1和pos2，更新规则为；若height[pos1]<height[pos2]，则向右移动pos1直到第一个大于pos1的元素为止；若height[pos1]>height[pos2]，则向左移动pos2直到第一个大于pos2的元素为止
            // 附注: 关于为什么按照该规定移动双指针，请参见上述的注释部分
            if(height[pos1]<height[pos2])
            {
                int temp=pos1+1;
                while(temp!=pos2&&height[temp]<=height[pos1])
                {
                    temp+=1;
                }
                pos1=temp;
            }
            else
            {
                int temp=pos2-1;
                while(temp!=pos1&&height[temp]<=height[pos2])
                {
                    temp-=1;
                }
                pos2=temp;
            }
        }

        return res;
    }
};