import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.stream.Stream;

public class p4963{
    public static int h, w;
    public static int[][] map;
    public static int[][] cnt;
    public static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    public static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    public static void dfs(int y, int x, int count){
        cnt[y][x] = count;

        for(int i = 0; i < dx.length; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h){
                if(map[ny][nx] == 1 && cnt[ny][nx] == 0){
                    dfs(ny, nx, count);
                }
            }
        }
    }
    public static void main(String[] args)throws Exception{
        ArrayList<Integer> ans = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        while(true){
            input = br.readLine();
            w = Integer.parseInt(input.split(" ")[0]);
            h = Integer.parseInt(input.split(" ")[1]);
            if(w == 0 && h == 0){
                break;
            }

            map = new int[h][w];
            cnt = new int[h][w];
            int count = 0;

            for(int i = 0; i < h; i++){
                input = br.readLine();
                map[i] = Stream.of(input.split(" ")).mapToInt(Integer::parseInt).toArray();
            }

            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(cnt[i][j] == 0 && map[i][j] == 1){
                        dfs(i, j, ++count);
                    }
                }
            }
            ans.add(count);
        }

        for(int a: ans){
            System.out.println(a);
        }
    }
}