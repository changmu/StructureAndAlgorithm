////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-18 20:21:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:588KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 100000 + 2
int arr[maxn]; 
int t, n, maxLeft, maxRight, maxSum, id = 1;

int max3(int a, int b, int c){
    if(a >= b && a >= c) return 1;
    if(b >= a && b >= c) return 2;
    if(c >= a && c >= b) return 3;
}

int maxSubsequenceSum(int left, int right, int *l, int *r){
    int thisLeft, thisRight;
    int leftSum, rightSum, midSum, mid;
    int leftBorderSum, maxLeftBorderSum;
    int rightBorderSum, maxRightBorderSum;
    int ll, lr, rl, rr, ml, mr;
    if(left == right){
		*l = *r = left;
		return arr[left];
	}
    mid = (left + right) / 2;
    leftSum = maxSubsequenceSum(left, mid, &ll, &lr);
    rightSum = maxSubsequenceSum(mid + 1, right, &rl, &rr);
    
    leftBorderSum = 0; thisLeft = mid;
    maxLeftBorderSum = arr[mid];
    for(int i = mid; i >= left; --i){
        leftBorderSum += arr[i];
        if(leftBorderSum >= maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
            thisLeft = i;
        }
    }
    rightBorderSum = 0; thisRight = mid + 1;
    maxRightBorderSum = arr[mid + 1];
    for(int i = mid + 1; i <= right; ++i){
        rightBorderSum += arr[i];
        if(rightBorderSum > maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
            thisRight = i;
        }
    }
    midSum = maxLeftBorderSum + maxRightBorderSum;   
    
    int sign = max3(leftSum, midSum, rightSum);
    
    if(sign == 1){
       maxSum = leftSum;
       *l = ll;
	   *r = lr;
    }else if(sign == 2){
        maxSum = midSum;
        *l = thisLeft;
		*r = thisRight;
    }else{
        maxSum = rightSum;
        *l = rl;
		*r = rr;
    }
    return maxSum;
}

int main(){    
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        maxSum = arr[0];
        maxLeft = maxRight = 0;
        maxSubsequenceSum(0, n - 1, &maxLeft, &maxRight);
        printf("Case %d:\n%d %d %d\n", id++, maxSum, maxLeft + 1, maxRight + 1);
        if(t) printf("\n");
    }
    return 0;
}