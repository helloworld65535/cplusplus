#include <iostream>
#include <vector>

/**
 * @brief 在源字符串中找出目标字符串的第一个匹配项的下标（下标从 0 开始）
 */
class Solution
{
public:
    int BF(std::string S, std::string T)
    {
        size_t SLength = S.length();
        size_t TLength = T.length();
        if (TLength == 0)
            return 0;
        if (SLength < TLength)
            return -1;

        for (size_t i = 0; i + TLength < SLength; i++)
        {
            bool flag = true;
            for (size_t j = 0; j < TLength; j++)
            {
                if (S[i + j] != T[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
    /**
     * @brief 在源字符串中找出目标字符串的第一个匹配项的下标（下标从 0 开始）
     * 》》KMP算法《《
     * @param S 源字符串
     * @param T 目标字符串
     * @return 匹配项的下标（下标从 0 开始），无匹配项返回 0
     */
    int KMP(std::string S, std::string T)
    {
        size_t SLength = S.length();
        size_t TLength = T.length();

        if (TLength == 0)
            return 0;
        if (SLength < TLength)
            return -1;

        // 构造前缀表
        std::vector<size_t> next(TLength);
        for (size_t i = 1, j = 0; i < TLength; i++)
        {
            while (j > 0 && T[i] != T[j])
                j = next[j - 1];
            if (T[i] == T[j])
                ++j;
            next[i] = j;
        }

        // 匹配
        for (size_t i = 0, j = 0; i < SLength; i++)
        {
            while (j > 0 && S[i] != T[j])
                j = next[j - 1];
            if (S[i] == T[j])
                ++j;
            if (TLength == j)
                return (i - TLength + 1);
        }

        return -1;
    }
};
int main(void)
{
    std::string str;
    std::string target;

    std::cout << "S string:" << std::endl;
    std::cin >> str;
    std::cout << "T string:" << std::endl;
    std::cin >> target;
    
    std::cout << Solution().KMP(str, target) << std::endl;

    return 0;
}