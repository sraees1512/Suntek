#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class Solution {
public:
int Subarray(vector<int>& nums, int k) {
lli temp = 1;
int j = 0;
int ans = 0;
for(int i = 0; i < nums.size(); i++){
temp *= nums[i];
while(temp >= k && j <= i) {
temp /= nums[j];
j++;
}
ans += (i - j + 1);
}
return ans;
}
};
main(){
Solution ob;
vector<int> v = {10,5,2,6};
cout << (ob.Subarray(v, 100));
}
