import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p1068 {
    public static int N;
    public static int root;
    public static int del;
    public static ArrayList<Integer> tree[];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        tree = new ArrayList[N];
        for(int i = 0; i < N; i++) tree[i] = new ArrayList<Integer>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            int parent = Integer.parseInt(st.nextToken());
            if(parent == -1) root = i;
            else tree[parent].add(i);
        }
        del = Integer.parseInt(br.readLine());
        
        System.out.println((del == root) ? 0 : dfs(root));
    }

    public static int dfs(int idx){
        if(tree[idx].isEmpty() || tree[idx].size() == 1 && tree[idx].get(0) == del) return 1;
        int ret = 0;
        for(int i = 0; i < tree[idx].size(); i++){
            if(tree[idx].get(i) != del) ret += dfs(tree[idx].get(i));
        }
        return ret;
    }
}
