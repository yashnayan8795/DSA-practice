class Solution {
public:
    int minimumRecolors(string& blocks, int k) {
        int n=blocks.size();
        int W=count(blocks.begin(), blocks.begin()+k, 'W');
        int rc=W;
        for(int l=0,r=k;r<n;r++,l++){
            W+=(blocks[r]=='W')-(blocks[l]=='W');
            rc=min(rc, W);
        }
        return rc;
    }
};