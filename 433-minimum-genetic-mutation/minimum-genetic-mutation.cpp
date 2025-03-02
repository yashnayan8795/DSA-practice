class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //queue<pair<string,int>> q;
        unordered_set<string> bankset(bank.begin(), bank.end());
        queue<string> que;
        unordered_set<string> visited;
        vector<char> valid = {'A', 'C', 'T', 'G'};

        que.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                string curr=que.front();
                que.pop();

                if(curr==endGene){
                    return level;
                }
                for(char ch: valid ){
                    for(int i=0;i<curr.length();i++){
                        string neighbour=curr;
                        neighbour[i]=ch;
                        if(visited.find(neighbour)==visited.end() && bankset.find(neighbour)!=bankset.end()){
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};