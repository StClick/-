#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
   int data;
   int balance_factor;
   Node* left;
   Node* right;
};

Node* TreeNode(int data)
{
    Node* p = new Node();
    p->data = data;
    p->left = p->right = nullptr;  
    return p;
}


void printTree(Node *p, int level)
{
    if(p == nullptr && level == 0) cout << "Пусто!" << endl;
    if(p)
    {
        printTree(p->right,level+1);
        for(int i = 0; i< level; i++) cout << "   ";
        cout << p->data << endl;
        printTree(p->left, level+1);
    }
}

void printTree_2(Node *p, int level)
{
    if(p == nullptr && level == 0) cout << "Пусто!" << endl;
    if(p)
    {
        printTree_2(p->right,level+1);
        for(int i = 0; i< level; i++) cout << "   ";
        cout << p->data << "(" << p->balance_factor << ")" << endl;
        printTree_2(p->left, level+1);
    }
}

//ПЕРВАЯ ЧАСТЬ
//Задача 1 "Восстановление бинарного дерева из массива"
Node* buildTree(int *arr, int n, int i)
{
   if(i >= n) return nullptr;
   
   Node* root = TreeNode(arr[i]);
   root->left = buildTree(arr, n, 2 * i + 1);
   root->right = buildTree(arr, n, 2 * i + 2);
   return root;
}

//Задача 2 "Симметричное дерево"
int deptSearch(Node *root, int *res, int i)
{
   if(root == nullptr) return i;
   if(root->left != nullptr)
      i = deptSearch(root->left, res, i);
   res[i] = root->data;
   i++;
   if(root->right != nullptr)
      i = deptSearch(root->right, res, i);
   return i;
}

int isSymmetric(Node *root, int n)
{
   if(root == nullptr) return true;
   if(n > 1000)
   {
      cout << "Sorry too much!" << endl;
      return -1;
   }
   int data[1000];
   deptSearch(root, data, 0);
   /*for(int i = 0; i < n; i++)
   {
      cout << data[i] << " ";
   }*/
   int j = n - 1;
   for(int i = 0; i < n/2; i++)
   {
      if(data[i] != data[j])
      {
         return 0;
      }
      j--;
   }
   return 1;
}


//Задача 3 "Поиск минимальной глубины бинарного дерева"
int minDepth(Node *root)
{
   if(root == nullptr) return 0;
   
   if(root->left == nullptr && root->right == nullptr) return 1;
   
   if(root->left != nullptr && root->right != nullptr) return 1 + min(minDepth(root->left), minDepth(root->right));
   
   if(root->left != nullptr) return 1 + minDepth(root->left);
   
   if(root->right != nullptr) return 1 + minDepth(root->right);
   
   return -1;
}

//Задача 4 "Поиск максимального произведения" (по факту ищем самый левых и самый праввый элемент)
int maxMinMultiplication(Node *tree)
{
   Node *h;
   h = tree;
   if(tree == nullptr) return -1;
   
   if(tree->left == nullptr && tree->right == nullptr) return tree->data * tree->data;
   
   while(tree->left != nullptr) 
   {
      tree = tree->left;
   }
   
   while(h->right != nullptr) 
   {
      h = h->right;
   }
   
   return tree->data * h->data;
}

//Задача 5 "Являются ли два дерева одинаковыми"
bool isSameTree(Node *a, Node *b) 
{
   if(a == nullptr && b == nullptr) return true;

   if(a == nullptr || b == nullptr) return false;

   if(a->data != b->data) return false;
   
   return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}

//ВТОРАЯ ЧАСТЬ
//Задача 1 "Проверка корректности кучи"
bool isMaxHeap(int *arr, int n)
{
   int left, right;
   for(int i = 0; i <= (n - 2) / 2; i++)
   {
      left = 2 * i + 1;
      right = 2 * i + 2;
      if(left < n && arr[i] < arr[left]) return false;
      
      if(right < n && arr[i] < arr[right]) return false;
   }
   return true;
}

//Задача 2 "Полное бинарное дерево"
bool isCompleteTree(Node *root)
{
   if(root->left == nullptr && root->right == nullptr) return true;
   
   if(root->left == nullptr || root->right == nullptr) return false;
   
   return isCompleteTree(root->left) && isCompleteTree(root->right);
}

