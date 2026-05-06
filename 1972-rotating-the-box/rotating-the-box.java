class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int m = boxGrid.length;       
        int n = boxGrid[0].length;    
        char[][] result = new char[n][m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        
        int[] emptyIndex = new int[m];           
        Arrays.fill(emptyIndex, n - 1);          
        for (int i = n - 1; i >= 0; i--) {       
            for (int j = 0; j < m; j++) {       

                if (result[i][j] == '#') {
                    
                    if (emptyIndex[j] != i) {
                        result[emptyIndex[j]][j] = '#'; 
                        result[i][j] = '.';             
                    }
                    
                    emptyIndex[j]--;

                } else if (result[i][j] == '*') {
                   
                    emptyIndex[j] = i - 1;
                }

            }
        }

        return result;
    }
}