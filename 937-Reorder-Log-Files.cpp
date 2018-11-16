#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    vector<string> reorderLogFiles(vector<string>& logs) {
        if(logs.size() < 2) return logs;

        bool flag = true;
        int temp;
        vector<int> pos(logs.size());

        for(int i = 0; i < logs.size(); i++) 
            /* record the position of first words after identifier for each logs */
            pos[i] = logs[i].find_first_of(' ') + 1;
        
        
        while(flag)
        {
            flag = false;
            for(int i = 0; i < logs.size() - 1; i++)
            {
                
                if(logs[i][pos[i]] >= '0' && logs[i][pos[i]] <= '9' && 
                   logs[i + 1][pos[i + 1]] >= 'a') 
                   /* logs[i] is digit-logs and logs[i + 1] isn't */
                {
                    temp = pos[i]; pos[i] = pos[i + 1]; pos[i + 1] = temp;
                    logs[i].swap(logs[i + 1]);
                    flag = true;
                }
                else if(logs[i][pos[i]] >= 'a' && logs[i + 1][pos[i + 1]] >= 'a')
                { 
                    /* logs[i] and logs[i + 1] are both letter-digits and logs[i] > logs[i + 1] */  
                    if(logs[i].compare(pos[i], logs[i].length() - pos[i], 
                            logs[i+1], pos[i+1], logs[i+1].length() - pos[i+1]) > 0 )
                    {
                        temp = pos[i]; pos[i] = pos[i + 1]; pos[i + 1] = temp;
                        logs[i].swap(logs[i + 1]);
                        flag = true;
                    }
                }
            }
        }

        return logs;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