//Задача 3 "Объединение K отсортированных массивов"
vector<int> mergeKSortedArrays(vector<vector<int>> &sortedArrays)
{
   int k = sortedArrays.size();
   vector<int> mergedArray;
   
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> minHeap; //priority_queue
   //Инициализируем кучу с первым элементом каждого массива
   for(int i = 0; i < k; i++)
   { 
      if (!sortedArrays[i].empty())
      {
          minHeap.push({sortedArrays[i][0], {i, 0}}); 
      }
   }
   
   while(!minHeap.empty())
   {
        //Извлекаем наименьший элемент из кучи
        auto top = minHeap.top();
        minHeap.pop();
        int val = top.first;
        int i = top.second.first;
        int j = top.second.second;
        //Добавляем его в итоговый массив
        mergedArray.push_back(val);
        //Проверяем, есть ли следующий элемент в том же массиве
        if (j+1 < sortedArrays[i].size())
        {
            minHeap.push({sortedArrays[i][j+1], {i, j+1}});
        }
    }
    return mergedArray;
}

//Задача 4 "К-ый наименьший/наибольший элемент в BST"
//counter надо по ссылке передавать!
Node *inorderMin(Node *node, int k, int &counter) 
{
   if(node == nullptr) return nullptr;
   
   
   Node *leftResult = inorderMin(node->left, k, counter);
   
   if(leftResult != nullptr) return leftResult;
   
   counter++;
   //cout << counter << " " << node->data << endl;

   if(counter == k)
   {
      return node;
   }
   
   return inorderMin(node->right, k, counter);
}

//Задача 5 "Balance factor"
int calculateHeightsAndBalance(Node *node)
{
   if(node == nullptr) return 0;
   int leftHeight = calculateHeightsAndBalance(node->left);
   int rightHeight = calculateHeightsAndBalance(node->right);
   node->balance_factor = leftHeight - rightHeight;
   return 1 + max(leftHeight, rightHeight);
}

//Задача 6 "Преобразование в зеркальное дерево"
void mirrorTree(Node *node)
{
   if (node == nullptr) return;
   Node *help;
   help = node->left;
   node->left = node->right;
   node->right = help;
   mirrorTree(node->left);
   mirrorTree(node->right);
}

