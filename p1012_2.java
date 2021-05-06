import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p1012_2 {

    public static int[][] field;
    public static int[] dx = {0, 1, 0, -1};
    public static int[] dy = {1, 0, -1, 0};
    public static int m;
    public static int n;
    public static void DFS(int x, int y){
        
        if(field[x][y] != 1) return;

        field[x][y]++;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                DFS(nx, ny);
            }
        }
    }

    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        int[] answer = new int[tc];

        for(int i = 0; i < tc; i++){
            String input = br.readLine();
            m = Integer.parseInt(input.split(" ")[0]);
            n = Integer.parseInt(input.split(" ")[1]);
            int k = Integer.parseInt(input.split(" ")[2]);

            field = new int[m][n];

            for(int j = 0; j < k; j++){
                input = br.readLine();
                int x = Integer.parseInt(input.split(" ")[0]);
                int y = Integer.parseInt(input.split(" ")[1]);

                field[x][y]++;
            }

            int cnt = 0;
            for(int p = 0; p < m; p++){
                for(int q = 0; q < n; q++){
                    if(field[p][q] == 1){
                        DFS(p, q);
                        cnt++;
                    }
                }
            }
            answer[i] = cnt;
        }

        for(int ans: answer){
            System.out.println(ans);
        }
    }
    
}
