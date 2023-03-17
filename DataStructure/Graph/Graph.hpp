#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

template <typename T>
class Vertex;

template <typename T>
class Edge
{
public:
    T info;
    Vertex<T> *dest;
    Edge(T info, Vertex<T> *dest)
    {
        this->info = info;
        this->dest = dest;
    }
};

template <typename T>
class Vertex
{
public:
    string name;
    vector<Edge<T> *> edges;
    Vertex(string name)
    {
        this->name = name;
    }
};

template <typename T>
class Graph
{
public:
    vector<Vertex<T> *> vertices;
    map<string, Vertex<T> *> vertexMap;
    void addVertex(string name)
    {
        Vertex<T> *v = new Vertex<T>(name);
        vertices.push_back(v);
        vertexMap[name] = v;
    }
    void addEdge(string source, string dest, T info)
    {
        Vertex<T> *s = vertexMap[source];
        Vertex<T> *d = vertexMap[dest];
        Edge<T> *e = new Edge<T>(info, d);
        s->edges.push_back(e);
    }
};