int main()
{
   int arr[100];
   int n = 10, marker, counter = 0;
   Node *tree, *pree;
   cout << "ПЕРВАЯ ЧАСТЬ" << endl;
   cout << "Задача 1 'Восстановление бинарного дерева из массива'" << endl;
   cout << "Для массива: ";
   for(int i = 0; i < n; i++)
   {
      arr[i] = i;
      cout << arr[i] << " ";
   }
   cout << endl;
   
   cout << "Вывод дерева (бочком), сверху правая сторона, снизу левая:" << endl;
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   
   n = 7;
   arr[0] = 8;
   arr[1] = 9;
   arr[2] = 11;
   arr[3] = 7;
   arr[4] = 16;
   arr[5] = 3;
   arr[6] = 1;
   cout << "Пример из семинара" << endl;
   cout << "Для массива: ";
   for(int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 2 'Симметричное дерево'" << endl;
   marker = isSymmetric(tree, n);
   printTree(tree, 0);
   if(marker == 0)
   {
      cout << "Дерево не является симметричным!" << endl;
   }
   if(marker == 1)
   {
      cout << "Дерево является симметричным!" << endl;
   }
   arr[0] = 1;
   arr[1] = 2;
   arr[2] = 2;
   arr[3] = 4;
   arr[4] = 5;
   arr[5] = 5;
   arr[6] = 4;
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   marker = isSymmetric(tree, n);
   if(marker == 0)
   {
      cout << "Дерево не является симметричным!" << endl;
   }
   if(marker == 1)
   {
      cout << "Дерево является симметричным!" << endl;
   }
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 3 'Поиск минимальной глубины бинарного дерева'" << endl;
   printTree(tree, 0);
   cout << "Минимальная глубина = " << minDepth(tree) << endl;
   n = 29;
   for(int i = 0; i < n; i++)
   {
      arr[i] = i;
   }
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   cout << "Минимальная глубина = " << minDepth(tree) << endl;
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 4 'Поиск минимальной глубины бинарного дерева'" << endl;
   n = 6;
   arr[0] = 5;
   arr[1] = 3;
   arr[2] = 8;
   arr[3] = 2;
   arr[4] = 4;
   arr[5] = 7;
   
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   cout << "Произведение минимума и максимума  = " << maxMinMultiplication(tree) << endl;
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 5 'Являются ли два дерева одинаковыми'" << endl;
   printTree(tree, 0);
   n = 10;
   for(int i = 0; i < n; i++)
   {
      arr[i] = i;
   }
   pree = buildTree(arr, n, 0);
   printTree(pree, 0);
   if(isSameTree(tree, pree) == 0)
   {
      cout << "Деревья разные!" << endl;
   }
   else
   {
      cout << "Деревья одинаковые!" << endl;
   }
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   printTree(tree, 0);
   if(isSameTree(tree, pree) == 0)
   {
      cout << "Деревья разные!" << endl;
   }
   else
   {
      cout << "Деревья одинаковые!" << endl;
   }
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "ВТОРАЯ ЧАСТЬ" << endl;
   cout << "Задача 1 'Проверка корректности кучи'" << endl;
   n = 10;
   arr[0] = 21;
   arr[1] = 19;
   arr[2] = 18;
   arr[3] = 11;
   arr[4] = 12;
   arr[5] = 15;
   arr[6] = 16;
   arr[7] = 9;
   arr[8] = 8;
   arr[9] = 10;
   for(int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   if(isMaxHeap(arr, n) == 0)
   {
      cout << "Это не куча!" << endl;
   }
   else
   {
      cout << "Это куча!" << endl;
   }
   
   for(int i = 0; i < n; i++)
   {
      arr[i] = i;
      cout << arr[i] << " ";
   }
   cout << endl;
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   if(isMaxHeap(arr, n) == 0)
   {
      cout << "Это не куча!" << endl;
   }
   else
   {
      cout << "Это куча!" << endl;
   }
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 2 'Полное бинарное дерево'" << endl;
   printTree(tree, 0);
   if(isCompleteTree(tree) == 0)
   {
      cout << "Не является полным бинарным деревом!" << endl;
   }
   else
   {
      cout << "Является полным бинарным деревом!" << endl;
   }
   n = 11;
   arr[10] = 10;
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   if(isCompleteTree(tree) == 0)
   {
      cout << "Не является полным бинарным деревом!" << endl;
   }
   else
   {
      cout << "Является полным бинарным деревом!" << endl;
   }
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 3 'Объединение K отсортированных массивов'" << endl;
   vector<vector<int>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   cout << "Было: {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}" << endl;
   vector<int> result = mergeKSortedArrays(data);
   cout << "Стало: ";
   for(int x:result)
   { 
      cout << x << " ";
   }
   cout << endl;
   
   data = {{1, 2, 3}, {1, 2, 4}, {3, 4, 5}};
   cout << "Было: {{{1, 2, 3}, {1, 2, 4}, {3, 4, 5}}" << endl;
   result = mergeKSortedArrays(data);
   cout << "Стало: ";
   for(int x:result)
   { 
      cout << x << " ";
   }
   cout << endl;
   cout << "/////////////////////////////////////////////////////////" << endl;
   cout << "Задача 4 'К-ый наименьший/наибольший элемент в BST'" << endl;
   n = 7;
   arr[0] = 5;
   arr[1] = 3;
   arr[2] = 8;
   arr[3] = 2;
   arr[4] = 4;
   arr[5] = 7;
   arr[6] = 9;
   
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   cout << "Ищем 5-ый наименьший" << endl;
   tree = inorderMin(tree, 5, counter);
   if(tree == nullptr)
   {
      cout << "Не нашли!" << endl;
   }
   else
   {
      cout << "Нашли! Значаение = " << tree->data << endl;
   }
   
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   counter = 0;
   cout << "Ищем 6-ый наименьший" << endl;
   tree = inorderMin(tree, 6, counter);
   if(tree == nullptr)
   {
      cout << "Не нашли!" << endl;
   }
   else
   {
      cout << "Нашли! Значаение = " << tree->data << endl;
   }
   
   tree = buildTree(arr, n, 0);
   printTree(tree, 0);
   counter = 0;
   cout << "Ищем 8-ый наименьший" << endl;
   tree = inorderMin(tree, 8, counter);
   if(tree == nullptr)
   {
      cout << "Не нашли!" << endl;
   }
   else
   {
      cout << "Нашли! Значаение = " << tree->data << endl;
   }
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 5 'Balance factor'" << endl;
   n = 10;
   for(int i = 0; i < n; i++)
   {
      arr[i] = i;
   }
   
   tree = buildTree(arr, n, 0);
   calculateHeightsAndBalance(tree);
   printTree_2(tree, 0);
   
   n = 8;
   for(int i = 0; i < n; i++)
   {
      arr[i] = i;
   }
   
   tree = buildTree(arr, n, 0);
   calculateHeightsAndBalance(tree);
   printTree_2(tree, 0);
   cout << "/////////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 6 'Преобразование в зеркальное дерево'" << endl;
   n = 15;
   for(int i = 0; i < n; i++)
   {
      arr[i] = i;
   }
   tree = buildTree(arr, n, 0);
   cout << "Было:" << endl;
   printTree(tree, 0);
   mirrorTree(tree);
   cout << "Стало:" << endl;
   printTree(tree, 0);
   
   return 0;
}
