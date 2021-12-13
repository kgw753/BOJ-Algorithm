import java.util.Scanner;

public class p2852 {
    public static int N;
    public static int score = 0;
    public static int prev = 0;
    public static int now = 0;
    public static int[] time = new int[2];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(sc.nextLine());
        
        for(int i = 0; i < N; i++){
            String[] input = sc.nextLine().split(" ");
            now = toInt(input[1]);

            if(score > 0) time[0] += (now - prev);
            else if(score < 0) time[1] += (now - prev);
            
            if(Integer.parseInt(input[0]) ==  1) score++;
            else score--;
            
            prev = now;
        }
        
        prev = now;
        now = toInt("48:00");
        
        if(score > 0) time[0] += (now - prev);
        else if(score < 0) time[1] += (now - prev);
        
        intPrint(time[0]);
        intPrint(time[1]);
    }

    public static int toInt(String scr){
        String[] time = scr.split(":");
        int ret = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
        return ret;
    }

    public static void intPrint(int scr){
        System.out.format("%02d:%02d\n", scr / 60, scr % 60);
    }
}
