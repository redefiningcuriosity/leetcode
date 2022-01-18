/*
 * Time complexity : O(n)
 *
 * Space complexity : O(1)
*/

void rotate(int* nums, int numsSize, int k){

	/* Bring K less than array size. Full circular loop will give same array.*/
    k=k%numsSize;
    
    if(k==0)
        return;
    
    long startPos = 0, numsTraversed = 0, tobenum = nums[0], temp = 0, tobePos = k, currentPos=0;
    
	/* Traverse till all index has been rotated atleast once. */
    while(numsTraversed<numsSize)
    {
		
        temp = nums[tobePos];
        nums[tobePos] = tobenum;
        tobenum = temp;
        tobePos += k;
        if(tobePos>=numsSize)
        {
            tobePos -= numsSize;
			/* If after one round you land in a previously rotated position, select next position to rotate*/
            if(tobePos == startPos)
            {
                nums[tobePos] = tobenum;
                tobenum = nums[++startPos];
                tobePos = startPos;
            }
                
        }
        numsTraversed++; 

    }
        
}