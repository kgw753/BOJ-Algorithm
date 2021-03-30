import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class p1913 {
    public static void main(String[] args)throws Exception{
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = sc.nextInt();
        int target = sc.nextInt();
        int [][] snail = new int[N][N];
        int val = N * N;
        int len = N;
        int x = 0;
        int y = -1;
        int move = 1;

        while(true){
            for(int i = 0; i < len; i++){
                y += move;
                snail[y][x] = val--;
            }
            len--;
            if(len <= 0){
                break;
            }
            for(int i = 0; i < len; i++){
                x += move;
                snail[y][x] = val--;
            }
            move *= -1;
        }
        int[] res = new int[2];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(target == snail[i][j]){
                    res[0] = i + 1;
                    res[1] = j + 1;
                }
                
                bw.write(snail[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.write(res[0] + " " + res[1] + "\n");
        bw.flush();
        bw.close();
    }
}
