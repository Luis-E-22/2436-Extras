#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
 stack<char> st;
    
    // Define matching pairs of brackets
    unordered_map<char, char> matchingBrackets = {{')', '('}, {']', '['}, {'}', '{'}};
    
    // Traverse the string
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // If it's an opening bracket, push it onto the stack
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            // If it's a closing bracket, check the stack
            if (st.empty() || st.top() != matchingBrackets[c]) {
                return "NO";  // If no match or stack is empty, return "NO"
            }
            st.pop();  // Pop the matching opening bracket
        }
    }
    
    // If the stack is empty, all brackets were matched; otherwise, they weren't
    return st.empty() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

