#include <stdio.h>

int partitionSort(int nArray[], int nStart, int nEnd)
{
    int nPriot = nArray[nStart];
    while(nStart < nEnd) {
       while (nStart < nEnd && nArray[nEnd] >= nPriot) --nEnd;
       nArray[nStart] = nArray[nEnd];

       while(nStart < nEnd && nArray[nStart] < nPriot) ++nStart;
       nArray[nEnd] = nArray[nStart];
    }
    nArray[nStart] = nPriot;
    return nStart;

}

void quickSort(int nArray[], int nStart, int nEnd)
{
    if (nStart < nEnd) {
        int nMiddle = partitionSort(nArray, nStart, nEnd);
        quickSort(nArray, nStart, nMiddle - 1);
        quickSort(nArray, nMiddle + 1, nEnd);
    }
}

int main()
{
    int nArray[10] = {10, 2, 3, 6, 5, 4, 8, 7, 9, 1};
    int i;
    quickSort(nArray, 0, sizeof(nArray) / sizeof(nArray[0]));

    for (i = 0; 10 > i; i++) {
        printf("nArray[%d] == %d\n", i, nArray[i]);
    }
    return 0;
}

