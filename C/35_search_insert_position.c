/*
 * Time complexity : O(log n)
 *
 * Space complexity : O(1)
*/

int searchInsert(int* nums, int numsSize, int target){

    int start = 0, end = numsSize -1;
    int tempindex=0;

    /* Binary Search the insertion Position. */
    while(start!=end)
    {
        tempindex = (start+end)/2;
        if(nums[tempindex]==target)
        {
            return tempindex;
        }
        else if(nums[tempindex]<target)
        {
            start = tempindex+1;
        }
        else
        {
            end=tempindex;
        }
    }
    if(nums[start]<target)
        return start+1;
    return start;
}