#include <iostream>
#include <queue>
#include <stack>

struct node {
    int value;
    node* next;
};

class adjacencyList {
    private:
        node* head;
    public:
        adjacencyList() { head = nullptr; }
        node* getHead() { return head; }
        void insertAtHead(int data);
        void print();
};

void adjacencyList::insertAtHead(int data) {
    node* newNode = new node();
    newNode->value = data;
    newNode->next = head;
    head = newNode;
}

void adjacencyList::print() {
    node* temp = head;
    while(temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
}

void bfs(int **graph, int source, int size) {
    // create queue and visited array
    std::queue<int> q;
    bool *visited = new bool[size];

    for(int i = 0; i < size; i++) {
        visited[i] = false;
    }

    // enqueue the source node
    q.push(source);
    int v;

    while(!q.empty()) {
        // pop the first node
        v = q.front();
        q.pop();

        // if the node hasn't been visited, print and mark it as visited
        if(!visited[v]) {
            std::cout << v << " ";
            visited[v] = true;

            // enqueue its neighbors
            for(int i = 0; i < size; i++) {
                if(graph[i][v] == 1) {
                    q.push(i);
                }
            }
        }
    }

    std::cout << std::endl;
    delete[] visited;
}

void buildAdjacencyMatrix() {
    // BUILDING AN ADJACENCY MATRIX
    // first declare a 2d (dynamic) array (or 2d vector)
    int size = 6;
    int** arr = new int*[size];
    for(int i = 0; i < size; i++) arr[i] = new int[size];

    // initalize everything to zeros
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
    }

    // set the value at the intersection of your two numbers as 1
    arr[1][0] = 1; // 1 is connected to 2
    arr[2][1] = 1; // 2 is connected to 3
    arr[3][2] = 1; // 3 is connected to 4
    arr[4][2] = 1; // 3 is connected to 5
    arr[4][3] = 1; // 4 is connected to 5
    arr[5][4] = 1; // 5 is connected to 6

    bfs(arr, 0, size);
}

void dfs(adjacencyList graph[], int source, int size) {
    // create stack and visited array
    std::stack<int> s;
    bool* visited = new bool[size];
    for(int i = 0; i < size; i++) {
        visited[i] = false;
    }

    // push the source node
    s.push(source);
    int val;
    while(!s.empty()) {
        // pop the top node
        val = s.top();
        s.pop();

        // if the node hasnt been visited, print and mark it as visited
        if(!visited[val]) {
            std::cout << val << " ";
            visited[val] = true;

            // push all of its neighbors
            node* v = graph[val].getHead();
            while(v != nullptr) {
                s.push(v->value);
                v = v->next;
            } 
        }
    }

    std::cout << std::endl;
    delete[] visited;
}

void buildAdjacencyList() {
    // BUILDING AN ADJACENCY LIST
    // create an array of linked lists/node pointers
    int size = 6;
    adjacencyList* list = new adjacencyList[size];

    // insert at head or tail of node that is connected to another node
    list[0].insertAtHead(1);
    list[1].insertAtHead(2);
    list[2].insertAtHead(3);
    list[2].insertAtHead(4);
    list[3].insertAtHead(4);
    list[4].insertAtHead(5);

    // // print your list
    // for(int i = 0; i < size; i++) {
    //     std::cout << i + 1 << " -> ";
    //     list[i].print();
    //     std::cout << std::endl;
    // }

    dfs(list, 0 , size);
}

int main() {
    buildAdjacencyMatrix();
    //buildAdjacencyList();

    return 0;
}