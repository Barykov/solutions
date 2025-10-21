#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;

        // Начинаем с предпоследней строки и идём вверх
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};

// Пример использования
int main() {
    // Пример 1 из условия
    vector<vector<int>> triangle1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    Solution sol;
    cout << "Пример 1: " << sol.minimumTotal(triangle1) << endl; // Ожидаем 11

    // Пример 2 из условия
    vector<vector<int>> triangle2 = {
        {-1},
        {2, 3},
        {1, -1, -3},
        {4, 2, 1, 3}
    };

    cout << "Пример 2: " << sol.minimumTotal(triangle2) << endl; // Ожидаем 0

    return 0;
}
}
