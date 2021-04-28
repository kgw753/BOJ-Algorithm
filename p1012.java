import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p1012 {

    public static int count;
    public static int[] dy = { -1, 0, 1, 0 };
    public static int[] dx = { 0, 1, 0, -1 };
    public static int[][] field = new int[51][51];
    public static boolean[][] visited = new boolean[51][51];

    public static int M, N, K;

    public static void dfs(int y, int x) {
        visited[y][x] = true;
        for (int i = 0; i < dy.length; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                continue;
            else if (!visited[ny][nx] && field[ny][nx] == 1) {
                dfs(ny, nx);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        int[] answer = new int[tc];

        for (int i = 0; i < tc; i++) {
            count = 0;
            for (int j = 0; j < field.length; j++) {
                Arrays.fill(field[j], 0);
            }
            for (int j = 0; j < visited.length; j++) {
                Arrays.fill(visited[j], false);
            }

            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            for (int j = 0; j < K; j++) {
                st = new StringTokenizer(br.readLine());
                int m = Integer.parseInt(st.nextToken());
                int n = Integer.parseInt(st.nextToken());
                field[m][n] = 1;
            }

            for (int p = 0; p < M; p++) {
                for (int q = 0; q < N; q++) {
                    if (field[p][q] == 1 && !visited[p][q]) {
                        dfs(p, q);
                        count++;
                    }
                }
            }

            answer[i] = count;
        }

        for(int ans: answer) System.out.println(ans);
    }
}
