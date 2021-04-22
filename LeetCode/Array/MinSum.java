import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * MinSum
 * https://leetcode.com/discuss/interview-question/339640/sap-online-assessment-minimum-sum
 */
public class MinSum {

    public static int minSum(List<Integer> num, int k){
        Queue<Integer> pq = new PriorityQueue<>(num.size(), Comparator.reverseOrder());
        pq.addAll(num);
        while(k > 0){
            int n = (int)Math.ceil(pq.poll() / 2.0);
            pq.add(n);
        }
        return pq.stream().mapToInt(i->i).sum();
    }

    public static void main(String[] args) {
        List<Integer> integers = Arrays.asList(1, 2, 3, 4, 5);
        Integer sum = integers.stream().mapToInt(i -> i).sum();
        double d = sum/integers.size();
        System.out.println(d);
        System.out.println(sum);
    }
}