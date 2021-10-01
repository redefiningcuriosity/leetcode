/*
 * Time complexity : O(n) where n =  Rows * Cols of original matrix.
 *
 * Space complexity : O(n) where n =  Rows * Cols of Return matrix.
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int matR = 0, matC = 0;
        
        /* If Result Matrix cannot be formed, force result matrix to be of same as source matrix. */
        if((mat.size()*mat[0].size()) != (r*c))
        {
            r=mat.size();
            c=mat[0].size();
        }

        /* Allocate an vector of Integer vectors to store the Rows. */
        vector<vector<int>> returnMat;
        
        /* Loop through each row of Result Matrix. */
        for(int returnMatr=0, returnMatc=0; returnMatr<r; returnMatr++)
        {
            /* Alocate a row for Result Matrix. */
            vector<int> vecC;

            /* We have to fill from Column 0 for the allocated row. */
            returnMatc=0;

            /* Loop through all columns of the allocated row. */
            while(returnMatc<c)
            {
                /* Fill Return Matrix from Source Matrix. Increment Source Matrix columns by 1.*/
                vecC.push_back(mat[matR][matC++]);
                returnMatc++;

                /* Change Row of Source Matrix when Column of Source Matrix reaches end. */
                if(matC == (mat[matR].size()))
                {
                    matR++;
                    matC=0;
                }
            }
            /* Push row into the parent Vector. */
            returnMat.push_back(vecC);
        }

        return returnMat;
    }
};