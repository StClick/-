#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int binarySearchSqrt(int target);
int copyTime(int n, int x, int y);
int feedAnimals(int *animals, int count_animals, int *food, int count_food);
void arr_out(int *a, int n);
string extraLetter(string a, string b);
void twoSum(int data, int n, int target);
void anagramma(vector<string>& vec);
void shell_sort(int *arr, int n);  

//Задача 1 "Найти ближайший ЦЕЛЫЙ корень числа"
int binarySearchSqrt(int target)
{
   int l = 0, r = target, middle;
   if(target < 0) return -1;
   if(r > 1) r = r / 2;
   while(l <= r) 
   {
      middle = l + (r - l) / 2;
      if(middle * middle > target)
      {
          r = middle - 1;
          continue;
      }
      if(middle * middle < target)
      {
          l = middle + 1;
          continue;
      }
      return middle;
   }
   return r;
}

//Задача 2 "Очень лёгкая задача"
int copyTime(int n, int x, int y)
{
   int l = 0, max, min, r, mid;
   if(x > y)
   {
      max = x;
      min = y;
   }
   else
   {
      max = y;
      min = x;
   }
   r = (n - 1) * max;
   while(l + 1 < r)
   {
      mid = l + (r - l) / 2;
      if(mid/x + mid/y < n - 1) 
      {
         l = mid;
      } 
      else
      {
         r = mid;
      }
   }
   return r + min;
}

//Задача 3 "Накормить животных"
int feedAnimals(int *animals, int count_animals, int *food, int count_food)
{
   if(count_animals == 0 || count_food == 0) return 0;
   
   int count = 0;
   
   sort(animals, animals + count_animals);
   sort(food, food + count_food);
   
   for(int f = 0; f < count_food; f++)
   {
       if(food[f] >= animals[count])
       {
           count += 1;
       }
       if(count == count_animals) break;
   }
   
   return count;
}

void arr_out(int *a, int n)
{
   cout << "[";
   for(int i = 0; i < n; i++)
   {
      if(i != n-1)
      {
         cout << a[i] << ", ";
      }
      else
      {
         cout << a[i];
      }
   }
   cout << "]" << endl;
}

//Задача 4 "Найти разницу между двух строк"
string extraLetter(string a, string b)
{
   string s;
   map<string, int> hashMapA = {};
   for(int i = 0; i < a.size(); i++)
   {
      s = a[i];
      hashMapA[s]++;
   }
   
   for(int i = 0; i < b.size(); i++)
   {
      s = b[i];
      if(hashMapA.count(s) > 0)
      {
          hashMapA[s]--;
          if(hashMapA[s] == 0)
          {
             hashMapA.erase(s);
             continue;
          }
          continue;
      }
      return s;
   }
   return "";
}

//Задача 5 "Сумма двух элементов"
void twoSum(int *data, int n, int target)
{
   int diff;
   map<int, int> cache = {};
   for(int i = 0; i < n; i++)
   {
       cache[data[i]] = i;
   }
   for(int i = 0; i < n; i++)
   {
       diff = target - data[i];
       if(cache.count(diff) > 0)
       {
          cout << i << " " << cache[diff] << endl;
          return;
       }
  }
  cout << "Нет совпадений" << endl;
}

//Задача 6 "Массив анаграмм"
void anagramma(vector<string>& vec)
{
   map<string, vector<string>> junk;
   for(int i = 0; i < vec.size(); i++) 
   {
      string word(vec[i]);
      sort(word.begin(),word.end()); //сортируем буквы слова
      junk[word].push_back(vec[i]); //добавляем в соответствующую группу
   }
   //вывод
   for(auto j: junk)
   {
      vector<string> poop(j.second); // j.first - ключ (отсортированная версия слова), а j.second - значение (вектор оригинальных слов-анаграмм)
      //выводим все слова из группы анаграмм
      for(int i = 0; i < poop.size(); i++)
      {
         cout << poop[i] << " ";
      }  
      cout << endl;
    }
}

//Задача 7 "Сортировка Шелла"
void shell_sort(int *arr, int n)
{
   int m_gap, gap = n / 2, help;
   while(gap > 0)
   {
      for(int current_position = gap; current_position < n; current_position++) 
      {
         m_gap = current_position;
         while(m_gap >= gap && arr[m_gap] < arr[m_gap - gap])
         {
            help = arr[m_gap];
            arr[m_gap] = arr[m_gap - gap];
            arr[m_gap - gap] = help;
            m_gap = m_gap - gap;
         }
      }
      gap = gap / 2;
   }
}

