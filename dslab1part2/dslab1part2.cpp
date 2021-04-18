#include <iostream>
#include <dslab1part2.h>
#include <string>
#include <queue>
#include <stack>
using namespace std;


bool testPalStack(string s) {
    stack<char> t;
    bool isPalindrome;
    for(int i = s.size(); i >= 0; i--){
        t.push(s[i]);
    }
    isPalindrome = true;
    for (int i = 1; i <= s.size() && isPalindrome; i++)
    {
        isPalindrome = t.top() == s[s.size() - i];
        t.pop();
    }
    return isPalindrome;
}

bool testPalQueue(string s) {
    queue <char> q;
    bool isPalindrome;
    for (int i = 0; i < s.size(); i++) {
        q.push(s[i]);
    }  
    isPalindrome = true;
    for (int i = 1; i <= s.size() && isPalindrome; i++)
    {
        isPalindrome = q.front() == s[s.size() - i];
        q.pop();
    }
    return isPalindrome;
}

string fixText(string s) {
    for (int i = 0, len = s.size(); i < len; i++) {
        if (s[i] == ' ' || s[i] == '.' || s[i] == ',') {
            s.erase(i--, 1);
            len = s.size();
        }
    }

    for (int i = 0, len = s.size(); i < len; i++) {
        {
            s[i] = tolower(s[i]);
        }
    }

    return(s);
}
int main()
{
    string str;
    cout << "Enter test: ";
    getline(cin, str);
    str = fixText(str);
    //cout << "it is: " << boolalpha << testPalQueue(str);
    cout << "it is: " << boolalpha << testPalStack(str);
}
