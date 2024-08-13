#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss;
    stringstream a;
    vector<int> v;
    string answer = "";
    int num;

    ss.str(s);
    
    while (ss >> num)
    {
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    
    answer = to_string(v[0]) + ' ' + to_string(v[v.size() - 1]);
    return answer;
}