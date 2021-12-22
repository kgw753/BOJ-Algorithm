import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class p11723 {
    public static int N;
    public static int bm;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = Integer.parseInt(br.readLine());

        while(N-- > 0){
            String[] input = br.readLine().split(" ");

            if(input.length == 1){
                if(input[0].equals("all")){
                    bm = ~0;
                }
                else if(input[0].equals("empty")){
                    bm = 0;
                }
            }
            else if(input.length == 2){

                int idx = Integer.parseInt(input[1]) - 1;

                if(input[0].equals("add")){
                    bm = bm | 1 << idx;
                }
                else if(input[0].equals("remove")){
                    bm = bm & ~(1 << idx);
                }
                else if(input[0].equals("check")){
                    if(((1 << idx) & bm) == (1 << idx)) bw.write(1 + "\n");
                    else bw.write(0 + "\n");
                }
                else if(input[0].equals("toggle")){
                    if(((1 << idx) & bm) == 0) bm += (1 << idx);
                    else bm -= (1 << idx);
                }
            }
        }
        bw.flush();
    }
}
