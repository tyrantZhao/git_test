#include <stdio.h>

void adjustHeap(int nArray[], int nStart, int nEnd)
{
    if (NULL == nArray) return;
    if (0 > nStart || 0 > nEnd) return;
    if (nEnd < nStart) return;

    int i, nTemp;
    nTemp = nArray[nStart];

    for (i = 2 * nStart + 1; i < nEnd; i = 2 * i + 1) {
        if (i + 1 < nEnd && nArray[i] < nArray[i + 1]) i++;

        if (nTemp > nArray[i]) {
            break;
        } else {
            nArray[nStart] = nArray[i];
            nStart = i;
        }
    }

    nArray[nStart] = nTemp;
}

void sortHeap(int nArray[], int nLen)
{
    if (NULL == nArray) return;
    if (0 > nLen) return;

    int i, nTemp;
    for(i = nLen / 2 - 1; 0 <= i; i--) {
        adjustHeap(nArray, i, nLen);
    }

    for (i = nLen - 1; 0 < i; i--) {
        nTemp = nArray[0];
        nArray[0] = nArray[i];
        nArray[i] = nTemp;
        adjustHeap(nArray, 0, i);
    }
}

int main()
{
    int nArray[10] = {2, 10, 9, 8, 7, 6, 5, 4, 1, 3};
    sortHeap(nArray, sizeof(nArray) / sizeof(nArray[0]));

    for (int i = 0; 10 > i; ++i) {
        printf("nArray[%d] = %d \n", i, nArray[i]);
    }

    return 0;
}
