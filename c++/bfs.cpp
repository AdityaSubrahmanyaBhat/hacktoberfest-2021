#include<iostream>
using namespace std;

int V;

class Queue {
    int front = -1, rear = -1;
    int *queue = new int[V]; 
    public:
        void enqueue(int val) {
            queue[++rear] = val;
        }
        int dequeue() {
            return queue[++front];
        }
        bool isEmpty() {
            return (front >= rear);
        }
};

void BFS(int **graph, int src) {
    Queue q;
    int *visit = new int[V+1];
    int *order = new int[V];
    for(int i=1; i<=V; i++)
        visit[i] = 0;
            
    q.enqueue(src);
    visit[src] = 1;
    int i=0,j=0;
    while(!q.isEmpty()) {
        int u = q.dequeue();
        order[i++] = u;
        for(int v=1; v<=V; v++) {
            if(graph[u][v] == 1 && visit[v] == 0) {
                visit[v] = 1;
                q.enqueue(v);
            }
        }
    }
    cout<<endl;
    for(int i=1; i<=V; i++) {
        if(visit[i] == 1)
            cout<<i<<" is reachable"<<endl;
        else
            cout<<i<<" is not reachable"<<endl;
    }
    cout<<endl<<"BFS: ";
    while(1) {
        if(order[j] == 0) break;
        cout<<order[j++]<<" ";
    }
    cout<<endl;
}

int main() {
    int src;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    int **graph = new int*[V+1];
    for(int i=1; i<=V; i++)
        graph[i] = new int[V+1];

    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=1; i<=V; i++) {
        for(int j=1; j<=V; j++)
            cin>>graph[i][j];
    }
    cout<<endl<<"Enter the source vertex"<<endl;
    cin>>src;
    BFS(graph,src);
    cout<<endl;
    return 0;
}
