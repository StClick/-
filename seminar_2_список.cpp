#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct Node
{
    int value;
    char c;
    Node *next;
};

class LinkedList
{
    public:
    Node *head;
    Node *tail;
    LinkedList();
    void addNewHead(int n);
    void addNewHead_char(char n);
    void addNewTail(int n);
    void addNewTail_char(char n);
    void printList();
    void printList_char();
    bool hasCycle();
    void reverseList();
    Node *middleList();
    void eraseElement(int elem);
    void listUnite(Node *p);
    bool isSubsequence(Node *p);
    bool isPalindrome();
};

LinkedList :: LinkedList()
{
    head = tail = NULL;
}

//Вставка в начало списка

void LinkedList :: addNewHead(int n)
{
    Node *p  = new Node;
    p->value = n;
    if(head == NULL)
    {
        p->next = NULL;
        tail = p;
    }
    else
    {
        p->next = head;
    }
    head = p;
}

void LinkedList :: addNewHead_char(char n)
{
    Node *p  = new Node;
    p->c = n;
    if(head == NULL)
    {
        p->next = NULL;
        tail = p;
    }
    else
    {
        p->next = head;
    }
    head = p;
}

//Вставка в конец списка 
void LinkedList :: addNewTail(int n)
{
    Node *p  = new Node;
    p->value = n;
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        tail->next = p;
    }
    tail = p;
    p->next = NULL;
}

void LinkedList :: addNewTail_char(char n)
{
    Node *p  = new Node;
    p->c = n;
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        tail->next = p;
    }
    tail = p;
    p->next = NULL;
}


