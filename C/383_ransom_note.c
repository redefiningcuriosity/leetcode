/*
 * Time complexity : O(n) where n =  maximum size of ransomNote, magazine.
 *
 * Space complexity : O(1) . A fixed alphabet array is declated of size 26.
*/

bool canConstruct(char * ransomNote, char * magazine){

    /* Create a 26-alphabet array and pre-fill to 0. */
    int arr[26];
    for(int i = 0; i<26; i++)
    {
        arr[i]=0;
    }
    /*  Loop till end of the strings. 
        In case of Ransom Occurence, increase the count.
        In case of Magazine Occurence, decrease the count.
    */
    int index=0;
    while(ransomNote[index]!='\0' && magazine[index]!='\0')
    {
        arr[ransomNote[index]-'a']++;
        arr[magazine[index]-'a']--;
        index++;
    }
    
    if(ransomNote[index]!='\0')
    {
        while(ransomNote[index]!='\0')
        {
            arr[ransomNote[index]-'a']++;
            index++;
        }
    } else if(magazine[index]!='\0')
    {
        while(magazine[index]!='\0')
        {
            arr[magazine[index]-'a']--;
            index++;
        }
    }
    
    /*  Check Alphabet Array if anywhere value is positive, return false as ransom not 
        had occurence which was not reduced by magazine. 
    */
    for(int i = 0; i<26; i++)
    {
        if(arr[i]>0)
            return 0;
    }
    
    return 1;
}