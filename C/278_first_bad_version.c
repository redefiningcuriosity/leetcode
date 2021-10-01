/*
 * Time complexity : O(log n)
 *
 * Space complexity : O(1)
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    long start = 1, end = n;
    int vs=0;

    /* Binary Search till you find Bad Version. */
    while(start != end)
    {
        vs = (int)((start+end)/2);
        
        if(isBadVersion(vs))
            end = vs;
        else
            start = vs+1;
    }
    return (int)start;
}