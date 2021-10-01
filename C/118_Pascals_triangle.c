/*
 * Time complexity : O(n) where n =  Rows * Cols of original matrix.
 *
 * Space complexity : O(n) where n =  Rows * Cols of original matrix.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){

	/* Allocate an array of Pointers, Each index will hold a row. */
    int** returnArray = (int**)malloc(numRows*sizeof(int*));
	
    /* Allocate an array to store the number of columns for each row. */
	*returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
	
    /* Return the number of rows of Pascal triangle. */
	*returnSize = numRows;
    
    /* Loop for all rows. */
    for(int i = 0; i<numRows; i++)
    {
		/* Allocate memory for the row. Number of columns will change per row. */
        returnArray[i] = (int*)malloc((i+1)*sizeof(int));
        
		/* Store the column size for the corresponding row index. */
        (*returnColumnSizes)[i]=i+1;
        
		/* First Column and Last column of each row is prefilled to 1. */
        returnArray[i][0]=1;
        if(i!=0)
            returnArray[i][i]=1;
        
		/* Loop from second column to the second last column and fill data as sum of previous row. */
        for(int j=1;j<i;j++)
        {
            returnArray[i][j]= returnArray[i-1][j-1]+returnArray[i-1][j];
        }
    }
    
    return returnArray;
}