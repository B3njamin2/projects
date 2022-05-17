#pragma once
#include "Edge_Vertex.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

class Graph
{
protected:
    std::vector<Vertex> vertexArr;                //attributes include an array of vertices
    std::vector<Edge> edgeArr;                    //array of edges

    Graph() {}      //default constructor

    Graph(std::vector<Vertex> &vArray, std::vector<Edge> &eArray)   //constructor   
    {
        addVertices(vArray);        //adds arrays of vertices and edges to graph
        addEdges(eArray);
    }

    Graph (const Graph& copy)        //copy constructor
    {
        vertexArr = copy.vertexArr;
        edgeArr = copy.edgeArr;
    }

    Vertex ReturnVertexByName(std::string dogbreed)     //returns a vertex by dog breed name, throws exception if not found
    {
        for (size_t i{0}; i < vertexArr.size(); i++)
            if (vertexArr[i].getDog().getBreed() == dogbreed)
                return vertexArr[i];
        throw std::runtime_error("Dog breed: " + dogbreed + " notfound!");
    }

    bool checkVertexInArr(int id, std::vector<Vertex> &Arr) const   //pass array and id into this to check if a vertex
    {                                                               //exists within the array, returns bool

        for (int i = 0; i < Arr.size(); i++)
            if (Arr[i].getId() == id)
                return true;

        return false;
    }

    const Vertex *returnVertexPtrbyID(int id) const                 //returns pointer to vertex by passing in id
    {                                                               //throwds exception if not found
        // iterate over all the vertices and find for matching id
        for (size_t i{0}; i < vertexArr.size(); i++)
            if (vertexArr[i].getId() == id)
                return &vertexArr[i];
        throw std::runtime_error("ID " + std::to_string(id) + " notfound!");
    }

public:
                                                         

    void addVertex(const Vertex &v)                         //add vertex to vertex array
    {
        vertexArr.push_back(v);
    }
    void addVertices(const std::vector<Vertex> &vArray)     //add multiples vertices to vertex array
    {
        for (int i{0}; i < vArray.size(); i++)
            addVertex(vArray[i]);
    }

    // the edges that has connection with this vertex needs to be removed;
    void removeVertex(std::string breed)        //removes vertex and any edges that are linked to it
    {

        for (size_t i{0}; i < vertexArr.size(); i++)
            // assuming data is correct there should only be one instance of a unique id vector in the arr
            // when the unique id is found then the edgearr will be searched
            if (vertexArr[i].getDog().getBreed() == breed)
            {

                vertexArr.erase(vertexArr.begin() + i);
                for (size_t i{0}; i < edgeArr.size(); i++)
                    // either the begin or the end of the edge needs to match with the id for the edge to be removed
                    if (edgeArr[i].getV1().getDog().getBreed() == breed || edgeArr[i].getV2().getDog().getBreed() == breed)
                        {edgeArr.erase(edgeArr.begin() + i--);
                        return;}
            }

        throw std::runtime_error("\n" + breed + " could not be found"); //throws exception if dog breed not found
    }

    void addEdge(const Edge &e)                 //adds edge to edge array
    {
        edgeArr.push_back(e);
    }
    
    void addEdges(const std::vector<Edge> &eArray)  //adds multiple edges to edge array
    {
        for (int i{0}; i < eArray.size(); i++)
            addEdge(eArray[i]);
    }
    // remove a edge; as a result, some node may remain as orphan.
    bool remove(const Edge &e)
    {
        // iterate over all edges if the begin,end id and weight matches then it will be removed
        for (size_t i{0}; i < edgeArr.size(); i++)
            if (edgeArr[i].getV1().getId() == e.getV1().getId() &&
                edgeArr[i].getV2().getId() == e.getV2().getId() &&
                edgeArr[i].getWeight() == e.getWeight())
            {
                edgeArr.erase(edgeArr.begin() + i);
                return true;
            }

        return false;
    }

    // return bool if a Edge exists in a graph;
    bool searchEdge(const Edge &e) const
    {
        // iterate over all the vertices and find for matching begin, end id and weight
        for (size_t i{0}; i < edgeArr.size(); i++)
            if (edgeArr[i].getV1().getId() == e.getV1().getId() &&
                edgeArr[i].getV2().getId() == e.getV2().getId() &&
                edgeArr[i].getWeight() == e.getWeight())
                return true;
        return false;
    }

