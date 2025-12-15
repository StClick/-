#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int count_sequences(int n);
int findLIS(int *nums, int n);
void pascal(int n);
int maxProfit(int *prices, int n);
int coinChange(int *coins, int amount, int n);

//Задача 1 'Последовательность из 0 и 1' (случай трех единиц)
int count_sequences(int n)
{
   if(n > 1000)
   {
       return -1;
       cout << "Слишком много...." << endl;
   }
   if(n == 0) return 1;
   if(n == 1) return 2;
   if(n == 2) return 4;

   int dp[1000];
   dp[0] = 1;
   dp[1] = 2;
   dp[2] = 4;
   for(int i = 3; i <= n; i++)
   {
       dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
   }

   return dp[n];
}

//Задача 2 'Наибольшая непрерывная возрастающая последовательность'
int findLIS(int *nums, int n)
{
   if(n == 0) return 0;
   if(n == 1) return 1;

   int max = 0, k = 0;
   for(int i = 1; i < n; i++)
   {
       if(nums[i] > nums[i-1])
       {
           k++;
       }
       else
       {
           k = 1;
       }
       if(k > max) max = k;
   }
   return max;
}

//Задача 3 'Треугольник Паскаля'
void pascal(int n)
{
    int pas[n][n];
    for(int raw = 0; raw < n; raw++)
    {
        for(int col = 0; col <= raw; col++)
        {
            if(raw == col || col == 0)
            {
                pas[raw][col] = 1;
            }
            else
            {
                pas[raw][col] = pas[raw - 1][col - 1] + pas[raw - 1][col];
            }
            cout << pas[raw][col] << " ";
        }
        cout << endl;
    }
}

//Задача 4 'Максимальная выгода'
int maxProfit(int *prices, int n)
{
    int profit = 0;
    int min_price = prices[0];
    for(int i = 1; i < n; i++)
    {
        if(profit < prices[i] - min_price)
        {
            profit = prices[i] - min_price;
        }
        if(prices[i] < min_price)
        {
            min_price = prices[i];
        }
    }
    return profit;
}

//Задача 5 'Размен монет'
int coinChange(int *coins, int amount, int n)
{
   int dp[amount+1];
   for(int i = 0; i <= amount; i++)
   {
       dp[i] = 10000;
   }
   dp[0] = 0;
   for(int i = 1; i <= amount; i++)
   {
       for(int j = 0; j < n; j++)
       {
           if (coins[j] <= i)
           {
               dp[i] = min(dp[i], dp[i - coins[j]] + 1);
           }
       }
   }
   if(dp[amount] == 10000)
   {
      return -1;
   }
   return dp[amount];
}

//Задача 6 'Максимальный палиндром в строке'
string longestPalindrome(string s)
{
   int first = 0, max = 1;
   int n = s.size();
   vector<vector<bool>> dp(n, vector<bool>(n, false)); //зафолсили все ячейки
    
   //Каждая буква сама по себе является палиндромом, поэтому в диагонали всегда true
   for(int i = 0; i < n; i++) dp[i][i] = true;
   
   //Двухбуквенные строки
   for(int i = 0; i < n - 1; i++)
   {
      if(s[i] == s[i+1])
      {
         dp[i][i+1] = true;
         if(max == 1)
         {
            first = i;
            max = 2;
         }
      }
   }
   
   //Трехбуквенные строки и больше
   for(int len = 3; len <= n; len++)
   {
      for (int i = 0; i <= n-len; i++)
      {
         int j = i+len-1;
            if(s[i] == s[j] && dp[i+1][j-1])
            { 
               dp[i][j] = true;
               if(len > max)
               {
                  first = i;
                  max = len;
               }
            }
       }
    }
    return s.substr(first, max);
}

int main()
{
   int nums[100], n;
   string s;

   cout << "Задача 1 'Последовательность из 0 и 1' (случай трех единиц)" << endl;
   cout << "Для n = 1: " << count_sequences(1) << endl;
   cout << "Для n = 2: " << count_sequences(2) << endl;
   cout << "Для n = 3: " << count_sequences(3) << endl;
   cout << "Для n = 4: " << count_sequences(4) << endl;
   cout << "////////////////////////////////////////////////////////////////////" << endl;

   cout << "Задача 2 'Наибольшая непрерывная возрастающая последовательность'" << endl;
   nums[0] = 3;
   nums[1] = 1;
   nums[2] = 4;
   nums[3] = 7;
   nums[4] = 2;
   nums[5] = 11;
   nums[6] = 9;
   n = 7;
   cout << "Для массива: " << endl;
   for(int i = 0; i < n; i++)
   {
       cout << nums[i] << " ";
   }
   cout << endl;
   cout << "Наибольшая длина непрерывно возрастающей последовательности: " << findLIS(nums, n) << endl;

   cout << "Для массива: " << endl;
   for(int i = 0; i < n; i++)
   {
       nums[i] = 10;
       cout << nums[i] << " ";
   }
   cout << endl;
   cout << "Наибольшая длина непрерывно возрастающей последовательности: " << findLIS(nums, n) << endl;
   cout << "////////////////////////////////////////////////////////////////////" << endl;

   cout << "Задача 3 'Треугольник Паскаля'" << endl;
   cout << "Для n = 3" << endl;
   pascal(3);
   cout << "Для n = 4" << endl;
   pascal(4);
   cout << "Для n = 5" << endl;
   pascal(5);
   cout << "Для n = 6" << endl;
   pascal(6);
   cout << "////////////////////////////////////////////////////////////////////" << endl;

   cout << "Задача 4 'Максимальная выгода'" << endl;
   nums[0] = 8;
   nums[1] = 9;
   nums[2] = 3;
   nums[3] = 7;
   nums[4] = 4;
   nums[5] = 16;
   nums[6] = 12;
   cout << "Для массива: " << endl;
   for(int i = 0; i < n; i++)
   {
       cout << nums[i] << " ";
   }
   cout << endl;
   cout << "Наибольшая выгода: " << maxProfit(nums, n) << endl;
   cout << "////////////////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 5 'Размен монет'" << endl;
   nums[0] = 1;
   nums[1] = 2;
   nums[2] = 5;
   n = 3;
   cout << "coins = [";
   for(int i = 0; i < n; i++)
   {
       cout << nums[i];
       if(i+1 != n) cout << ", ";
   }
   cout << "], amount = 11" << endl;
   cout << "Результат: " << coinChange(nums, 11, n) << endl;
   
   nums[0] = 2;
   n = 1;
   cout << "coins = [";
   for(int i = 0; i < n; i++)
   {
       cout << nums[i];
       if(i+1 != n) cout << ", ";
   }
   cout << "], amount = 3" << endl;
   cout << "Результат: " << coinChange(nums, 3, n) << endl;
   cout << "////////////////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 6 'Максимальный палиндром в строке'" << endl;
   s = "babad";
   cout << "Для " << s << " максимальный палиндром = ";
   s = longestPalindrome(s);
   cout << s << endl;
   
   s = "hslvfhslkhfgvklmasamj";
   cout << "Для " << s << " максимальный палиндром = ";
   s = longestPalindrome(s);
   cout << s << endl;
   return 0;
}
