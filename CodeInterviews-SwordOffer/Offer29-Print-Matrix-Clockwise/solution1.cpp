class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (!matrix.size()) return {};

        vector<int> vec;
        vec.reserve(matrix.size() * matrix[0].size());    // 先分配好内存（性能++）

        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;    // 初始化上下左右边界
        while (true) {       // 每次循环打印最外层 （当不构成范围时，循环终止）

            for (int i = left; i <= right; ++i) {     // 从左到右，打印top行
                vec.push_back(matrix[top][i]);
            }
            if (++top > bottom) break;    // 打印完top行后,top++ （缩小上边界）
            
            for (int i = top; i <= bottom; ++i) {     // 从上到下，打印right列
                vec.push_back(matrix[i][right]);
            }
            if (--right < lef) break;    // 打印完right列后,right-- （缩小右边界）

            for (int i = right; i >= left; --i) {     // 从右到左，打印bottom行
                vec.push_back(matrix[bottom][i]);
            }
            if (--bottom < top) break;    // 打印完bottom行后,bottom-- （缩小下边界）

            for (int i = bottom; i >= top; --i) {     // 从下到上，打印left列
                vec.push_back(matrix[i][left]);
            }
            if (++left > right) break;    // 打印完left列后,left-- （缩小左边界）
        }

        return vec;
    }
};t
