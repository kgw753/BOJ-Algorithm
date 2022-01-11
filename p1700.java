import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class p1700 {
    public static BufferedReader br;
    public static int N, M;
    public static int[] arr;
    public static boolean[] visited;
    public static List<Integer> socket;
    public static void main(String[] args) throws IOException{
        init();
        int res = 0;

        for(int i = 0; i < M; i++){
            if(visited[arr[i]]) continue;

            if(socket.size() == N){
                int idx = 0, item = 0;
                for(int s : socket){
                    int itemIdx = Integer.MAX_VALUE;
                    for(int j = i + 1; j < M; j++){
                        if(arr[j] == s){
                            itemIdx = j;
                            break;
                        }
                    }

                    if(itemIdx > idx){
                        idx = itemIdx;
                        item = s;
                    }
                }

                socket.remove(socket.indexOf(item));
                visited[item] = false;
                res++;
            }

            socket.add(arr[i]);
            visited[arr[i]] = true;
        }

        System.out.println(res);
    }
    
    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        arr = new int[M];
        visited = new boolean[M + 1];
        socket = new ArrayList<>();

        input = br.readLine().split(" ");
        for(int i = 0; i < M; i++){
            arr[i] = Integer.parseInt(input[i]);
        }
    }
}
