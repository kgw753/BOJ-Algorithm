import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class p2910 {
    public static int N;
    public static int M;
    public static Map<Integer, Integer> map;
    public static Map<Integer, Integer> seq;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        map = new HashMap<>();
        seq = new HashMap<>();
        int cnt = 1;
        for(int i = 0; i < N; i++){
            int input = sc.nextInt();
            if(map.containsKey(input)) map.put(input, map.get(input) + 1);
            else {
                map.put(input, 1);
                seq.put(input, cnt++);
            }
        }

        ArrayList<Integer> arr = new ArrayList<>(map.keySet());
        
        Collections.sort(arr, new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b){
                if(map.get(a) == map.get(b)) return seq.get(a) - seq.get(b);
                else return map.get(b) - map.get(a);
            }
        });

        for(Integer num : arr) {
            for(int i = 0; i < map.get(num); i++){
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }
}
