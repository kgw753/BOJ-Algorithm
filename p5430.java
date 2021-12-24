import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class p5430 {
    public static boolean error, rev;
    public static int T, n;
    public static String p, x;
    public static Deque<Integer> dq;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            error = false;
            rev = false;

            p = br.readLine();
            n = Integer.parseInt(br.readLine());
            x = br.readLine();

            dq = parsing(x);

            for(Character op : p.toCharArray()){
                if(op == 'R'){
                    rev = !rev;
                }
                else if(dq.isEmpty()){
                    error = true;
                    break;
                }
                else if(op == 'D'){
                    if(rev) dq.pollLast();
                    else dq.pollFirst();
                }
            }

            if(error) {
                bw.append("error\n");
            } else {
                if(rev) dq = reverse(dq);
                bw.append(print(dq));
            }
                
        }

        bw.flush();
    }

    public static Deque<Integer> parsing(String arr){
        Deque<Integer> ret = new LinkedList<>();
        
        StringTokenizer st = new StringTokenizer(arr.replace("[", "").replace("]", ""));

        while(st.hasMoreTokens()){
            ret.addLast(Integer.parseInt(st.nextToken(",")));
        }

        return ret;
    }

    public static Deque<Integer> reverse(Deque<Integer> input){
        Deque<Integer> ret = new LinkedList<>();

        while(!input.isEmpty()){
            ret.addFirst(input.pollFirst());
        }

        return ret;
    }

    public static String print(Deque<Integer> arr){
        StringBuffer sb = new StringBuffer();

        sb.append("[");

        while(!arr.isEmpty()){
            sb.append(arr.pollFirst());
            if(arr.size() == 0) break;
            sb.append(',');
        }

        sb.append("]\n");
        return sb.toString();
    }
}
