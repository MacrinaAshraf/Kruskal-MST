#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > myType;
int nodes, edges;
myType graph[100];
int parent[100];
int size[100];

int kruskalMST();
void initialize();
int find(int);
bool checkElement(int, int);
void Union(int, int);

int main() {
	int source, destination, cost;
	int minimumCost = 0;

	initialize();
	
	cin >> nodes >> edges;
	cout << "\n";
	
	for(int i = 0; i < edges; i++){
		cin >> source >> destination >> cost;
		graph[i] = make_pair(cost, make_pair(source, destination));
		cout << "\n";
	}
	sort(graph, graph + edges);
	
	minimumCost = kruskalMST();
	cout << minimumCost << endl;
}

void initialize(){
    for(int i = 0; i < 100; i++)
    {
		parent[ i ] = i ;
		size[ i ] = 1;
	}
}

int find(int i){
	while(parent[i] != i){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
		
	return i;
}

bool checkElement(int a, int b){
	if(find(a) == find(b))
		return true;
	else
		return false;
}

void Union(int a, int b){
	int root_a = find(a);
	int root_b = find(b);
	if(root_a == root_b)
		return;
	if(size[root_a] < size[root_b]){
		parent[root_a] = parent[root_b];
		size[root_b] += size[root_a];	
	}
	else {
		parent[root_b] = parent[root_a];
		size[root_a] += size[root_b];
	}	
}

int kruskalMST(){
	int source, destination, cost, minimumCost;
	
	for(int i = 0; i < edges; i++){
		source = graph[i].second.first;
		destination = graph[i].second.second;
		cost = graph[i].first;
		
		if(!checkElement(source, destination)){
			minimumCost += cost;
			Union(source, destination);
		}
	}
	return minimumCost;
}
