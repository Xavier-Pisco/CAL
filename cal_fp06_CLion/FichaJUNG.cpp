#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
    GraphViewer *gv = new GraphViewer(600, 600, true);
    gv->setBackground("background.jpg");
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    int id = 0;
    gv->addNode(id);
    gv->rearrange();

    id = 1;
    gv->addNode(id);
    gv->rearrange();

    gv->addEdge(0, 0, 1, EdgeType::DIRECTED);
    gv->removeNode(1);

    gv->addNode(2);
    gv->addEdge(0, 0, 2, EdgeType::DIRECTED);
    gv->setEdgeLabel(0, "Isto e uma aresta");
    gv->setVertexLabel(0, "Isto e um no");
    gv->setVertexColor(0, "green");
    gv->setEdgeColor(0, "yellow");
}

void exercicio2()
{
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    gv->addNode(0, 300, 50);
    gv->addNode(1, 318, 58);
    gv->addNode(2, 325, 75);
    gv->addNode(3, 318, 93);
    gv->addNode(4, 300, 100);
    gv->addNode(5, 282, 93);
    gv->addNode(6, 275, 75);
    gv->addNode(7, 282, 58);
    gv->addNode(8, 150, 200);
    gv->addNode(9, 300, 200);
    gv->addNode(10, 450, 200);
    gv->addNode(11, 300, 400);
    gv->addNode(12, 200, 550);
    gv->addNode(13, 400, 550);
    gv->rearrange();

    gv->addEdge(0, 0, 1, EdgeType::DIRECTED);
    gv->addEdge(1, 1, 2, EdgeType::DIRECTED);
    gv->addEdge(2, 2, 3, EdgeType::DIRECTED);
    gv->addEdge(3, 3, 4, EdgeType::DIRECTED);
    gv->addEdge(4, 4, 5, EdgeType::DIRECTED);
    gv->addEdge(5, 5, 6, EdgeType::DIRECTED);
    gv->addEdge(6, 6, 7, EdgeType::DIRECTED);
    gv->addEdge(7, 7, 0, EdgeType::DIRECTED);
    gv->addEdge(8, 4, 9, EdgeType::DIRECTED);
    gv->addEdge(9, 9, 8, EdgeType::DIRECTED);
    gv->addEdge(10, 9, 10, EdgeType::DIRECTED);
    gv->addEdge(11, 9, 11, EdgeType::DIRECTED);
    gv->addEdge(12, 11, 12, EdgeType::DIRECTED);
    gv->addEdge(13, 11, 13, EdgeType::DIRECTED);

    int id = 13;

    while(id < 50){
        sleep(1);
        gv->removeNode(id - 1);
        gv->removeNode(id++);

        gv->addNode(id, 250, 550);
        gv->addEdge(12, 11, id++, EdgeType::DIRECTED);
        gv->addNode(id, 350, 550);

        gv->addEdge(13, 11, id, EdgeType::DIRECTED);
        gv->rearrange();


        sleep(1);
        gv->removeNode(id - 1);
        gv->removeNode(id++);

        gv->addNode(id, 200, 550);
        gv->addEdge(12, 11, id++, EdgeType::DIRECTED);
        gv->addNode(id, 400, 550);

        gv->addEdge(13, 11, id, EdgeType::DIRECTED);
        gv->rearrange();

    }



}

void exercicio3()
{
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    ifstream f;
    f.open("../resources/mapa1/nos.txt");
    string s, number;
    while(getline(f, s) && (s.size() > 2)){
        number = s.substr(0, s.find(';'));
        s.erase(0, s.find(";") + 1);
        int id = stoi(number);
        number = s.substr(0, s.find(';'));
        s.erase(0, s.find(";") + 1);
        cout << s << endl;
        int x = stoi(number);
        int y = stoi(s);
        gv->addNode(id, x, y);
    }
    gv->rearrange();
    f.close();
    f.open("../resources/mapa1/arestas.txt");
    while(getline(f, s) && (s.size() > 2)){
        number = s.substr(0, s.find(';'));
        s.erase(0, s.find(';') + 1);
        int id = stoi(number);
        number = s.substr(0, s.find(';'));
        s.erase(0, s.find(';') + 1);
        int v1 = stoi(number);
        int v2 = stoi(s);
        gv->addEdge(id, v1, v2, EdgeType::UNDIRECTED);
    }
    gv->rearrange();
}

int main() {
    /*
     * Uncomment the line below to run Exercise 1
     */
    //exercicio1();

    /*
      * Uncomment the line below to run Exercise 2
      */
    //exercicio2();

    /*
      * Uncomment the line below to run Exercise 3
      */
	//
	exercicio3();

	getchar();
	return 0;
}
