/*
 * Time complexity : O(n)
 *
 * Space complexity : O(n)
*/

int* sortedSquares(int* nums, int numsSize, int* returnSize){

	/* Allocate Return Array*/
    int *returnArray = (int *) malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int start = 0, end =numsSize-1;
    int temp =0;
    
	/* Find position where negative numbers end */
    while(start<end)
    {
        temp = (start+end)/2;
        if(nums[temp]>=0)
            end = temp;
        else
            start = temp + 1;
    }
    start--;
	
    int sqn=0, sqp=0;
	/* calculate squares from both ends. Place the smaller squared one to the beginning*/ 
    for(int i = 0; i<numsSize; i++)
    {
        sqn = sqp = INT_MAX;
        if(start>=0)
            sqn = nums[start]*nums[start];
        if(end<numsSize)
            sqp = nums[end]*nums[end];
        
        if(sqn>sqp)
        {
            returnArray[i]=sqp;
            end++;
        }
        else
        {
            returnArray[i]=sqn;
            start--;
        }
    }
    
    return returnArray;
}