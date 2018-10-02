package cn.pzhu.cg.offer;

import java.util.ArrayList;
import java.util.PriorityQueue;

/**
 * @Author:CG-PC
 * @Date:2018/10/2
 * @Time:19:03
 */
public class GetLeastNumbers {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        int len = input.length;
        if (len < k || k == 0) return res;
        //创建一个容量为 K 的优先队列(堆)
        PriorityQueue<Integer> maxHead = new PriorityQueue<Integer>(k, (o1,o2) -> {return o2.compareTo(o1);});
        for (int i = 0;i < len;i++) {
            if (i < k) {
                maxHead.add(input[i]);
            } else if (maxHead.peek() > input[i]) {
                maxHead.poll();//移除堆顶元素
                maxHead.add(input[i]);
            }
        }
        while (!maxHead.isEmpty()) {
            res.add(maxHead.remove());
        }
        return res;
    }

    public static void main (String[] args) {
        int[] input = {4,5,1,6,2,7,3,8};
        GetLeastNumbers test = new GetLeastNumbers();
        ArrayList<Integer> res = test.GetLeastNumbers_Solution(input,4);
        for (Integer i : res) {
            System.out.print(i + " ");
        }

    }
}
