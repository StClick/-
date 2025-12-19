#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> find_connected_components(vector<vector<int>>& graph);
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int s, vector<int>& connected_components);

bool dfs_2(vector<vector<int>>& graph, int node, int parent, vector<bool>& vis);
bool has_cycle(vector<vector<int>>& graph);

bool isTree(vector<vector<int>>& graph);

vector<int> dijkstra(vector<vector<pair<int,int>>>& dij, int src);

bool isBipartite(vector<vector<int>> &graph);

//Задача 1 'Поиск компонент связности'
vector<vector<int>> find_connected_components(vector<vector<int>>& graph)
{
   int V = graph.size();
   vector<bool> visited(V, false);
   
   vector<vector<int>> connected_components;

   for(int i = 0; i < V; i++) 
   {
      if(!visited[i])
      {
         vector<int> component;
         dfs(graph, visited, i, component);
         connected_components.push_back(component);
      }
   }

   return connected_components;
}

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int s, vector<int>& connected_components) {
   visited[s] = true;
   
   connected_components.push_back(s);
    
   for(int i : graph[s])
   {
      if(!visited[i])
      {
         dfs(graph, visited, i, connected_components);
      }
   }
}

void add_edge(vector<vector<int>>& graph, int u, int v)
{
   graph[u].push_back(v);
   graph[v].push_back(u);
}

//Задача 2 'Поиск цикла в графе'
bool dfs_2(vector<vector<int>>& graph, int vertex, int parent, vector<bool>& visited)
{
   visited[vertex] = true;
   
   for (auto neighbor : graph[vertex])
   {
      if (!visited[neighbor]) 
      {
          if (dfs_2(graph, neighbor, vertex, visited)) return true;
      }
      else if(neighbor != parent)
      {
          return true;
      }
   }
   return false;   
}

bool has_cycle(vector<vector<int>>& graph)
{
   int V = graph.size();
   vector<bool> visited(V, false); 
   bool cycle = dfs_2(graph, 0, -1, visited);
        
   return cycle;
}

//Задача 3 'Является ли граф деревом?'
bool isTree(vector<vector<int>>& graph)
{
    vector<vector<int>> connected_components = find_connected_components(graph);
   
    //cout << connected_components.size() << endl;
    if(connected_components.size() != 1) return false;
    if(has_cycle(graph)) return false;

    return true;
}

//Задача 4 'Алгоритм Дейкстры'
vector<int> dijkstra(vector<vector<pair<int,int>>>& dij, int src)
{
   int V = dij.size();

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority_queue;

   vector<int> distances(V, INT_MAX);

   distances[src] = 0;
   priority_queue.emplace(0, src);

   while (!priority_queue.empty())
   {
      auto gr = priority_queue.top();
      priority_queue.pop();

      int current_distance = gr.first;  
      int neighbor = gr.second; 

      if (current_distance > distances[neighbor]) continue;

      for (auto &p : dij[neighbor])
      {
         int v = p.first; 
         int weight = p.second; 

         if (distances[neighbor] + weight < distances[v])
         {
            distances[v] = distances[neighbor] + weight;   
            priority_queue.emplace(distances[v], v);
         }
      }
   }

   return distances;
}

//Задача 5 'Двудольный граф'
bool isBipartite(vector<vector<int>> &graph)
{
   int V = graph.size();
   vector<int> color(V, -1);
   queue<int> q;
   for(int i = 0; i < V; i++)
   {
       if(color[i] == -1)
       {
          color[i] = 0;
          q.push(i);
          while(!q.empty())
          {
             int node = q.front();
             q.pop();
             for(auto &v : graph[node])
             {
                 if(color[v] == -1)
                 {
                    color[v] = 1 - color[node];
                    q.push(v);
                 }
                 else if(color[v] == color[node])
                 {
                    return false;
                 }
             }
          }
       }
   }
   return true;
}

