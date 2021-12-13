import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class p4179 {
    public static int N;
    public static int M;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int flag;
    public static char[][] map;
    public static int[][] visited;
    public static Queue<int[]>jhPos = new LinkedList<>();
    public static Queue<int[]>firePos = new LinkedList<>();
    public static Queue<int[]>tmpPos;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new char[N][M];
        visited = new int[N][M];

        for(int i = 0; i < N; i++){
            map[i] = br.readLine().toCharArray();
            
            for(int j = 0; j < M; j++){
                if(map[i][j] == 'J') {
                    jhPos.add(new int[]{i, j});
                    visited[i][j] = 1;
                }
                else if(map[i][j] == 'F') firePos.add(new int[]{i, j});
            }
        }

        flag = 0;
        int res = 0;
        while(true){
            goJH();
            goFire();
            res++;
            if(flag != 0) break;
        }

        if(flag == 1) System.out.println(res);
        else System.out.println("IMPOSSIBLE");
    }

    public static void goJH(){
        tmpPos = new LinkedList<>();
        
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
                if(visited[ny][nx] == 0 && map[ny][nx] == '.'){
                    visited[ny][nx] = visited[y][x] + 1;
                    tmpPos.add(new int[]{ny, nx});
                }
            }
        }

        jhPos = tmpPos;
        if(jhPos.isEmpty()) flag = 2;
    }
    
    public static void goFire(){
        tmpPos = new LinkedList<>();
        while(!firePos.isEmpty()){
            int y = firePos.peek()[0];
            int x = firePos.peek()[1];
            firePos.poll();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(map[ny][nx] == '.') {
                    map[ny][nx] = 'F';
                    tmpPos.add(new int[]{ny, nx});
                }
            }
        }
        firePos = tmpPos;
    }

    public static void print(){
        for(int i = 0; i < N; i++){            
            for(int j = 0; j < M; j++){
                System.out.print(visited[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
