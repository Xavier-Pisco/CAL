/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <algorithm>
#include "MutablePriorityQueue.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
	T info;						// content of the vertex
	vector<Edge<T> > adj;		// outgoing edges
	
	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool visited = false;		// auxiliary field
	bool processing = false;	// auxiliary field

	void addEdge(Vertex<T> *dest, double w);

public:
	Vertex(T in);
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;

	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set

	vector<vector<int>> distance;
	vector<vector<Vertex<T>*>> predecessor;

public:
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	// Fp05 - single source
	void unweightedShortestPath(const T &s);    //TODO...
	void dijkstraShortestPath(const T &s);      //TODO...
	void bellmanFordShortestPath(const T &s);   //TODO...
	vector<T> getPathTo(const T &dest) const;   //TODO...

	// Fp05 - all pairs
	void floydWarshallShortestPath();   //TODO...
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;   //TODO...

};

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
	if ( findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2,w);
	return true;
}


/**************** Single Source Shortest Path algorithms ************/

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
	for (Vertex<T> * v: vertexSet){
	    v->dist = INT_MAX;
	    v->path = NULL;
	}
	queue<Vertex<T>*> q;
	Vertex<T> * vorig = findVertex(orig);
	vorig->dist = 0;
	q.push(vorig);
	while(!q.empty()){
        Vertex<T> * v = q.front();
        q.pop();
	    for (Edge<T> e: v->adj){
	        if (e.dest->dist == INT_MAX){
	            q.push(e.dest);
	            e.dest->dist = v->dist + 1;
	            e.dest->path = v;
	        }
	    }
	}
}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    for (Vertex<T> * v: vertexSet){
        v->dist = INT_MAX;
        v->path = NULL;
        v->visited = false;
    }
    MutablePriorityQueue<Vertex<T>> q;
    Vertex<T> * vorig = findVertex(origin);
    vorig->dist = 0;
    vorig->visited = true;
    q.insert(vorig);
    while(!q.empty()){
        Vertex<T> * v = q.extractMin();
        for (Edge<T> e: v->adj){
            if (e.dest->dist > e.weight + v->dist){
                e.dest->dist = v->dist + e.weight;
                e.dest->path = v;
                if (e.dest->visited){
                    q.decreaseKey(e.dest);
                } else {
                    q.insert(e.dest);
                }
                e.dest->visited = true;
            }
        }
    }
}


template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
    for (Vertex<T> * v: vertexSet){
        v->dist = INT_MAX;
        v->path = NULL;
        v->visited = false;
    }
    Vertex<T> * vorig = findVertex(orig);
    vorig->dist = 0;
    vorig->visited = true;
    queue<Vertex<T> *> q;
    q.push(vorig);
    while(!q.empty()){
        Vertex<T>* v = q.front();
        q.pop();
        for (Edge<T> e: v->adj){
            if (e.dest->dist > v->dist + e.weight){
                q.push(e.dest);
                e.dest->dist = v->dist + e.weight;
                e.dest->path = v;
            }
        }
    }
}


template<class T>
vector<T> Graph<T>::getPathTo(const T &dest) const{
	vector<T> res;
	Vertex<T> * v = findVertex(dest);
	while(v != NULL){
	    res.push_back(v->info);
	    v = v->path;
	}
	reverse(res.begin(),res.end());
	return res;
}



/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() {
	distance.resize(getNumVertex());
	for (int i = 0; i < distance.size(); i++){
	    distance[i].resize(getNumVertex());
	    for (int j = 0; j < distance[i].size(); j++){
	        if (i == j) distance[i][j] = 0;
	        else distance[i][j] = INT_MAX;
	    }
	}
	predecessor.resize(getNumVertex());
	for (int i = 0; i < predecessor.size(); i++){
	    predecessor[i].resize(getNumVertex());
        for (int j = 0; j < predecessor[i].size(); j++) {
            if (i == j) predecessor[i][j] = vertexSet[i];
            else predecessor[i][j] = NULL;
        }
	}
}

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
	vector<T> res;

	return res;
}


#endif /* GRAPH_H_ */
