import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class p11000 {
    
    public static void main(String[] args){
        Scanner sc = new Scanner (System.in);
        int N = sc.nextInt();
        ArrayList<Lecture> input = new ArrayList<>();
        for(int i = 0; i < N; i++){
            input.add(new Lecture(sc.nextInt(), sc.nextInt()));
        }

        Collections.sort(input, new Comparator<Lecture>(){
            @Override
            public int compare(Lecture l1, Lecture l2){
                if(l1.start == l2.start){
                    return l1.end - l2.end;
                }
                else{
                    return l1.start - l2.start;
                }
            }
        });

        PriorityQueue<Integer> answer = new PriorityQueue<>();

        for(Lecture lec : input){
            if(answer.isEmpty()){
                answer.add(lec.end);
            }
            else if(lec.start >= answer.peek()){
                answer.poll();
                answer.add(lec.end);
            }
            else{
                answer.add(lec.end);
            }
        }
        System.out.println(answer.size());
    }
}

class Lecture {
    int start;
    int end;
    

    public Lecture(int start, int end){
        this.start = start;
        this.end = end;
    }
}