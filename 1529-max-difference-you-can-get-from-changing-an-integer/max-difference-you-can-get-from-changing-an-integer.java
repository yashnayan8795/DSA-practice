class Solution {
    public int maxDiff(int num) {
        String a = Integer.toString(num);
        String b = Integer.toString(num);
        char x = '9';
        int n = a.length();
        for (int i = 0; i< n; i++) {
            if (a.charAt(i) < x) {
                x = a.charAt(i);
                break;
            }
        }
        int num1 = Integer.parseInt(a.replace(x, '9'));
        if (b.charAt(0) != '1') {
            int num2 = Integer.parseInt(b.replace(b.charAt(0), '1'));
            return num1-num2;
        }
        x = '0';
        for (int i = 1; i< n; i++) {
            if (b.charAt(i) > x && b.charAt(i)!=b.charAt(0)){
                x = b.charAt(i);
                break;
            }
        }
        int num2 = Integer.parseInt(b.replace(x, '0'));
        return num1-num2;
    }
}