    void printAllDogs() const           //prints all dogs' information
    {
        for (size_t i{0}; i < vertexArr.size(); i++)
        {
            std::cout << std::endl
                      << i + 1 << ". Who's this doooog?"
                      << "Doggy Tag ID: " << std::left << std::setw(15) << vertexArr[i].getId()
                      << "\n------------------------------------------------------------------\n"
                      << " Breed: " << vertexArr[i].getDog().getBreed() << std::endl
                      << "Average Height(Inches): " << std::setw(4) << vertexArr[i].getDog().getHeight()
                      << "  Average Life Expectency(Years): " << vertexArr[i].getDog().getLifeExpectancy()
                      << "\n------------------------------------------------------------------\n";
        }
    }

    void printDog(const Vertex &dog) const  //print individual dogs' information
    {
        std::cout << std::endl
                  << "Who's this doooog?"
                  << "\n------------------------------------------------------------------\n"
                  << "Doggy Tag ID: " << std::left << std::setw(15) << dog.getId()
                  << " Breed: " << dog.getDog().getBreed() << std::endl
                  << "Average Height(Inches): " << std::setw(4) << dog.getDog().getHeight()
                  << "  Average Life Expectency(Years): " << dog.getDog().getLifeExpectancy()
                  << "\n------------------------------------------------------------------\n";
    }

    // remove all the vertices and edges;
    void clean()
    {
        vertexArr.clear();
        edgeArr.clear();
    }

    // search for a specific edge and prints out its information
    void queryByEdge(const Edge &edge) const
    {
        
        for (size_t i{0}; i < edgeArr.size(); i++)
        {
            if (edgeArr[i].getV1().getId() == edge.getV1().getId() &&
                edgeArr[i].getV2().getId() == edge.getV2().getId())
            {
                std::cout << "\n\nYes!!! " << edge.getV1().getDog().getBreed() << " and " << edge.getV2().getDog().getBreed() << " are related!\n\nHere's their info:     "
                          << ((checktype())?edgeArr[i].directedToString():edgeArr[i].undirectedToString());
                printDog(edgeArr[i].getV1());
                printDog(edgeArr[i].getV2());
                return;
            }
            if (edgeArr[i].getV1().getId() == edge.getV2().getId() &&
                edgeArr[i].getV2().getId() == edge.getV1().getId())
            {
                std::cout << "\n\nYes!!! " << edge.getV1().getDog().getBreed() << " and " << edge.getV2().getDog().getBreed() << " are related!\n\nHere's their info:     "
                          << ((checktype())?edgeArr[i].directedToString():edgeArr[i].undirectedToString());
                printDog(edgeArr[i].getV2());
                printDog(edgeArr[i].getV1());
                return;
            }
        }
        std::cout << std::endl
                  << edge.getV1().getDog().getBreed() << " and " << edge.getV2().getDog().getBreed() << " aren't related :(\n";
    }
    
    // this function search for a specific vertex by dog breed name and prints its information
    void queryByVertexValue(std::string dogbreed) const
    {

        for (size_t i{0}; i < vertexArr.size(); i++)
        {
            if (vertexArr[i].getDog().getBreed() == dogbreed)
            {
                printDog(vertexArr[i]);
                return;
            }
        }
        
        std::cout << std::endl
                  << dogbreed << " not found :(\n";
    }

    // all path finder runs the find all path for each vertex the vertexArr
    void allPathFinder() const
    {
        std::cout << "Beware all possible paths incomming!\n";
        for (size_t i{0}; i < vertexArr.size(); i++)
            pathFinder(vertexArr[i].getId());
    }

    ~Graph() { clean(); }
    // virtual functions
    virtual bool checktype()const = 0;
    virtual std::string toString() const = 0;
    virtual void pathFinder(int start, int end = -1) const = 0;
    // friend functions and class
    friend class Menu;
    friend std::ostream &operator<<(std::ostream &stream, const Graph &other);
};
// override stream operator<<
std::ostream &operator<<(std::ostream &stream, const Graph &other)
{
    stream << other.toString();
    return stream;
}
