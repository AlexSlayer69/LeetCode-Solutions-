class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        string result = "";
        map<string, int> elementCount;  // To store final counts of each element
        stack<pair<string, int>> elementStack;  // To store elements and their counts
        stack<int> multiplierStack;  // To store multipliers for nested structures
        int currentMultiplier = 1;  // Current multiplier for nested elements
        int i = 0;

        // Parse the formula
        while (i < n) {
            string element = "", countStr = "";
            int j = i;

            // Parse element name and its count
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                element += formula[i];
                j = i + 1;
                while (j < n && formula[j] >= 'a' && formula[j] <= 'z') {
                    element += formula[j];
                    j++;
                }
                while (j < n && formula[j] >= '0' && formula[j] <= '9') {
                    countStr += formula[j];
                    j++;
                }
                if (countStr == "") {
                    elementStack.push({element, 1});
                } 
                else {
                    elementStack.push({element, stoi(countStr)});
                }
                i = j;
            } 
            else if (formula[i] == '(') {
                elementStack.push({"(", 0});
                i++;
            } 
            else if (formula[i] == ')') {
                j = i + 1;
                while (j < n && formula[j] >= '0' && formula[j] <= '9') {
                    countStr += formula[j];
                    j++;
                }
                int multiplier = (countStr == "") ? 1 : stoi(countStr);
                elementStack.push({")", multiplier});
                i = j;
            }
        }

        // Process the elements in the stack and apply multipliers
        while (!elementStack.empty()) {
            string element = elementStack.top().first;
            int count = elementStack.top().second;
            if (element == ")") {
                currentMultiplier *= count;
                multiplierStack.push(count);
            } 
            else if (element == "(") {
                currentMultiplier /= multiplierStack.top();
                multiplierStack.pop();
            } 
            else {
                int adjustedCount = currentMultiplier * elementStack.top().second;
                elementCount[element] += adjustedCount;
                
            }
            elementStack.pop();
        }

        // Build the result string
        for (auto& elem : elementCount) {
            result += elem.first;
            if (elem.second != 1) {
                result += to_string(elem.second);
            }
        }

        return result;
    }
};