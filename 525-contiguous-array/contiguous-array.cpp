class Solution {
public:
    int findMaxLength(vector<int>& a) {
        unordered_map<int,int>f;
        int zeroes = 0;
        int ones = 0;
        int res =0;
        for (int i =0;i<a.size();i++){
            if (a[i]==0){
                zeroes++;   
            }
            else{
                ones++;
            }
        int diff = zeroes-ones;
        if(diff == 0){
            res = max(res,i+1);   
            continue;
        }
        if (f.find(diff)==f.end()){  //diff is not present in the hashmap
            f[diff]=i;               // store in  diff = index format in hashmap
        }
        else {
            int idx = f[diff];      //checking the index of the difference in hasmap we got in this iteration
            int len = i-idx; 
            res = max (res,len);
        }
        }
      return res;    
    }
};