#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        char stack[100000];
        long index = -1;
        if (!abs(s.compare("")))
            return true;
        if (s.at(0) == ')' || s.at(0) == ']' || s.at(0) == '}')
        {
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
            {
                index++;
                stack[index] = s.at(i);
            }
            else if (s.at(i) == ')')
            {
                if (index > -1 && stack[index] == '(')
                    index--;
                else
                    return false;
            }
            else if (s.at(i) == ']')
            {
                if (index > -1 && stack[index] == '[')
                    index--;
                else
                    return false;
            }
            else if (s.at(i) == '}')
            {
                if (index > -1 && stack[index] == '{')
                    index--;
                else
                    return false;
            }
        }
        if (index > -1)
            return false;
        return true;
    }
};

int main(int argc, const char *argv[])
{
    //    string a = "test";
    bool res;
    Solution test;
    res = test.isValid("{}][}}{[))){}{}){(}]))})[({");
    cout << res << endl;
    return 0;
}