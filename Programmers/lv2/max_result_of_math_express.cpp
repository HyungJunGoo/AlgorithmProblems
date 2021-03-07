#include <bits/stdc++.h>

using namespace std;


class Solution
{
    public:
        
        long long solution(string expression) {

            // Find kinds of operator (set)
            set<char> set_operators;
            for (char c : expression)
            {
                if(int(c) == 42 || int(c) == 43 || int(c) == 45){
                    set_operators.insert(c);
                }
            }
            int num = set_operators.size(); // number of kinds
            vector<char> operators;
            for(auto o : set_operators){
                operators.push_back(o);
            }
            sort(operators.begin(), operators.end());
            
            // Create combinations of cases from set of opreators
            vector<vector<char> > combinations;
            do
            {
                vector<char> tmp_case;
                for(int i =0; i<num; i++){
                    tmp_case.push_back(operators[i]);
                }
                combinations.push_back(tmp_case);
            } while (next_permutation(operators.begin(), operators.begin() + num));
            
            // Make easier with expressions (list of numbers, list of operators)
            vector<long long> l_numbers;
            vector<char> l_operators;
            string tmp_number = "";
            for (int i=0; i<expression.length(); i++){
                int int_of_char = int(expression[i]);
                
                if (int_of_char == 42 || int_of_char == 43 || int_of_char == 45 ){
                    l_numbers.push_back(stoi(tmp_number));
                    tmp_number = "";
                    l_operators.push_back(expression[i]);
                }
                else{
                    tmp_number += expression[i];
                }
            }
            l_numbers.push_back(stoi(tmp_number));

            long long maximum = 0;

            for (int i = 0; i < combinations.size(); i++)
            {
                string tmp_expression = expression;
                vector<char> order_operation = combinations[i];
                // make temporary little vecotr of original l_numbers, l_operators
                vector<long long> l_n; 
                vector<char> l_o;
                // copy
                for (int n : l_numbers)
                    l_n.push_back(n);
                for (char o : l_operators)
                    l_o.push_back(o);
                
                // main calculation
                for(int j=0; j<num; j++){
                    // choose current operator
                    char cur_oper = order_operation[j];
                    int idx_in_o = 0;
                    while(l_o.size() > 0 && idx_in_o < l_o.size()){
                        
                        // 3 times 
                        if(l_o[idx_in_o] == cur_oper){
                            long long num1 = l_n[idx_in_o];
                            long long num2 = l_n[idx_in_o+1];
                            long long result = 0;
                            l_n.erase(l_n.begin()+idx_in_o, l_n.begin()+idx_in_o+2);
                            
                            switch (l_o[idx_in_o])
                            {
                                case '+':
                                    result = num1 + num2;
                                    break;
                                case '*':
                                    result = num1 * num2;
                                    break;
                                case '-':
                                    result = num1 - num2;
                                    break;
                            }
                            l_o.erase(l_o.begin()+idx_in_o);
                            l_n.insert(l_n.begin()+idx_in_o, result);
                            
                        }
                        else{
                            idx_in_o += 1;
                        }   
                    }
                    
                }                
                
                if (abs(l_n[0]) > maximum){
                    maximum = abs(l_n[0]);
                }
            }
            return maximum;
        }
};

int main(){
    Solution solution;
    cout << solution.solution("100-200*300-500+20") << endl;
    cout << solution.solution("50*6-3*2") << endl;
    
    
    return 0;
}