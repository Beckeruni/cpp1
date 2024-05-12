// 315442236 aviad.becker@msmail.ariel.ac.il

#include <cstddef>
#include <iterator>
#include <list>
#include <vector>
#include <array>

using namespace std;

#pragma once

// declare class

// we will look at a graph as a vector of vectors. every inner vector of size 3. Where vertice (start, end, weight)
// we will keep matrix to use in some cases
class Graph{
    public:
    vector<vector<int>> mData;
    vector<array<int, 3>> gData;
    vector<vector<int>> adjL;
    int numOfVertices;
    int numOfEdges;
    bool negative;// true if there is a negative weight
    int type; // 1- undirected graph, 2- only positive weights, 3 - negative weights allowed  //גרף מכוון ולא מכוון וגם גרף ממושקל 
    
   
   
    Graph(vector<vector<int>> mData){
        mData = mData;
        gData = loadGraph(mData);
        numOfVertices, numOfEdges= numOfVerticesAndEdges(mData).first, numOfVerticesAndEdges(mData).second;
        type = typeOfGraph(mData);
        adjL = adjList(gData);
        negative = hasNegative(mData);
    }


    // returns true if loaded
    static bool printGraph(vector<vector<int>> matrix);

    static vector<array<int,3>> loadGraph(vector<vector<int>> matrix);

    static pair<int, int> numOfVerticesAndEdges(vector<vector<int>> matrix);

    vector<vector<int>> adjList(vector<array<int, 3>> gData);

    static int typeOfGraph(vector<vector<int>> matrix);
    
    vector<vector<int>> turnSymmetrical(vector<vector<int>> matrix);

    bool hasNegative(vector<vector<int>> matrix);

};