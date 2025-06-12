class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result= new ArrayList();
        combinations(1,k,n,new LinkedList(),result);
        return result;
    }
    public void combinations(int st,int k,int n,LinkedList l ,List<List<Integer>> result ){
        if(k<0 || n<0) return;
        if(k==0 && n==0){
            result.add(new ArrayList(l));
            return;
        }
        for(int i=st;i<=9;i++){
            l.add(i);
            combinations(i+1,k-1,n-i,l,result);
            l.removeLast();
        }
    }
}