class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        int n = path.size();

        for(int i = 0; i < n; i++) {

            if(path[i] == '/') continue;   // slash skip karo

            string folder = "";           // current folder name

            while(i < n && path[i] != '/') {
                folder += path[i];
                i++;
            }

            if(folder == ".") {
                continue;                 // same folder, ignore
            }
            else if(folder == "..") {
                if(!st.empty()) {
                    st.pop();             // ek folder back jao
                }
            }
            else {
                st.push(folder);          // valid folder store karo
            }
        }

        vector<string> res;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        string ans = "";

        for(string s : res) {
            ans += "/" + s;
        }

        if(ans == "") return "/";

        return ans;
    }
};