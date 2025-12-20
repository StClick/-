#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int maxSubarraySum(int *arr, int n, int k);
int subarraySum(vector<int> &arr, int k);
int pivotIndex(int *nums, int n);

//Задача 1 'Максимальная сумма подмассива'
int maxSubarraySum(int *arr, int n, int k)
{
   if(n < k)
   {
       cout << "Некорректные данные!" << endl;
       return -1;
   }

   int currentSum = 0;
   for(int i = 0; i < k; i++)
   {
       currentSum += arr[i];
   }
   int maxSum = currentSum;

   for(int i = k; i < n; i++)
   {
       currentSum = currentSum - arr[i - k] + arr[i];
       maxSum = max(maxSum, currentSum);
       //cout << maxSum << endl;
   }

   return maxSum;
}

//Задача 2 'Subarray Sum Equals K'
int subarraySum(vector<int> &arr, int k)
{
   unordered_map<int, int> prefixCount;
  
   int count = 0;
   int prefixSum = 0;

   for(int i = 0; i < arr.size(); i++)
   {
       prefixSum += arr[i];
       if (prefixSum == k)
           count++;

       if (prefixCount.find(prefixSum - k) != prefixCount.end())
           count += prefixCount[prefixSum - k];

       prefixCount[prefixSum]++;
   }

   return count;
}

//Задача 3 'Максимальная длина подмассива с равным количеством нулей и единиц'
int findMaxLength(vector<int> &arr)
{
   unordered_map<int,int> indexMap; indexMap[0] = -1;
   int sum = 0, maxLen = 0, len = arr.size();
   for(int i = 0; i < len; i++)
   {
      sum += arr[i] == 0 ? - 1 : 1;
      if(indexMap.find(sum) == indexMap.end())
      {
         indexMap[sum] = i;
      } 
      else if(maxLen < i - indexMap[sum])
      {
         maxLen = i - indexMap[sum];
      }
    }
    return maxLen;
}

//Задача 4 'Индекс поворота массива'
int pivotIndex(int *nums, int n)
{
   int totalSum = 0;
   int leftSum = 0;

   for (int i = 0; i < n; i++)
   {
       totalSum += nums[i];
   }

   // Проверяем каждый индекс, чтобы найти пивот
   for(int i = 0; i < n; i++)
   {
       if (leftSum == totalSum - leftSum - nums[i])
       {
           return i;
       }
       leftSum += nums[i];
   }

   return -1;
}

//Задача 5 'Баланс скобок через префиксные суммы'
bool canMakeValidWithDeletions(string s, int k)
{
   int balance = 0;
   int extra_closed_balance = 0;

   for(int i = 0; i < s.length(); i++)
   {
       if (s[i] == '(') 
       {
           balance += 1;
       }
       else 
       {
           if (balance > 0) 
           {
               balance -= 1;
           } 
           else
           {
               extra_closed_balance += 1;
           }
       }
   }

   int total_needed = balance + extra_closed_balance;

   return total_needed <= k;
}

int main()
{
   int arr[100];
   int n;
   
   cout << "Задача 1 'Максимальная сумма подмассива'" << endl;
   cout << "Для массива: ";
   for(int i = 0; i < 10; i++)
   {
      cout << i << " ";
      arr[i] = i;
   }
   cout << endl;
   cout << "Максимальная сумма подмассива длины 5 = ";
   cout << maxSubarraySum(arr, 10, 5) << endl;
   cout << "/////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 2 'Subarray Sum Equals K'" << endl;
   vector<int> vec = {3, 8, 6, 9, 2, 1, 4};
   cout << "Для массива {3, 8, 6, 9, 2, 1, 4} и k = 7:" << endl;
   int k = 11;
   cout << subarraySum(vec, k) << endl;
   cout << "/////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 3 'Максимальная длина подмассива с равным количеством нулей и единиц'" << endl;
   vec = {0, 1, 0, 0, 1};
   cout << "Для массива {0, 1, 0, 0, 1}:" << endl;
   cout << findMaxLength(vec) << endl;
   cout << "/////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 4 'Индекс поворота массива'" << endl;
   cout << "Для массива {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:" << endl;
   cout << pivotIndex(arr, 10) << endl;
   arr[0] = 9;
   arr[1] = 4;
   arr[2] = 8;
   arr[3] = 7;
   arr[4] = 1;
   arr[5] = 11;
   arr[6] = 2;
   arr[7] = 6;
   arr[8] = 1;
   cout << "Для массива {9, 4, 8, 7, 1, 11, 2, 6, 1}:" << endl;
   cout << pivotIndex(arr, 9) << endl;
   cout << "/////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 5 'Баланс скобок через префиксные суммы'" << endl;
   cout << "Для ((()()()()()))), 6" << endl;
   if(canMakeValidWithDeletions("((()()()()())))", 6))
   {
      cout << "Да!" << endl;
   }
   else
   {
      cout << "Нет!" << endl;
   }
   cout << "Для ((((((((())(((((((, 5" << endl;
   if(canMakeValidWithDeletions("((((((((())(((((((", 5))
   {
      cout << "Да!" << endl;
   }
   else
   {
      cout << "Нет!" << endl;
   }
   cout << "/////////////////////////////////////////////////////" << endl;
   
   return 0;
}
