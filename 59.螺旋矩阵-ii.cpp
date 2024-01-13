/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {

        std::vector<std::vector<int>> res(n,std::vector<int>(n));
        int k=1;
        for(int i=0;i<n/2;i++){
            int row=i,col=i;
            while(col<n-i-1){
                res[row][col++]=k++;
            }
            while(row<n-i-1){
                res[row++][col]=k++;
            }
            while(col>i){
                res[row][col--]=k++;
            }
            while(row>i){
                res[row--][col]=k++;
            }
        }
        if(n%2!=0){
            res[n/2][n/2]=k;
        }
        return res;

    }
};
// @lc code=end

