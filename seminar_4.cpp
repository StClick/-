#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct Node
{
   int data;
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

int main()
{
   int arr[100];
   int n = 10, marker;
   Node *tree, *pree;
   
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
   return 0;
}
