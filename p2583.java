import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class p2583 {
    public static final int[] dx = {1, 0, -1, 0};
    public static final int[] dy = {0, 1, 0, -1};
    public static int N;
    public static int M;
    public static int K;
    public static int[][] map;
    public static boolean[][] visited;
    public static ArrayList<Integer> arr;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        visited = new boolean[N][M];
        arr = new ArrayList<>();

        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());
            makeSquare(st);
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0 && !visited[i][j]){
                    arr.add(bfs(i, j));
                }
            }
        }

        Collections.sort(arr);
        System.out.println(arr.size());
        for(Integer i : arr){
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void makeSquare(StringTokenizer st){
        int x1 = Integer.parseInt(st.nextToken());
        int y1 = Integer.parseInt(st.nextToken());
        int x2 = Integer.parseInt(st.nextToken());
        int y2 = Integer.parseInt(st.nextToken());

        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                map[i][j] = 1;
            }
        }
    }
    
    public static Integer bfs(int y, int x){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{y, x});
        visited[y][x] = true;
        Integer ret = 1;

        while(!q.isEmpty()){
            y = q.peek()[0];
            x = q.peek()[1];
            q.poll();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(!visited[ny][nx] && map[ny][nx] == 0){
                    visited[ny][nx] = true;
                    q.add(new int[]{ny, nx});
                    ret++;
                }
            }
        }
        return ret;
    }
}