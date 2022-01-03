/*
 * Time complexity : O(n)
 *
 * Space complexity : O(n)
*/
char * longestCommonPrefix(char ** strs, int strsSize){
    
    int prefix = 0;
    int iterator = 0;
	
    /* Loop till a string ends or a mismatch occurs. */
    while(1)
    {
		/* Take current charachter. */
        char c = strs[0][prefix];
        int flag = 0;
		
		/* Loop through all available strings. */
        for(iterator=0; iterator<strsSize; iterator++)
        {
			/* Check if string has ended or charachter mismatch happens */
            if(strs[iterator][prefix]!=c || strs[iterator][prefix]=='\0')
            {
                flag = 1;
                break;
            }
        }
		
		/* Break if string has ended or charachter mismatch has happened. */
        if(flag)
            break;
			
		/* Increment prefix otherwise. */
        prefix++;
    }
     
	/* Allocate memory for available prefix and copy from any string. */
    char* returnString = (char*)malloc((prefix+1)*sizeof(char));
    for(iterator = 0; iterator<prefix; iterator++)
    {
        returnString[iterator]=strs[0][iterator];
    }
	
	/* End array with NULL. */
    returnString[iterator]='\0';
	
    return returnString;
}