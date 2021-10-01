/*
 * Time complexity : O(log n)
 *
 * Space complexity : O(1)
*/

int search(int* nums, int numsSize, int target){

    int start = 0, end = numsSize-1;
    int index = -1;
    int tempindex = 0;

    /* Binary Search the Array */
    while(start!=end)
    {
        tempindex = (start+end)/2;
        if(nums[tempindex]==target)
        {
            return tempindex;
        }
        else if(nums[tempindex]<target)
        {
            start = tempindex + 1;
        }
        else
        {
            end = tempindex;
        }
    }
    if(start == end)
    {
        if(nums[start]==target)
            return start;
    }
    return index;
}