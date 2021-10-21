import java.util.*;

//유의사항: 벽은 뚫고 지나갈 수 없지만 이미 청소된 구역으로는 이동할 수 있음!

public class Main {
	static int N, M, r, c, cnt;
	static int board[][];
	static int dy[] = {-1, 0, 1, 0};
	static int dx[] = {0, 1, 0, -1};
	
	static int Direction(int d) {
		if(--d < 0)
			d = 3;
		return d;
	}
	
	static boolean InBoundary(int y, int x) {
		if(y >= 0 && x >= 0 && y < N && x < M)
			return true;
		return false;
	}
	
	static void Simulation(int d) {
		while(true) {
			boolean flag = false;
			if(board[r][c] == 0) {
				cnt++;
				board[r][c] = 2;  //"board[r][c] = 1"로 해서 틀렸었음
			}
			for(int i = 0; i < 4; i++) {
				d = Direction(d);
				int ny = r + dy[d];
				int nx = c + dx[d];
				if(board[ny][nx] == 0) {
					r = ny; c = nx;
					flag = true;
					break;
				}
			}
			if(flag)
				continue;
			r += dy[(d + 2) % 4];
			c += dx[(d + 2) % 4];
			if(board[r][c] == 1)
				break;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int d;
		N = sc.nextInt();
		M = sc.nextInt();
		board = new int[N + 1][M + 1];
		r = sc.nextInt();
		c = sc.nextInt();
		d = sc.nextInt();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				board[i][j] = sc.nextInt();
			}
		}
		Simulation(d);
		System.out.println(cnt);
	}

}
