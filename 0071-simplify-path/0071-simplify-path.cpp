#include<stack>
class Solution {
public:
    // class stack{
    //     int size;
    //     int top;
    //     char *arr;
    // public:
    //     stack(int s){
    //         size = s;
    //         top = -1;
    //         arr = new arr[char];
    //     }
    // };
    string simplifyPath(string path) {
        stack<string> st;
        string dir;
                for (int i = 0; i <= path.length(); i++) {
            if (i == path.length() || path[i] == '/') {
                if (dir == "" || dir == ".") {
                    // do nothing
                }
                else if (dir == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else {
                    st.push(dir);
                }
                dir.clear();
            } else {
                dir += path[i];
            }
        }

        // build result
        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;

    //     stack(path.length());
    //     for(int i = 0;i< path.length();i++){
    //         if(s==NULL){
    //             s.push(path[i]);
    //         }
    //         if(s.top!='/'){
    //             continue;
    //         }if(path[i]=='.'){
    //             continue;
    //         }
    //     }
    //     string ans;
    //     while(s.top()!=NULL){
    //         ans.push_back(s.top());
    //         s.pop();
    //     }
    //     return ans;
    // }
    // 
    }
    
};