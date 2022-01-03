/*
 * Time complexity : O(n)
 *
 * Space complexity : O(1)
*/

int romanToInt(char * s){

    int strLength = 0;
	
	/* Find String Length */
    while(s[strLength]!='\0')
        strLength++;
    
	/* Keep track of last encountered roman numerical and final number */
    int final_number =0;
    int last_number = 0;
	
	/* Loop through entire string from left to right. */
	/* Calculate numerical value as u encounter digit, value will decrease if a smaller numerical comes 
	before a larger numerical, else will increase. Store the current encontered number for next iteration. */
    while(strLength>=0)
    {
        if(s[strLength]=='I')
        {
            final_number = (last_number>1) ? (final_number-1) : (final_number+1);
            last_number = 1;
        }
        else if(s[strLength]=='V')
        {
            final_number = (last_number>5) ? (final_number-5) : (final_number+5);
            last_number = 5;
        }
        else if(s[strLength]=='X')
        {
            final_number = (last_number>10) ? (final_number-10) : (final_number+10);
            last_number = 10;
        }
        else if(s[strLength]=='L')
        {
            final_number = (last_number>50) ? (final_number-50) : (final_number+50);
            last_number = 50;
        }
        else if(s[strLength]=='C')
        {
            final_number = (last_number>100) ? (final_number-100) : (final_number+100);
            last_number = 100;
        }
        else if(s[strLength]=='D')
        {
            final_number = (final_number+500);
            last_number = 500;
        }
        else if(s[strLength]=='M')
        {
            final_number = (final_number+1000);
            last_number = 1000;
        }
        strLength--;
    }
    
    return final_number;
}