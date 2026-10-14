import java.util.Random;

class ComputeIslands {
    private int rsize;
    private int csize;

    ComputeIslands(int x, int y){
        this.rsize = x;
        this.csize = y;
    }

    boolean safe(int adj[][], int row, int col, boolean visited[][]){
        return (row < rsize) && (col < csize) && (row >= 0) && (col >= 0) && (adj[row][col] == 1) && !visited[row][col];
    }

    void DFS(int adj[][], int row, int col, boolean visited[][]){
        int[] rnext = new int[]{-1, -1, -1, 0, 0, 1, 1, 1};
        int[] cnext = new int[]{-1, 0, 1, -1, 1, -1, 0, 1};
        visited[row][col] = true;
        for(int i = 0; i < 8; ++i){
            if(safe(adj, row+rnext[i], col+cnext[i], visited))
                DFS(adj, row+rnext[i], col+cnext[i], visited);
        }
    }

    int CountIslands(int adj[][], int row, int col){
        int cnt = 0; //counts the number of islands
        boolean visited[][] = new boolean[rsize][csize];
        for(int i = 0; i < rsize; ++i){
            for(int j = 0; j < csize; ++j){
                if(!visited[i][j] && adj[i][j] == 1){
                    System.out.println("Island detected at ("+i+","+j+")");
                    DFS(adj, i, j, visited);
                    ++cnt;
                }
            }
        }
        return cnt;
    }

}

public class NumberOfIslands {

    public static void main(String[] args) {

        int[][] adj = new int[][]{
                { 1, 1, 0, 0, 0 },
                { 0, 1, 0, 0, 1 },
                { 1, 0, 0, 1, 1 },
                { 0, 0, 0, 0, 0 },
                { 1, 0, 1, 1, 1 }
        };

        ComputeIslands obj = new ComputeIslands(5, 5);
        System.out.print("Number of islands = "+obj.CountIslands(adj, 0, 0));
        /*
        Island detected at (0,0)
        Island detected at (1,4)
        Island detected at (4,0)
        Island detected at (4,2)
        Number of islands = 4
         */
    }
}
