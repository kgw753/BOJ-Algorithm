import java.util.ArrayList;
import java.util.Scanner;

public class p1032 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        ArrayList<String> input = new ArrayList<>();
        StringBuilder res = new StringBuilder();

        for(int i = 0; i < N; i++){
            input.add(sc.nextLine());
        }

        for(int i = 0; i < input.get(0).length(); i++){
            char ch = input.get(0).charAt(i);
            boolean same = true;

            for(int j = 0; j < N; j++){
                String compare = input.get(j);
                if(ch != compare.charAt(i)){
                    same = false;
                }
            }
            if(same){
                res.append(ch);
            }
            else{
                res.append('?');
            }
        }
        System.out.println(res.toString());
    }
}
