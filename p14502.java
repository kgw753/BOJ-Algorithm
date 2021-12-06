import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class p14502 {
    public static int N;
    public static int M;
    public static int mx;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[][] map;
    public static int[][] tmp;
    public static ArrayList<int[]> virus;
    public static ArrayList<int[]> space;
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] size = br.readLine().split(" ");
        N = Integer.parseInt(size[0]);
        M = Integer.parseInt(size[1]);
        map = new int[N][M];
        virus = new ArrayList<>();
        space = new ArrayList<>();

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 0) space.add(new int[]{i, j});
                else if(map[i][j] == 2) virus.add(new int[]{i, j});
            }
        }
        
        combi(-1, new ArrayList<int[]>(), 3);

        System.out.println(mx);
    }

    public static void combi(int idx, ArrayList<int[]> arr, int size){
        if(arr.size() == size){
            buildBarr(arr);
            goVirus();
            mx = Math.max(mx, count());
            return;
        }

        for(int i = idx + 1; i < space.size(); i++){
            arr.add(space.get(i));
            combi(i, arr, size);
            arr.remove(arr.size() - 1);
        }
    }
    
    public static void buildBarr(ArrayList<int[]> arr){
        tmp = new int[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                tmp[i][j] = map[i][j];
            }
        }
        
        for(int[] pos : arr){
            int y = pos[0];
            int x = pos[1];
            tmp[y][x] = 1;
        }
    }

    public static void goVirus(){
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[N][M];
        for(int[] vPos : virus){
            q.add(vPos);
            visited[vPos[0]][vPos[1]] = true;
        }

        while(!q.isEmpty()){
            int[] pos = q.poll();
            int y = pos[0];
            int x = pos[1];

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
                if(tmp[ny][nx] == 0){
                    q.add(new int[]{ny, nx});
                    visited[ny][nx] = true;
                    tmp[ny][nx] = 2;
                }
            }
        }
    }

    public static int count(){
        int ret = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(tmp[i][j] == 0) ret++;
            }
        }
        return ret;
    }
}