int main()
{
    int target;
    int animals[10] = {3, 4, 7}, food[10] = {8, 1, 2}, data[10];
    int arr[10];
    cout << "Задача 1 'Найти ближайший ЦЕЛЫЙ корень числа'" << endl;
    cout << "Для 0: " << binarySearchSqrt(0) << endl;
    cout << "Для 1: " << binarySearchSqrt(1) << endl;
    cout << "Для 2: " << binarySearchSqrt(2) << endl;
    cout << "Для 3: " << binarySearchSqrt(3) << endl;
    cout << "Для 4: " << binarySearchSqrt(4) << endl;
    cout << "Для 25: " << binarySearchSqrt(25) << endl;
    cout << "Для 69: " << binarySearchSqrt(69) << endl;
    cout << "Для 100: " << binarySearchSqrt(100) << endl;
    cout << "Для 1024: " << binarySearchSqrt(1024) << endl;
    cout << "Для 2000: " << binarySearchSqrt(2000) << endl;
    cout << "/////////////////////////////////////////////" << endl;
    
    cout << "Задача 2 'Очень лёгкая задача'" << endl;
    cout << "Для 11 листов, 1 секунда, 1 секунда: " << copyTime(11, 1, 1) << endl;
    cout << "Для 19 листов, 10 секунд, 2 секунд: " << copyTime(19, 10, 2) << endl;
    cout << "Для 100 листов, 5 секунд, 10 секунд: " << copyTime(100, 5, 10) << endl;
    cout << "Для 1000 листов, 1 секунда, 2 секунды: " << copyTime(1000, 1, 2) << endl;
    cout << "/////////////////////////////////////////////" << endl;
    
    cout << "Задача 3 'Накормить животных'" << endl;
    cout << "Животные: ";
    arr_out(animals, 3);
    cout << "Еда: ";
    arr_out(food, 3);
    cout << "К-во накормленных животных: ";
    cout << feedAnimals(animals, 3, food, 3) << endl;
    
    animals[0] = 3;
    animals[1] = 8;
    animals[2] = 1;
    animals[3] = 4;
    food[0] = 1;
    food[1] = 1;
    food[2] = 2;
    cout << "Животные: ";
    arr_out(animals, 4);
    cout << "Еда: ";
    arr_out(food, 3);
    cout << "К-во накормленных животных: ";
    cout << feedAnimals(animals, 4, food, 3) << endl;
    
    animals[0] = 1;
    animals[1] = 2;
    animals[2] = 2;
    food[0] = 7;
    food[1] = 1;
    cout << "Животные: ";
    arr_out(animals, 3);
    cout << "Еда: ";
    arr_out(food, 2);
    cout << "К-во накормленных животных: ";
    cout << feedAnimals(animals, 3, food, 2) << endl;
    
    animals[0] = 8;
    animals[1] = 2;
    animals[2] = 3;
    animals[3] = 2;
    food[0] = 1;
    food[1] = 4;
    food[2] = 3;
    food[3] = 8;
    cout << "Животные: ";
    arr_out(animals, 4);
    cout << "Еда: ";
    arr_out(food, 4);
    cout << "К-во накормленных животных: ";
    cout << feedAnimals(animals, 4, food, 4) << endl;
    cout << "/////////////////////////////////////////////" << endl;
    
    cout << "Задача 4 'Найти разницу между двух строк'" << endl;
    cout << "строка a: uio строка b: oeiu результат: ";
    cout << extraLetter("uio", "oeiu") << endl;
    
    cout << "строка a: fe строка b: efo результат:: ";
    cout << extraLetter("fe", "efo") << endl;
    
    cout << "строка a: ab строка b: ab результат: ";
    cout << extraLetter("ab", "ab") << endl;
    
    cout << "строка a: bbb строка b: bbbb результат: ";
    cout << extraLetter("bbb", "bbbb") << endl;
    cout << "/////////////////////////////////////////////" << endl;
    
    cout << "Задача 5 'Сумма двух элементов'" << endl;
    for(int i = 0; i < 10; i++)
    {
       data[i] = i * 10;
    }
    arr_out(data, 10);
    cout << "Сумма = 9, соответствующие индексы элементов: " << endl;
    twoSum(data, 10, 9);
    arr_out(data, 10);
    cout << "Сумма = 10, соответствующие индексы элементов: " << endl;
    twoSum(data, 10, 10);
    data[0] = 100;
    data[1] = 23;
    data[2] = 58;
    data[3] = 71;
    data[4] = 55;
    data[5] = 69;
    data[6] = 148;
    data[7] = 97;
    data[8] = 1;
    data[9] = 96;
    arr_out(data, 10);
    cout << "Сумма = 169, соответствующие индексы элементов: " << endl;
    twoSum(data, 10, 169);
    cout << "/////////////////////////////////////////////" << endl;
    
    cout << "Задача 6 'Массив анаграмм'" << endl;
    vector<string> a;
    a.push_back("eat");
    a.push_back("tea");
    a.push_back("tan");
    a.push_back("ate");
    a.push_back("nat");
    a.push_back("bat");
    anagramma(a);
    
    cout << "/////////////////////////////////////////////" << endl;
    
    cout << "Задача 7 'Сортировка Шелла'" << endl;
    cout << "Было: ";
    for(int i = 0; i < 10; i++)
    {
       arr[i] = 10 - i;
       cout << arr[i] << " ";
    }
    cout << endl << "Стало: ";
    shell_sort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
       cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Было: ";
    for(int i = 0; i < 10; i++)
    {
       arr[i] = rand() % 100 + 1;
       cout << arr[i] << " ";
    }
    cout << endl << "Стало: ";
    shell_sort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
       cout << arr[i] << " ";
    }
    return 0;
}
