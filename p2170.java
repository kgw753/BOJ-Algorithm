import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

class Line{
    public int start;
    public int end;
    public Line(int start, int end){
        this.start = start;
        this.end = end;
    }
}

public class p2170 {
    public static int N;
    public static List<Line> lines;
    public static BufferedReader br;
    public static void main(String[] args) throws IOException{
        init();

        int mn = lines.get(0).start;
        int mx = lines.get(0).end;
        int res = 0;

        for(Line line : lines){
            if(mx < line.start){
                res += mx - mn;
                mn = line.start;
                mx = line.end;
            }
            else if(mx < line.end){
                mx = line.end;
            }
        }

        System.out.println(res + (mx - mn));
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        lines = new ArrayList<>();
        
        int s, e;
        StringTokenizer st;
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());

            lines.add(new Line(s, e));
        }

        Collections.sort(lines, new Comparator<Line>(){
            @Override
            public int compare(Line l1, Line l2){
                if(l1.start == l2.start) return l1.end - l2.end;
                else return l1.start - l2.start;
            }
        });
    }
}
