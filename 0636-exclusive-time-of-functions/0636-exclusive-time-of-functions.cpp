class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        int num = logs.size();
        stack<pair<int, pair<string, int>>> logStack;
        for (int i = 0; i < num; i++)
        {
            string log = logs[i];
            string startOrEnd;
            int idOrTimeStamp = 0;
            int id, timeStamp;
            int pointer = 1;
            for (int j = 0; j < log.size(); j++)
            {
                char ch = log[j];
                if (ch >= 48 && ch <= 57)
                    idOrTimeStamp = 10 * idOrTimeStamp + (ch - 48);
                else if (ch >= 97 && ch <= 122)
                    startOrEnd.push_back(ch);
                else
                {
                    if (pointer == 1)
                        id = idOrTimeStamp;
                    pointer++;
                    idOrTimeStamp = 0;
                }
            }
            if (pointer == 3)
                timeStamp = idOrTimeStamp;
            if (startOrEnd == "start")
                logStack.push({id, {startOrEnd, timeStamp}});
            else
            {
                pair<int, pair<string, int>> topLog = logStack.top();
                result[topLog.first] += (timeStamp - topLog.second.second + 1);
                logStack.pop();
                if (!logStack.empty())
                    result[logStack.top().first] -= (timeStamp - topLog.second.second + 1);
            }
            startOrEnd.clear();
        }
        return result;
    }
};