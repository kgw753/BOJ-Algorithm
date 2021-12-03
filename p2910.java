import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;

public class p2910 {
    public static int N;
    public static int C;
    public static HashMap<Integer, Integer> hm;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine().split(" ")[0]);
        hm = new LinkedHashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            int num = Integer.parseInt(st.nextToken());
            if(hm.containsKey(num)){
                hm.replace(num, hm.get(num) + 1);
            }
            else hm.put(num, 1);
        }

        ArrayList<Integer> arr = new ArrayList<>(hm.keySet());
        Collections.sort(arr, new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b){
                return hm.get(b) - hm.get(a);
            }
        });

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < hm.get(arr.get(i)); j++){
                System.out.print(arr.get(i) + " ");
            }
        }
        System.out.println();
    }
}
