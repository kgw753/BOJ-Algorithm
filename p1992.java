import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1992 {
    public static int N;
    public static int[][] map;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for(int i = 0; i < N; i++){
            String input = br.readLine();
            for(int j = 0; j < N; j++){
                map[i][j] = input.charAt(j) - '0';
            }
        }
        
        System.out.println(qt(0, 0, N));
    }

    public static String qt(int y, int x, int size){
        int cmp = map[y][x];
        boolean flag = true;
        for(int i = y; i < y + size; i++){
            for(int j = x; j < x + size; j++){
                if(cmp != map[i][j]) flag = false;
            }
        }

        if(flag){
            return Integer.toString(cmp);
        }
        else{
            size /= 2;
            String ret = "(";
            ret += qt(y, x, size);
            ret += qt(y, x + size, size);
            ret += qt(y + size, x, size);
            ret += qt(y + size, x + size, size);
            ret += ")";
            return ret;
        }
    }
}