//Вывод списка на экран (не для циклических списков!) 
void LinkedList :: printList()
{
    if(head!= NULL)
    {
        Node *p = head;
        while(p)
        {
            if(p->next != NULL)
            {
                cout << p->value << "->";
            }
            else
            {
                cout << p->value;
            }
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Список пуст" << endl;
    }
}

void LinkedList :: printList_char()
{
    if(head!= NULL)
    {
        Node *p = head;
        while(p)
        {
            if(p->next != NULL)
            {
                cout << p->c << "->";
            }
            else
            {
                cout << p->c;
            }
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Список пуст" << endl;
    }
}

//Задача 1 "Проверка списка на цикличность" 
bool LinkedList :: hasCycle()
{
    Node *slow, *fast;
    if(head == NULL || head->next == NULL)
    {
        cout << "Цикла нет" << endl;
        return false;
    }
    slow = head;
    fast = head->next;

    while(slow != fast)
    {
        if(fast == NULL || fast->next == NULL)
        {
            cout << "Цикла нет" << endl;
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Цикл есть!" << endl;
    return true;
}

//Задача 2 "Развернуть односвязный список" 
void LinkedList :: reverseList()
{
    Node *prev, *current, *next;
    prev = NULL;
    current = head;
    tail = head;

    while(current != NULL)
    {
        //cout << current->value << " ";
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

//Задача 3 "Найти середину списка" 
Node* LinkedList :: middleList()
{
    Node *slow, *fast;
    slow = head;
    fast = head;
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

//Задача 4 "Удалить элемент, совпадающий по значению с искомым"
void LinkedList :: eraseElement(int elem)
{
    Node *dummy  = new Node;
    Node *cur, *prev;
    dummy->next = head;
    prev = dummy;
    cur = head;
    while(cur != NULL)
    {
        if(cur->value == elem) 
        {
            prev->next = cur->next;
        } 
        else
        {
            prev = cur;
        }
        cur = cur->next;
    }
    head = dummy->next;
}

//Задача 5 "Является ли одна строка исходной для другой строки?"
bool LinkedList :: isSubsequence(Node *p)
{
    queue<char> q;
    Node *d;
    d = head;
    while(d != NULL)
    {
       q.push(d->c);
       d = d->next;
    }
    
    while(p != NULL)
    {
       if(q.front() == p->c) q.pop();
       p = p->next;
    }
    
    return q.size() == 0;
}

//Задача 6 "Является ли слово палиндромом?"
bool LinkedList :: isPalindrome()
{
    stack<char> q;
    Node *d;
    d = head;
    while(d != NULL)
    {
       q.push(d->c);
       d = d->next;
    }
    d = head;
    while(d != NULL)
    {
       if(q.top() != d->c) return false;
       q.pop();
       d = d->next;
    }
    
    return true;
}

//Задача 7 "Слияние двух отсортированных списков"
void LinkedList :: listUnite(Node *p)
{
    Node *dummy  = new Node;
    Node *q, *current;
    q = head;
    current = dummy;
    while(q != NULL && p != NULL)
    {
       if(q->value <= p->value)
       {
          current->next = q;
          q = q->next;
       } 
       else
       {
          current->next = p;
          p = p->next;
       }
       current = current->next;
    }
    if(q != NULL)
    {
       current->next = q;
    }
    if(p != NULL)
    {
       current->next = p;
       while(p != NULL) //для порядка
       {
          tail = p;
          p = p->next;
       }
    }
    head = dummy->next;
}

int main()
{
    LinkedList ob, ob2, ob3, a, b, c, palindrom;
    ob.addNewHead(1);
    for(int i = 2; i <= 10; i++)
    {
        ob.addNewTail(i);
    }
    
    cout << "Задача 1 'Есть ли циклы в списке?'" << endl;
    cout << "Для списка:";
    ob.printList();
    ob.hasCycle();
    cout << "Для того же списка с хвостом, указывающим на голову: ";
    ob.tail->next = ob.head;
    ob.hasCycle();
    ob.tail->next = NULL;
    cout << "/////////////////////////////////////////////////////////" << endl;
    
    cout << "Задача 2 'Развернуть список' " << endl << "Было: ";
    ob.printList();
    ob.reverseList();
    cout << "Стало: ";
    ob.printList();
    cout << "/////////////////////////////////////////////////////////" << endl;
    
    cout << "Задача 3 'Найти середину списка' " << endl;
    cout << "Средний элемент: " << ob.middleList()->value << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    
    cout << "Задача 4 'Удаление элемента из связного списка' " << endl;
    cout << "Удалим элемент со значением 5, тогда получим: ";
    ob.eraseElement(5);
    ob.printList();
    cout << "Вдобавок удалим элемент со значением 10, тогда получим: ";
    ob.eraseElement(10);
    ob.printList();
    cout << "Вдобавок удалим элемент со значением 1, тогда получим: ";
    ob.eraseElement(1);
    ob.printList();
    ob.reverseList();
    ob2.addNewHead(1);
    for(int i = 3; i <= 30; i=i+3)
    {
        ob2.addNewTail(i);
    }
    cout << "/////////////////////////////////////////////////////////" << endl;
    
    cout << "Задача 5 'Является ли одна строка исходной для другой строки?' " << endl;
    a.addNewHead_char('a');
    a.addNewTail_char('b');
    a.addNewTail_char('c');
    a.addNewTail_char('d');
    a.addNewTail_char('e');
    a.addNewTail_char('f');
    
    b.addNewHead_char('c');
    b.addNewTail_char('d');
    b.addNewTail_char('e');
    
    c.addNewHead_char('b');
    c.addNewTail_char('b');
    c.addNewTail_char('c');
    
    cout << "Для строк вида:" << endl;
    b.printList_char();
    a.printList_char();
    if(b.isSubsequence(a.head))
    {
       cout << "Первая является порождающей второй" << endl;
    }
    else
    {
       cout << "Первая не является порождающей второй" << endl;
    }
    cout << "Для строк вида:" << endl;
    c.printList_char();
    a.printList_char();
    if(c.isSubsequence(a.head))
    {
       cout << "Первая является порождающей второй" << endl;
    }
    else
    {
       cout << "Первая не является порождающей второй" << endl;
    }
    cout << "/////////////////////////////////////////////////////////" << endl;
    
    cout << "Задача 6 'Является ли слово палиндромом?' " << endl;
    palindrom.addNewHead_char('a');
    palindrom.addNewTail_char('b');
    palindrom.addNewTail_char('c');
    palindrom.addNewTail_char('b');
    palindrom.addNewTail_char('a');
    
    cout << "Строка:" << endl;
    palindrom.printList_char();
    if(palindrom.isPalindrome())
    {
       cout << "Палиндром" << endl;
    }
    else
    {
       cout << "Не палиндром" << endl;
    }
    cout << "Строка:" << endl;
    a.printList_char();
    if(a.isPalindrome())
    {
       cout << "Палиндром" << endl;
    }
    else
    {
       cout << "Не палиндром" << endl;
    }
    cout << "/////////////////////////////////////////////////////////" << endl;
    
    cout << "Задача 7 'Слияние двух отсортированных списков' " << endl;
    cout << "Объединяем список1: ";
    ob.printList();
    cout << "и список2: ";
    ob2.printList();
    ob.listUnite(ob2.head);
    cout << "Ответ: ";
    ob.printList();
    
    return 0;
}
