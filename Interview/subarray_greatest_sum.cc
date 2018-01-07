#include <iostream>

int nGreatestSum = 0;
int nStart, nEnd;

bool findGreatestSumOfSubArray(int* pData, size_t nSize)
{
    if (nullptr == pData || 0 >= nSize)
        return false;

    int k = 0;
    int nCurSum = 0;

    for (int i = 0; nSize > i; ++i) {
        nCurSum += pData[i];
        if (0 > nCurSum) {
            nCurSum = 0;
            k = i + 1;
        }
        if (nCurSum > nGreatestSum) {
            nGreatestSum = nCurSum;
            nStart = k;
            nEnd = i;
        }
    }

    if (0 == nGreatestSum) {
        nGreatestSum = pData[0];

        for (int i = 1; nSize > i; ++i) {
            if (nGreatestSum < pData[i]) {
                nGreatestSum = pData[i];
                nStart = i;
                nEnd = i;
            }
        }
    }

    return true;
}

//使用动态规划思想
int findGreatestSumOfSubArray2(int* pData, size_t nSize)
{
    int nGreatestSum = -100000000;

    if (nullptr == pData || 0 >= nSize)
        return nGreatestSum;

    int nCurSum = 0;
    for(size_t i = 0; nSize > i; ++i) {
        //前n个数之和，为0说明对子数组连续和无贡献，修正
        nCurSum = std::max(nCurSum + pData[i], 0);
        if (0 == nCurSum) {
            //修正过后，连续和与当前元素比较
            nGreatestSum = std::max(nGreatestSum, pData[i]);
        } else {
            //无修正，与前n个数和比较
            nGreatestSum = std::max(nGreatestSum, nCurSum);
        }
    }

    return nGreatestSum;
}

int main()
{
    int array[10] = {0, 3, -1, 10, -5, -1, 2, -2, 1, 0};

    if (!findGreatestSumOfSubArray(array, sizeof(array) / sizeof(array[0]))) {
        std::cout << "invalid argument!"<< std::endl;
    }

    std::cout << " nGreatestSum : " << nGreatestSum << std::endl;

    std::cout << "DP : nGreatestSum1 : " << findGreatestSumOfSubArray2(array, sizeof(array) / sizeof(array[0])) << std::endl;
    return 0;
}
