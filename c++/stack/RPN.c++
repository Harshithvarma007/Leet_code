class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
    
    for (const string& token : tokens) {
        if (token == "+") {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            st.push(operand1 + operand2);
        } else if (token == "-") {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            st.push(operand1 - operand2);
        } else if (token == "*") {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            st.push(operand1 * operand2);
        } else if (token == "/") {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            st.push(operand1 / operand2);
        } else {
            st.push(stoi(token));
        }
    }
    
    return st.top();
    }

};
