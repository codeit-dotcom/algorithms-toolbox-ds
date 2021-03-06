#include <iostream>
#include <string>
#include<vector>

using std::string;
  using std::vector;
int min(int a, int b, int c)
{
  return (a <= b && a <= c) ? a : (b <= a && b <= c) ? b : c;
}
int edit_distance(const string &str1, const string &str2) {
  int sr1len=str1.length();
  int sr2len=str2.length();
  vector<vector<int>> dp(sr1len+1,vector<int>(sr2len+1,0));
  for(int i=0;i<=sr1len;i++){
    dp[i][0]=i;
  }
  for(int i=0;i<=sr2len;i++){
    dp[0][i]=i;
  }
  for(int i=1;i<=sr1len;i++){
    for(int j=1;j<=sr2len;j++){
          if(str1[i-1]==str2[j-1]){
            dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]);
          }else{dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1);}
    }
  }
  return dp[sr1len][sr2len];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
