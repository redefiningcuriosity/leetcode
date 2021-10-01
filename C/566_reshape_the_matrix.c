/*
 * Time complexity : O(n) where n =  Rows * Cols of original matrix.
 *
 * Space complexity : O(n) where n =  Rows * Cols of Return matrix.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){

    /* If Result Matrix cannot be formed, force result matrix to be of same as source matrix. */
    if((matSize*(*matColSize) != r*c))
    {
        r=matSize;
        c= *matColSize;
    }
    
    int matR = 0;
    int matC = 0;
    int returnMatr = 0;
    int returnMatc = 0;
    
    /* Return the number of rows in the Result Matrix. */
    *returnSize = r;

    /* Allocate an array to return the column sizes of each row. */
    *returnColumnSizes = (int*) malloc(r*sizeof(int*));

    /* Allocate an array of Integer ointers to store the Row arrays. */
    int** returnMat = (int*)malloc(r*sizeof(int*));
    
    /* Loop through each row of Result Matrix. */
    for(int returnMatr=0; returnMatr<r; returnMatr++)
    {
        /* Assign Column Size to the returnColumnSizes Array. */
        (*returnColumnSizes)[returnMatr] = c;

        /* Alocate a row for Return Matrix. */ 
        returnMat[returnMatr] = (int*)malloc(c*sizeof(int));

        /* We have to fill from Column 0 for the allocated row. */
        returnMatc=0;

        /* Loop through all columns of the allocated row. */
        while(returnMatc<c)
        {
            /* Fill Return Matrix from Source Matrix. Increment Source Matrix columns by 1.*/
            returnMat[returnMatr][returnMatc] = mat[matR][matC++];
            returnMatc++;

            /* Change Row of Source Matrix when Column of Source Matrix reaches end. */
            if(matC == (*matColSize))
            {
                matR++;
                matC=0;
            }
        }
    }
    
    return returnMat;
}