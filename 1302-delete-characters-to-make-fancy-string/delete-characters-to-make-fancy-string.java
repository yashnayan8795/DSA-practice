class Solution {
    public String makeFancyString(String s) {
        StringBuilder ans=new StringBuilder();
        int x=0;
        char p=' ';
        for(char i:s.toCharArray()){
            if(p==i) x++;
            else x=1;
            if(x==3){
                x--;
                continue;
            }
            p=i;
            ans.append(i);
        }
        return ans.toString();
    }
}