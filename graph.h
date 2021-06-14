#include <iostream> 
#include <cstdlib>
#include <vector>


using namespace std;
/*

Creation of the class GraphN for the manipulation

*/
class GraphN {
    //Declaration of private variable
	int n_v;
	int** adj;

//Delcaration of methods
public:
	GraphN(int n_v);
	void InsertEdge(int start, int e);
	void Bfs(int start);
    void Dfs(int start, vector<bool>& visited);
};

/*
* Constructor of the Object GraphN
* Parameter needed is an integer
*/
GraphN::GraphN(int n_v)
{
	this->n_v = n_v;
	adj = new int*[n_v];
	for (int i = 0; i < n_v; i++) {
		adj[i] = new int[n_v];
		for (int j = 0; j < n_v; j++) {
			adj[i][j] = 0;
		}
	}
}

/*
* Method InsertEdge to insert edge ina the graph
*/
void GraphN::InsertEdge(int start, int e)
{
	adj[start][e] = 1;
	adj[e][start] = 1;
}
/*
* Method Bfs : To traverse the graph through Breath First Search
*/
void GraphN::Bfs(int start)
{
	vector<bool> visited(n_v, false);
	vector<int> q;
	q.push_back(start);
		visited[start] = true;
	int vis;
	while (!q.empty()) {
		vis = q[0];
		cout << "(" <<vis << ") ";
		q.erase(q.begin());
		for (int i = 0; i < n_v; i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {
				q.push_back(i);
				visited[i] = true;
			}
		}
	}
}

/*
* Method Dfs : To traverse the graph through Deep First Search
*/
void GraphN::Dfs(int start, vector<bool>& visited)
{
    cout <<"(" << start << ") ";
	visited[start] = true;
		for (int i = 0; i < n_v; i++) {
			if (adj[start][i] == 1 && (!visited[i])) {
            Dfs(i, visited); 
            } 
		}
}

/*
* Function Graph called from the main program
* 
*/
int Graph()
{
    int v=8;
    GraphN G(v);
    G.InsertEdge(0, 1);
    G.InsertEdge(0, 2);
    G.InsertEdge(0, 3);
    G.InsertEdge(0, 4);
    G.InsertEdge(2, 5);
    G.InsertEdge(2, 6);
    G.InsertEdge(3, 7);
    vector<bool> visited(v, false);
    
    
    int choice;
    writeTitle("Welcome to Graph Section secion");
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1- Depht First Search " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 2- Breadth First Search " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 3- Exit the program " <<endl;

    do
    {
        cout << "\n\n\t Choose to continue... " <<endl;
        cin >>choice;

    } while ((choice < 1 ) || (choice > 3));
    
    switch (choice)
    {
        case 1:
            cout << "\tDepht First Search: ";
            G.Dfs(0, visited);
            break;
        case 2:
            cout << "\tBreadth First Search: ";
            G.Bfs(0);
            break;
        case 3:
            ;
            break;
       default:
           break;
       }
    return 0;
}
