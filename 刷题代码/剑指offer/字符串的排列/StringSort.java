package cn.pzhu.cg.offer;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * @Author:CG-PC
 * @Date:2018/10/1
 * @Time:22:31
 */
public class StringSort {
    public ArrayList<String> list = new ArrayList<String>();
    public int maxn = 10;
    public int[] visit = new int[maxn];
    public StringBuffer res = new StringBuffer();
    public int len = 0;

    public ArrayList<String> Permutation(String str) {
        len = str.length();
        if (len == 0) return list;

        char [] arr = new char[maxn];
        arr = str.toCharArray();
        Arrays.sort(arr);

        dfs(arr,0);
        return list;
    }
    //去重的 DFS 全排列
    public void dfs(char[] arr, int k) {
        if (k == len) {
            list.add(res.toString());
            //res.setLength(0);
            return;
        }
        for (int i = 0;i < len;i++) {
            boolean flag = true;
            if (visit[i] == 0) {
                for (int j = i + 1;j < len;j++) {
                    if (arr[i] == arr[j] && visit[j] == 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    visit[i] = 1;
                    res.append(arr[i]);
                    dfs(arr,k+1);
                    //回溯
                    visit[i] = 0;
                    res.deleteCharAt(k);
                }
            }
        }
    }

    public static void main (String[] args) {
        StringSort temp = new StringSort();
        ArrayList<String> list = temp.Permutation("aac");
        for (String s : list) {
            System.out.println(s);
        }
    }
}