int main()
{
   int V = 11, src = 0;

   cout << "Задача 1 'Поиск компонент связности'" << endl;
   vector<vector<int>> graph(V);
   cout << "Для графа: 0>1->2->3->0 4 5->7->8->5 6 9->10" << endl << "Компоненты связности:" << endl;
   add_edge(graph, 0, 1);
   add_edge(graph, 1, 2);
   add_edge(graph, 2, 3);
   add_edge(graph, 0, 3);
   add_edge(graph, 5, 7);
   add_edge(graph, 7, 8);
   add_edge(graph, 5, 8);
   add_edge(graph, 9, 10);
   
   vector<vector<int>> connected_components = find_connected_components(graph);
   

   for (auto& component : connected_components)
   {
       for (int vertex : component)
       {
           cout << vertex << " ";
       }
       cout << endl;
   }
   cout << "/////////////////////////////////////////////////////" << endl;
   cout << "Задача 2 'Поиск цикла в графе'" << endl;
   cout << "Для графа: 0>1->2->3->0 4 5->7->8->5 6 9->10" << endl;
   
   if(has_cycle(graph))
   {
      cout << "Есть цикл!" << endl;
   }
   else 
   {
      cout << "Цикла нет!" << endl;
   }
   
   vector<vector<int>> g(6);
   cout << "Для графа: 0>1->2 1->3 4->5" << endl;
   add_edge(g, 0, 1);
   add_edge(g, 1, 2);
   add_edge(g, 1, 3);
   add_edge(g, 4, 5);
   
   if(has_cycle(g))
   {
      cout << "Есть цикл!" << endl;
   }
   else 
   {
      cout << "Цикла нет!" << endl;
   }
   cout << "/////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 3 'Является ли дерево графом?'" << endl;
   cout << "Граф: 0>1->2 1->3 4->5" << endl;
   if(isTree(g))
   {
      cout << "Дерево!" << endl;
   }
   else 
   {
      cout << "Не дерево!" << endl;
   }
   
   cout << "Граф: 0>1->2->3->0 4 5->7->8->5 6 9->10" << endl;
   if(isTree(g))
   {
      cout << "Дерево!" << endl;
   }
   else 
   {
      cout << "Не дерево!" << endl;
   }
   
   vector<vector<int>> gr(6);
   cout << "Граф: 0>1->2 1->3 0->4->5" << endl;
   add_edge(gr, 0, 1);
   add_edge(gr, 1, 2);
   add_edge(gr, 1, 3);
   add_edge(gr, 0, 4);
   add_edge(gr, 4, 5);
   if(isTree(gr))
   {
      cout << "Дерево!" << endl;
   }
   else 
   {
      cout << "Не дерево!" << endl;
   }
   cout << "/////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 4 'Алгоритм Дейкстры'" << endl;
   vector<vector<pair<int,int>>> dij(4);
   dij[0] = {{1,1}, {2,5}};
   dij[1] = {{0,1}, {3,3}, {2,2}};
   dij[2] = {{0,5}, {3,1}, {1,2}};
   dij[3] = {{1,3}, {2,1}};

   vector<int> s = dijkstra(dij, src);
   cout << "Для графа =" << endl << "{'A': {'B': 1, 'C': 5}," << endl <<"'B': {'A': 1, 'C': 2, 'D': 3}," << endl << "'C': {'A': 5, 'B': 2, 'D': 1}," <<endl << "'D': {'B': 3, 'C': 1}}" << endl;
   cout << "Минимальное расстояние из А = { ";
   for(int dist : s)
   {
      cout << dist << " ";
   }
   cout << "}" << endl;
   
   cout << "/////////////////////////////////////////////////////" << endl;
   
   cout << "Задача 5 'Двудольный граф'" << endl;
   cout << "Граф: 0>1->2->3->0 4 5->7->8->5 6 9->10" << endl;
   if(isBipartite(graph))
      cout << "Двудольный!" << endl;
   else
      cout << "Не является двудольным!" << endl;
   cout << "Граф: 0>1->2 1->3 0->4->5" << endl;
   if(isBipartite(gr))
      cout << "Двудольный!" << endl;
   else
      cout << "Не является двудольным!" << endl;
   return 0;
}
