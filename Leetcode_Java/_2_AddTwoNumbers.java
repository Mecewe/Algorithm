package com.mecewe.Leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * 2. Add Two Numbers
 *
         You are given two non-empty linked lists representing two non-negative integers.
         The digits are stored in reverse order and each of their nodes contain a single digit.
         Add the two numbers and return it as a linked list.
         You may assume the two numbers do not contain any leading zero, except the number 0 itself.

         Example:
         Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
         Output: 7 -> 0 -> 8
         Explanation: 342 + 465 = 807.

         Definition for singly-linked list.
         public class ListNode {
         int val;
         ListNode next;
         ListNode(int x) { val = x; }
         }
 */

public class _2_AddTwoNumbers {
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sum = new ListNode(0);
        ListNode temp3 = null;
        List<Integer> list = new ArrayList<>();
        int temp = 0;
        while (l1 != null && l2 != null) {
            list.add(l1.val + l2.val);
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            list.add(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            list.add(l2.val);
            l2 = l2.next;
        }
        for (int i = 0; i < list.size(); i++) {
            if (i == 0) {
                temp3 = sum;
            }
            if ((list.get(i) + temp) < 10) {
                temp3.next = new ListNode(list.get(i) + temp);

            } else {
                temp3.next = new ListNode((list.get(i) + temp) % 10);
                temp = (list.get(i) + temp) / 10;
            }
            temp3 = temp3.next;
        }
        if (temp > 0) {
            temp3.next = new ListNode(temp);
        }
        return sum.next;
    }
}
