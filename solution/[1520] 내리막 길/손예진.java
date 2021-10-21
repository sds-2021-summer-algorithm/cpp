import java.util.*;

public class Main {
	
	//memorization 안해줘서 시간초과,, 항상 메모라이제이션 할 수 있나 생각해보기!

	static int N, M;
	static int board[][];
	static int dp[][];	//현위치부터 목적지까지 갈 수 있는 방법의 수
	static int dy[] = {-1, 1, 0, 0};
	static int dx[] = {0, 0, -1, 1};
	
	static boolean InBoundary(int y, int x) {
		if(y >= 0 && x >= 0 && y < N && x < M)
			return true;
		return false;
	}
	
	static int Simulation(int y, int x) {
		if(y == N - 1 && x == M - 1) {	//목적지에서 목적지 가는 방법은 항상 1가지
			return 1;
		}
		if(dp[y][x] != 0)	//이미 방문한 위치면 dp값 return
			return dp[y][x];
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(InBoundary(ny, nx) && board[ny][nx] < board[y][x]) {
				int tmp = Simulation(ny, nx);
				if(tmp != -1)
					dp[y][x] += tmp;
			}
		}
		if(dp[y][x] == 0)	//상하좌우 다 돌았는데 목적지로 갈 수 있는 방법 없음
			return dp[y][x] = -1;
		return dp[y][x];
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		board = new int[N + 1][M + 1];
		dp = new int[N + 1][M + 1];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				board[i][j] = sc.nextInt();
			}
		}
		Simulation(0, 0);
		if(dp[0][0] == -1)  //시작점에서 목적지까지 절대 도달할 수 없는 경우 -1이 저장돼있음 -> 따라서 그럴 경우 0 출력하도록 설정
			System.out.println(0);
		else
			System.out.println(dp[0][0]);
	}

}
