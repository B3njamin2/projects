#pragma once
#include "graph.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class DirectedGraph : public Graph
{
public:
    // constucotr
    DirectedGraph() : Graph() {}
    DirectedGraph(std::vector<Vertex> &vArray, std::vector<Edge> &eArray) : Graph(vArray, eArray) {}
    DirectedGraph(const DirectedGraph& copy) : Graph (copy){}

    // to string function: convers all verteries and edges to string
    std::string toString() const
    {
        std::string output;
        output += "\nVertices\n";
        for (size_t i{0}; i < vertexArr.size(); i++)
            output += std::to_string(i + 1) + ". " + vertexArr[i].toString() + "\n";
        output += "Edges\n";
        for (size_t i{0}; i < edgeArr.size(); i++)
            output += std::to_string(i + 1) + ". " + edgeArr[i].directedToString() + "\n";
        return output;
    }

    void pathFinder(int start, int end = -1) const
    {
        //verify if start id exists 
        const Vertex *s = returnVertexPtrbyID(start);
        std::vector<Vertex> idArr;
        if (end == -1)
        {
            // this happens if end id doesnt exist 
            // print the start vertex of the path
            std::cout << std::endl
                      << std::left << std::setw(15) << s->toString();
            // the function that will print all the path
            thePathFinder(start, idArr);
        }
        else
        {
            // check if end id exist
            const Vertex *e = returnVertexPtrbyID(end);
            std::cout << "\n\n---------All paths from " << s->toString()
                      << " to " << e->toString() << "------------\n";
            // function that will the path between two paths
            thePathFinder(start, end, idArr);
        }
        std::cout<<"\nNo other paths found\n";
    }

    // the PathFinder overloauding function
    void thePathFinder(int begin, int end, std::vector<Vertex> &arr) const
    {
        // intirate through the edge Arr
        for (size_t i{0}; i < edgeArr.size(); i++)
            // if start vertex matches in the edge arr
            if (edgeArr[i].getV1().getId() == begin)
            {
                // create a temporary Arr
                std::vector<Vertex> tempArr = arr;
                // keep track of the path already taken
                tempArr.push_back(edgeArr[i].getV1());
                // if the next id matches our destination vertex
                if (edgeArr[i].getV2().getId() == end)
                {
                    //print the whole path.
                    tempArr.push_back(edgeArr[i].getV2());
                    std::cout << "\n\n"
                              << std::left << std::setw(15) << tempArr[0].toString();
                    for (int i = 1; i < tempArr.size(); i++)
                        std::cout << std::setw(25) << ("------->" + tempArr[i].toString());

                    continue;
                }

                int nextId = edgeArr[i].getV2().getId();
                // the checkVertexArr keeps track of the path already taken and 
                // avoids looping on its self
                if (checkVertexInArr(nextId, arr))
                    continue;
                // rerun itself with the next vertex as the begin vertex
                thePathFinder(nextId, end, tempArr);
            }
    }

    void thePathFinder(int begin, std::vector<Vertex> &arr) const
    {
        bool check = false;
        
        // intirate through the edge Arr
        for (size_t i{0}; i < edgeArr.size(); i++)
            // if any vertex matches in the edge arr
            if (edgeArr[i].getV1().getId() == begin)
            {   
                // create a temporary Arr
                std::vector<Vertex> tempArr = arr;
                tempArr.push_back(edgeArr[i].getV1());
                // if previous iteration have already been printed in the terminal 
                // creat a new line to avoid overlapping paths in the terminal
                if (check)
                {
                    
                    std::cout << "\n\n               ";
                    std::cout << std::left << std::setw(25 * (arr.size())) << "";
                }
                // print the next vertex relation
                std::cout << std::setw(25) << ("------->" + edgeArr[i].getV2().toString());

                check = true;
                int nextId = edgeArr[i].getV2().getId();

                // the checkVertexArr keeps track of the path already taken and 
                // avoids looping on its self
                if (checkVertexInArr(nextId, arr))
                    continue;
                
                // rerun itself with the next vertex as the begin verte
                thePathFinder(nextId, tempArr);
            }
    }

   

    

    bool checktype()const{return 1;}
};