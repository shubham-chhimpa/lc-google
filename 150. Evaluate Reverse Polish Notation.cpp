//150. Evaluate Reverse Polish Notation

class Solution {
public:
    
    bool isNumber(string s){
        bool flag = false;
        if(s.size()>1 && s[0]=='-') flag=true;
        for(auto &c:s){
            if(c=='-' && flag) continue;
            if(!isdigit(c)) return false;
        }
        
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto &token : tokens){
            if(isNumber(token)){
                int num = stoi(token);
                st.push(num);
            }else{
                int res = INT_MAX;
                if(token == "+"){
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    res = a +b;
                    st.push(res);
                }else if(token == "/"){
                     int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    res = a /b;
                    st.push(res);
                }else if(token == "*"){
                     int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    res = a *b;
                    st.push(res);
                }else if(token == "-"){
                     int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    res = a -b;
                    st.push(res);
                }
            }
        }
        
        return st.top();
    }
};
