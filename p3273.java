import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class p3273 {
    public static BufferedReader br;
    public static int N, X;
    public static List<Integer> list;
    public static void main(String[] args) throws IOException{
        init();

        int l = 0, r = N - 1;
        int lnum, rnum;
        int ret = 0;
        Collections.sort(list);

        while(l < r){
            lnum = list.get(l);
            rnum = list.get(r);

            if(lnum + rnum == X) {
                ret++;
                r--;
            }
            else if(lnum + rnum < X){
                l++;
            }
            else {
                r--;
            }
        }

        System.out.println(ret);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        list = new ArrayList<>();

        String[] input = br.readLine().split(" ");
        for(int i = 0; i < N; i++){
            list.add(Integer.parseInt(input[i]));
        }

        X = Integer.parseInt(br.readLine());
    }
}
