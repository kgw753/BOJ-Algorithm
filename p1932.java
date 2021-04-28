import java.util.ArrayList;
import java.util.Scanner;

public class p1932 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> triangle = new ArrayList<>();
        ArrayList<ArrayList<Integer>> answer = new ArrayList<>();
        for(int i = 0; i < n; i++){
            triangle.add(new ArrayList<Integer>());
            answer.add(new ArrayList<Integer>());
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i + 1; j++){
                triangle.get(i).add(sc.nextInt());
            }
        }
        
        answer.get(0).add( triangle.get(0).get(0) );

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i + 1; j++){
                int now = triangle.get(i).get(j);
                if(j == 0) answer.get(i).add( now + answer.get(i - 1).get(j) );
                else if(j == i) answer.get(i).add( now + answer.get(i - 1).get(j - 1) );
                else{
                    int max = Math.max(answer.get(i - 1).get(j - 1), answer.get(i - 1).get(j));
                    answer.get(i).add(max + now);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < answer.get(n - 1).size(); i++){
            ans = Math.max(ans, answer.get(n - 1).get(i));
        }

        System.out.println(ans);
    }
}
