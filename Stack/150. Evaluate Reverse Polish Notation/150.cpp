class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 把tokens往stack放，如果遇到operation的話，就可以把stack內的東西吐出來
        stack <int> s;
        for(string str: tokens){
            if(str=="+"||str=="-"||str=="*"||str=="/"){
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                if(str=="+"){
                    s.push(a+b);
                }
                if(str=="-"){
                    s.push(b-a);
                }
                if(str=="*"){
                    s.push(a*b);
                }
                if(str=="/"){
                    s.push(b/a);
                }
            }
            else s.push(stoi(str));
            
        }
        return s.top();
    }
};
