#include<stdio.h>
char firstsingle(char *arr)
{
    char asc[255] = {0};
    int i = 0;
    for(; arr[i] != '\0'; i++){
      asc[arr[i]]++;
    }

    for(i = 0; arr[i] != '\0';i++) {
        if(asc[arr[i]] == 1) {
            return arr[i];
        }
    }

    return '\0';
}

int main()
{
    char arr[10];
    char ret;
    scanf("%s",&arr);
    ret = firstsingle(arr);
    printf("%c\n",ret);
    return 0;
}
