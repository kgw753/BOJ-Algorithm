import java.util.ArrayList;
import java.util.Scanner;

public class p1009 {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int [][] input = new int[T][2];
        int [] res = new int[T];

        for(int i = 0; i < T; i++){
            input[i][0] = sc.nextInt();
            input[i][1] = sc.nextInt();
        }
        
        for(int i = 0; i < T; i++){
            int a = input[i][0] % 10;
            if(a == 0){
                res[i] = 10;
                continue;
            }
            int b = input[i][1];
            int tmp = a;
            ArrayList<Integer> arr = new ArrayList<>();
            do{
                arr.add(tmp);
                tmp = (tmp * a) % 10;
            }while(tmp != a);
            int idx = b % arr.size() - 1;
            if(idx < 0){
                idx += arr.size();
            }
            res[i] = arr.get(idx);
        }

        for(int r: res){
            System.out.println(r);
        }
    }
    
}
