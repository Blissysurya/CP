#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize(const string& str) {
    vector<string> tokens;
    for (int i = 0; i < str.length(); ++i) {
        if (i + 1 < str.length() && str.substr(i, 2) == "id") {
            tokens.push_back("id");
            i++;
        } else if (i + 1 < str.length() && str[i+1] == '\'') {
            tokens.push_back(str.substr(i, 2));
            i++;
        } else {
            tokens.push_back(string(1, str[i]));
        }
    }
    return tokens;
}

void printStep(const string& matched, stack<string>& st, const vector<string>& input_tokens, int input_ptr, const string& action) {
    cout << left << setw(20) << matched;

    stack<string> temp = st;
    vector<string> svec;
    while (!temp.empty()) {
        svec.push_back(temp.top());
        temp.pop();
    }
    reverse(svec.begin(), svec.end());
    string stack_str;
    for (const auto &x : svec) stack_str += x;
    cout << left << setw(20) << stack_str;

    string input_str;
    for (int i = input_ptr; i < input_tokens.size(); ++i) {
        input_str += input_tokens[i];
    }
    cout << left << setw(20) << input_str;

    cout << left << setw(30) << action << endl;
}

int main() {
    cout << "--- Predictive Parser Simulation ---" << endl;

    map<pair<string, string>, string> parsingTable;
    parsingTable[{"E", "id"}] = "TE'";
    parsingTable[{"E", "("}] = "TE'";
    parsingTable[{"E'", "+"}] = "+TE'";
    parsingTable[{"E'", ")"}] = "e";
    parsingTable[{"E'", "$"}] = "e";
    parsingTable[{"T", "id"}] = "FT'";
    parsingTable[{"T", "("}] = "FT'";
    parsingTable[{"T'", "+"}] = "e";
    parsingTable[{"T'", "*"}] = "*FT'";
    parsingTable[{"T'", ")"}] = "e";
    parsingTable[{"T'", "$"}] = "e";
    parsingTable[{"F", "id"}] = "id";
    parsingTable[{"F", "("}] = "(E)";

    vector<string> non_terminals = {"E", "E'", "T", "T'", "F"};

    string input_str;
    cout << "Enter input string (e.g., id+id*id$): ";
    cin >> input_str;

    vector<string> input_tokens = tokenize(input_str);
    int input_ptr = 0;

    stack<string> st;
    st.push("$");
    st.push("E");

    string matched = "";

    cout << "\n" << string(90, '-') << endl;
    cout << left << setw(20) << "MATCHED"
              << setw(20) << "STACK"
              << setw(20) << "INPUT"
              << setw(30) << "ACTION" << endl;
    cout << string(90, '-') << endl;

    printStep(matched, st, input_tokens, input_ptr, "Initial State");

    while (!st.empty() && st.top() != "$") {
        string top = st.top();
        string current_input_token = input_tokens[input_ptr];
        
        if (top == current_input_token) {
            st.pop();
            matched += current_input_token;
            input_ptr++;
            printStep(matched, st, input_tokens, input_ptr, "Match " + current_input_token);
        } 
        
        else if (find(non_terminals.begin(), non_terminals.end(), top) != non_terminals.end()) {
            if (parsingTable.count({top, current_input_token})) {
                string production = parsingTable.at({top, current_input_token});
                string action = top + "->" + (production == "e" ? "epsilon" : production);
                st.pop();
                
                if (production != "e") {
                    vector<string> prod_tokens = tokenize(production);
                    for (int i = prod_tokens.size() - 1; i >= 0; --i) {
                        st.push(prod_tokens[i]);
                    }
                }
                printStep(matched, st, input_tokens, input_ptr, action);
            } else {
                 printStep(matched, st, input_tokens, input_ptr, "ERROR: No rule in table!");
                 break;
            }
        }
        
        else {
            printStep(matched, st, input_tokens, input_ptr, "ERROR: Mismatch!");
            break;
        }
    }

    cout << string(90, '-') << endl;
    if (st.top() == "$" && input_tokens[input_ptr] == "$") {
         printStep(matched, st, input_tokens, input_ptr, "ACCEPT: String parsed successfully!");
    } else {
         printStep(matched, st, input_tokens, input_ptr, "REJECT: Parsing failed!");
    }

    return 0;
}