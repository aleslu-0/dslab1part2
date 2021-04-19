#include <iostream>
#include <dslab1part2.h>
#include <string>
#include <queue>
#include <stack>
#include <chrono>
using namespace std::chrono;
using namespace std;


bool testPalStack(string s) {
    stack<char> t;
    bool isPalindrome;
    for(int i = s.size(); i >= 0; i--){
        t.push(s[i]);
    }
    isPalindrome = true;
    for (int i = 1; i <= s.size() && isPalindrome; i++) //breaks if isPalindrome is false
    {
        isPalindrome = t.top() == s[s.size() - i]; //isPalindrome is set through comparing strings
        t.pop();
    }
    return isPalindrome;
}

bool testPalQueue(string s) {
    queue <char> q;
    bool isPalindrome = true;
    for (int i = 0; i < s.size(); i++) {
        q.push(s[i]);
    }  
    for (int i = 1; i <= s.size() && isPalindrome; i++) //breaks if isPalindrome is false
    {
        isPalindrome = q.front() == s[s.size() - i]; //isPalindrome is set through comparing strings
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
    while (true) {
        string str;
        cout << "Enter test: ";
        getline(cin, str);
        str = fixText(str);
        //cout << "it is: " << boolalpha << testPalQueue(str); //Queue
        //cout << "it is: " << boolalpha << testPalStack(str); //Stack
        high_resolution_clock::duration totalTime(0);
        for (int i = 0; i < 1000; i++) {
            auto start = high_resolution_clock::now();
            //testPalStack(str); //21000 ~ 25000 at 1000 iterations
            testPalQueue(str); //19000 ~ 23000 at 1000 iterations
            auto end = high_resolution_clock::now();
            totalTime = totalTime + (end - start);
        }
        auto average = totalTime.count() / 1000;
        cout << "the average time is: " << average << " nanoseconds\n";
    }
   
}
