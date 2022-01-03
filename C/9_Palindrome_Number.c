/*
 * Time complexity : O(n)
 *
 * Space complexity : O(1)
*/

bool isPalindrome(int x){
	/* All negative numbers and multiples of 10 are not pallindrome */
    if(x<0 || (x!=0 && x%10 == 0))
        return false;
    
    int x_back=0;
    int temp;
	/* Loop till half of digits. Store half in x_back */
    while(x>x_back)
    {
        temp=x%10;
        x=x/10;
        x_back=(x_back*10)+temp;
    }
    
    /* In case of even number of digits first condition is valid. 
	If number of digits is odd, remove last digit and compare */
    if(x_back==x || x == (x_back/10))
        return true;
    else
        return false;
}