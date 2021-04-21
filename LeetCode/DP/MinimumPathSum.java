package LeetCode.DP;

/**
 * MinimumPathSum
 */
public class MinimumPathSum {

    public int minPathSum(int[][] grid) {
        int result = 0;
        int m = grid.length;
        int n = grid[0].length;

        int[][] d = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j==0 || i==0){
                    if(i==0 && j==0){
                        d[i][j] = grid[i][j];
                    }
                    else if ( i > 0 && j==0)
                        d[i][j] = d[i-1][j] + grid[i][j];
                    else if (i==0 && j>0)
                        d[i][j] = d[i][j-1] + grid[i][j];
                }
                else{
                    d[i][j] = Math.min(d[i-1][j], d[i][j-1]) + grid[i][j];
                }
            }
        }
        result += d[m][n];
        return result;
    }
}