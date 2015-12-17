#include <myLinux.h>

#define MAX_LEN 4096

void myQuickSort(int *arr, int begin, int end);

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s <inputFile> <outputFile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int arr[MAX_LEN];
    int i = 0, j;

    int fd1 = open(argv[1], O_RDONLY);
    dup2(fd1, STDIN_FILENO);
    int fd2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
    dup2(fd2, STDOUT_FILENO);

    while (~scanf("%d", arr + i)) ++i;

    myQuickSort(arr, 0, i); // [,)

    for (j = 0; j != i; ++j)
        printf("%d ", arr[j]);

    return 0;
}

int myQuickSortCore(int *arr, int begin, int end)
{
    int tmp = arr[begin];

    while (begin + 1 < end) {
        while (begin + 1 < end && arr[end-1] >= tmp) --end;
        arr[begin] = arr[end-1];
        while (begin + 1 < end && arr[begin] <= tmp) ++begin;
        arr[end-1] = arr[begin];
    }
    arr[begin] = tmp;

    return begin;
}

void myQuickSort(int *arr, int begin, int end)
{
    if (begin + 1 >= end) return;

    int pivot = myQuickSortCore(arr, begin, end);
    myQuickSort(arr, begin, pivot);
    myQuickSort(arr, pivot + 1, end);
}
