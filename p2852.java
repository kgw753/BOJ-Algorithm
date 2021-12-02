import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p2852 {
    public static int N;
    public static int scoreA;
    public static int scoreB;
    public static int timeA;
    public static int timeB;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int team, time;
        int prev = 0, now = 0;
        while(N-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            team = Integer.parseInt(st.nextToken());
            now = toInt(st.nextToken());
            if(scoreA > scoreB){
                timeA += now - prev;
            }
            else if(scoreA < scoreB){
                timeB += now - prev;
            }
            if(team == 1) scoreA++;
            else scoreB++;
            prev = now;
        }
        if(scoreA > scoreB){
            timeA += (48 * 60) - prev;
        }
        else if(scoreA < scoreB){
            timeB += (48 * 60) - prev;
        }
        printTime(timeA);
        printTime(timeB);
    }

    public static int toInt(String time){
        int ret = 0;
        ret += Integer.parseInt(time.split(":")[0]) * 60;
        ret += Integer.parseInt(time.split(":")[1]);
        return ret;
    }
    public static void printTime(int time){
        System.out.format("%02d:%02d\n", time / 60, time % 60);
    }
}
