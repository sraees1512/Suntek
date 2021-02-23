#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
vector < pair <int, int> > sorted;
int n = indexes.size();
for(int i = 0; i < n; i++){
sorted.push_back({indexes[i], i});
}
sort(sorted.rbegin(), sorted.rend());
for(int j = 0; j < n; j++){
int i = sorted[j].first;
string source = sources[sorted[j].second];
string target = targets[sorted[j].second];
if(S.substr(i, source.size()) == source){
S = S.substr(0, i) + target + S.substr(i + source.size());
}
}
return S;
}
};
int main(){
vector<int> v1 = {0,2};
vector<string> v2 = {"a", "cd"};
vector<string> v3 = {"eee", "ffff"};
Solution ob;
cout << (ob.findReplaceString("abcd", v1, v2, v3));
}
