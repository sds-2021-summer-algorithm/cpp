import java.util.*;

public class test_9663{
    static int N, cnt;
    static boolean visited[][];
    static boolean cols[];
    static boolean IsPos(int y, int x, int d){    //d => 왼쪽 위: -1, 오른쪽 위 : +1
        int ny = y - 1, nx = x + d;
        if(ny < 0 || nx < 0 || nx >= N)
            return true;
        if(!visited[ny][nx])    //해당 없음
            return IsPos(ny, nx, d);
        return false;    //visited == true
    }
    static void SetQueen(int row){
        if(row >= N){
            cnt++;
            return;
        }
        for(int i = 0; i < N; i++){
            if(IsPos(row, i, -1) && IsPos(row, i, 1) && !cols[i]){
                visited[row][i] = true;
                cols[i] = true;
                SetQueen(row + 1);
                visited[row][i] = false;
                cols[i] = false;
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        visited = new boolean[N][N];
        cols = new boolean[N];
        SetQueen(0);
        System.out.println(cnt);
    }
}
