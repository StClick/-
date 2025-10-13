#include <iostream>

using namespace std;

void twoSum(int* nums, int target, int n);
void reverseArray(int* arr, int left, int right);
void reverseArray_2(int* arr, int n, int k);
void merge_sorted_arrays(int* arr1, int* arr2, int right1, int right2);
void sort_binary_array(int* arr, int n);
void sortColors(int* nums, int n);
void evenFirst(int* arr, int n); 
void zero(int* arr, int n);

// Задача 1 "Две суммы"
void twoSum(int* nums, int target, int n)
{
   int left = 0, right = n - 1, sum;
   cout << "Ответ на задачу 1 для target == " << target << ":";
   while(left < right)
   {
      sum = nums[left] + nums[right];
      if(sum == target)
      {
         cout << " следующие индексы " << left << " " << right << endl;
         return;
      }
      else if(sum < target)
      {
         left++;
      }
      else
      {
         right--;
      }
   }
   
   cout << " таких индексов в данном массиве нет" << endl;
}

// Задача 2 "Развернуть массив"

void reverseArray(int* arr, int left, int right)
{
   int temp;
   for(left; left < right; left++)
   {
      temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
      right--;
   }
}

// Задача 3 "Развернуть часть массива"

void reverseArray_2(int* arr, int n, int k)
{
   k = k % n;
   reverseArray(arr, 0, n - 1);
   reverseArray(arr, 0, k - 1);
   reverseArray(arr, k, n - 1);
}

// Задача 4 "Слияние двух отсортированных массивов"

void merge_sorted_arrays(int* arr1, int* arr2, int right1, int right2)
{
   int l = right1 - right2 - 1, r = right1, p = right2;
   while(p >= 0)
   {
      if(l >= 0 && arr1[l] > arr2[p])
      {
         arr1[r] = arr1[l];
         l--;
      }
      else
      {
         arr1[r] = arr2[p];
         p--;
      }
      r--;
   }
}

// Задача 5 "Сортировка массива из 0 и 1"

void sort_binary_array(int* arr, int n)
{
   int left = 0, right = n - 1;
   while(left < right) 
   {
      if(arr[left] == 0) 
      {
          left++;
      } 
      else if(arr[right] == 1) 
      {
          right--;
      } 
      else 
      {
          arr[left] = 0; 
          arr[right] = 1;
          left++;
          right--;
      }
   }
}

// Задача 6 "Задача флага Нидерландов"

void sortColors(int* nums, int n)
{
   int low = 0, mid = 0, high = n - 1;
   while(mid <= high) 
   {
      if(nums[mid] == 0) 
      {
         nums[mid] = nums[low];
         nums[low] = 0; 
         low++;
         mid++;
      } 
      else if(nums[mid] == 1) 
      {
          mid++;
      } 
      else if(nums[mid] == 2) 
      {
         nums[mid] = nums[high];
         nums[high] = 2;
         high--;
      }
   }
}

// Задача 7 "Передвинуть четные числа вперед"

void evenFirst(int* arr, int n)
{
   int evenIndex = 0, temp;
   for(int i = 0; i < n; i++) 
   {
      if(arr[i] % 2 == 0) 
      {
         temp = arr[i];
         arr[i] = arr[evenIndex];
         arr[evenIndex] = temp;
         evenIndex++;
      }
   }
}

// Задача 8 "Нули в конец"

void zero(int* arr, int n)
{
   int left = 0, right = n - 1;
   while(left < right)
   {
      if(arr[left] == 0)
      {
         arr[left] = arr[right];
         arr[right] = 0;
         right--;
      }
      else
      {
         left++;  
      }
   }
}

int main ()
{
   int nums[] = {3, 8, 9, 11, 16, 18, 19, 21};
   int arr[] = {3, 8, 6, 9, 9, 8, 6};
   int arr_2[] = {1, 2, 3, 4, 5, 6, 7};
   int sort_1[] = {3, 8, 10, 11, 0, 0, 0};
   int sort_2[] = {1, 7, 9};
   int zero_one[] = {0, 1, 1, 0, 1, 0, 1, 0};
   int zero_one_two[] = {2, 0, 1, 0, 2, 0, 2, 1};
   int even[] = {3, 2, 4, 1, 11, 8, 9};
   int z[] = {0, 5, 4, 0, 5, 0, 1, 2};
   twoSum(nums, 25, size(nums));
   reverseArray(arr, 0, size(arr) - 1);
   reverseArray_2(arr_2, size(arr), 3);
   merge_sorted_arrays(sort_1, sort_2, size(sort_1)-1, size(sort_2)-1);
   sort_binary_array(zero_one, size(zero_one));
   sortColors(zero_one_two, size(zero_one_two));
   evenFirst(even, size(even));
   zero(z, size(z));
   return 0;
}
