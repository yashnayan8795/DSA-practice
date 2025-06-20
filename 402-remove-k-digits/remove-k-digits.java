class Solution {
    public String removeKdigits(String num, int k) {
        int len = num.length();
        if (k == len) return "0";

        Deque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < len; i++) {
            char c = num.charAt(i);
            while (!stack.isEmpty() && k > 0 && stack.peekLast() > c) {
                stack.pollLast();
                k--;
            }
            stack.addLast(c);
        }

        while (k-- > 0) {
            stack.pollLast();
        }
        StringBuilder sb = new StringBuilder();
        for (char digit : stack) {
            sb.append(digit);
        }

        while (sb.length() > 0 && sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }

        return sb.length() == 0 ? "0" : sb.toString();
    }
}