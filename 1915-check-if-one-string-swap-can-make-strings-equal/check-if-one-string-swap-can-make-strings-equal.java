class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.equals(s2)) return true;
        List<Integer> swapIndex = new ArrayList<>();
        for (int i= 0; i<s1.length();i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                swapIndex.add(i);
            }
        }
        if (swapIndex.size() == 2) {
            int i =swapIndex.get(0), j =swapIndex.get(1);
            return (s1.charAt(i) == s2.charAt(j) && s1.charAt(j) == s2.charAt(i));
        }return false;
    }
}