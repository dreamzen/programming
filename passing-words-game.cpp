#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> word_game(map<string, string>m, vector<string> words, int people)
    {
        int len = words.size();
        vector<string> result;
        map<string, string>::iterator ite;
        for(int i = 0; i < len; i++)
        {
            string str = words[i];
            for(int j = 0; j < people - 1; j++)
            {
                ite = m.find(str);
                if(ite == m.end())
                {
                    break;
                }
                else
                {
                    str = ite->second;
                }
            }
            result.push_back(str);
        }
        return result;
    }
};

int main()
{
    int k;
    cin >> k;
    vector<vector<string> > v;
    for(int i = 1; i <= k; i++)
    {
        map<string, string> m;
        int people, table;
        cin >> people >> table;
        for(int j = 0; j < table; j++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            m.insert(make_pair(s1, s2));
        }
        string str;
        getline(cin, str);
        getline(cin, str);
        const char *const_line = str.c_str();
        char *line = new char[strlen(const_line) + 1];
        strcpy(line, const_line);
        vector<string> words;
        char *word;
        word = strtok(line, " ");
        while(word != NULL)
        {
            words.push_back(word);
            word = strtok(NULL, " ");
        }
            
        Solution s;
        vector<string> result = s.word_game(m, words, people);
        v.push_back(result);
    }
    for(int i = 1; i <= k; i++)
    {
        vector<string> result = v[i - 1];
        int len = result.size();
        int j;
        cout << "Case #" << i << ": ";
        for(j = 0; j < len - 1; j++)
        {
            cout << result[j] << " ";
        }
        cout << result[j] << endl;
    }
    return 0;
}
        
