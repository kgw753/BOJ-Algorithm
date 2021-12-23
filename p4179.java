import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class p4179 {
    public static int N, M, flag;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static boolean[][] visited;
    public static char[][] map;
    public static Queue<int[]> firePos = new LinkedList<>();;
    public static Queue<int[]> jhPos = new LinkedList<>();;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new char[N][M];
        visited = new boolean[N][M];

        for(int i = 0; i < N; i++){
            map[i] = br.readLine().toCharArray();
            
            for(int j = 0; j < M; j++){
                if(map[i][j] == 'J') {
                    jhPos.add(new int[]{i, j});
                    visited[i][j] = true;
                }
                else if(map[i][j] == 'F') {
                    firePos.add(new int[]{i, j});
                }
            }
        }

        int res = 0;
        while(flag == 0){
            goJH();
            goFire();
            res++;
        }

        if(flag == 1) System.out.println(res);
        else if(flag == 2) System.out.println("IMPOSSIBLE");
    }

    public static void goJH(){
        Queue<int[]> tmp = new LinkedList<>();

        while(!jhPos.isEmpty()){
            int y = jhPos.peek()[0];
            int x = jhPos.peek()[1];
            jhPos.poll();

            if(map[y][x] == 'F') continue;

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M){
                    flag = 1;
                    return;
                }
                if(visited[ny][nx] || map[ny][nx] != '.') continue;
                visited[ny][nx] = true;
                tmp.add(new int[]{ny , nx});
            }
        }

        jhPos = tmp;
        if(jhPos.isEmpty()) flag = 2;
    }

    public static void goFire(){
        Queue<int[]> tmp = new LinkedList<>();

        while(!firePos.isEmpty()){
            int y = firePos.peek()[0];
            int x = firePos.peek()[1];
            firePos.poll();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(map[ny][nx] == '.'){
                    map[ny][nx] = 'F';
                    tmp.add(new int[]{ny, nx});
                }
            }
        }

        firePos = tmp;
    }
}