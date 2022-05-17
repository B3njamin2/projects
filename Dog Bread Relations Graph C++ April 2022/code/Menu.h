#pragma once
#include "graph.h"
#include <iostream>
#include <string>
#include <stdexcept>

class Menu
{
private:
    Graph *graph;                               //only attribute is a pointer to a graph

public:
    Menu(){}

    Menu(Graph *Graph)                          //constructor
    {
        graph = Graph;
    }

    Menu(const Menu& copy)                      //copy constructor
    {
        graph = copy.graph;
    }

    void userInput(std::string &name)           //checks if user input is a string (with no numbers), if not throws exception
    {

        std::cin >> name;
        for (int i = 0; i < name.size(); i++)
        {
            if (((name[i]) < 'A' || (name[i]) > 'Z') && ((name[i]) > 'z' || (name[i]) < 'a'))
            {
                std::cin.clear();
                std::string dump;
                std::getline(std::cin, dump);
                throw std::runtime_error("\nBreed name should only contain letters. Please try again\n");
            }
        }
    }

    template <typename T>                       //template takes in any data type if the input causes and error throw exception
    void userInput(T &input, std::string errorMessage)  
    {

        if (!(std::cin >> input))
        {
            std::cin.clear();
            std::string dump;
            std::getline(std::cin, dump);
            throw std::runtime_error("\n" + errorMessage + "\n");
        }
    }

    void DisplayMenu()                          //displays main menu
    {
        std::cout << "\nHere are your options: \n"
                     "\n----Modify graph-----\n"
                     "[1] List all dog breeds in database\n"
                     "[2] List all dog breeds AND their relations\n"
                     "[3] List all dog breeds' detailed information\n"
                     "[4] Add dog breed to database and its relation\n"
                     "[5] Add multiple dog breeds (only vertices)\n"
                     "[6] Add relations (edges)\n"
                     "[7] Delete dog breed from \n"
                     "\n----Retrieve graph Info-----\n"
                     "[8] See a dog breed's info\n"
                     "[9] See complete relationship graphs for all dog breeds\n"
                     "[10] See complete relationship graph for an individual dog breed\n"
                     "[11] See if two dog breeds are directly related\n"
                     "[12] Path between two dog breed\n"
                     "\n---------Other----------\n"
                     "[13] Clear Graph\n"
                     "[14] End program\n";
    }

    void listDatabase()                         //lists dogs in database at any point in time
    {
        std::cout << "\nDog breed list: \n";
        for (size_t i{0}; i < graph->vertexArr.size(); i++)
        {
            std::cout << i + 1 << ". "
                      << "ID:" << graph->vertexArr[i].getId() << " "
                      << graph->vertexArr[i].getDog().getBreed() << std::endl;
        }
    }

    void listDatabaseWithEdges()                //uses operator overloading to display all vertices and edges in graph
    {                                           
        std::cout << *graph;
    }

    void addVertexByMenu()                      //adds dog(vertex) to graph and adds its relation (edge) with another dog
    {

        std::string breed, relation;
        int height, life, percent;

        try                                     
        {
            std::cout << "\nEnter dog breed (case sensitive): ";
            userInput(breed); // might throw exception
            std::cout << "Enter dog height: ";
            userInput(height, "The height should be an integer"); // might throw exception
            std::cout << "Enter dog life expectancy: ";
            userInput(life, "The life expectancy should be an integer"); // might throw exception
            Vertex newDog(DogBreed(breed, height, life));   //creates dog vertex 

            std::cout << "\nEnter the name of the dog in database it has relation with (case sensitive):  ";
            userInput(relation);                             // might throw exception
            std::cout << "Enter percentage of similarity: "; // might throw exception
            userInput(percent, "The percentage should be an interger");
            Edge newedge(newDog, graph->ReturnVertexByName(relation), percent); //creates edge, might throw exception
            graph->addVertex(newDog);   //adds vertex to graph
            graph->addEdge(newedge);    //adds edge to graph
        }
        catch (const std::runtime_error &error)    //catches exceptions through 
        {
            std::cout << "Error: " << error.what() << std::endl;
            return;
        }

        std::cout << "\nDog successfully added\n";
    }

    void addVerticesByMenu()                       //only add dog, no edge. used for manually filling empty graph 
    {
        std::string breed;
        int height, life;

        try
        {
            std::cout << "\nEnter dog breed: ";
            userInput(breed); // might throw exception

            if (breed == "end")
            {
                std::cout << "\nDone adding dog breeds\n";
                return;
            }

            std::cout << "Enter dog height: ";
            userInput(height, "The height should be an integer"); // might throw exception
            std::cout << "Enter dog life expectancy: ";
            userInput(life, "The life expectancy should be an integer"); // might throw exception
            Vertex newDog(DogBreed(breed, height, life));
            graph->addVertex(newDog);
        }
        catch (const std::runtime_error &error)
        {
            std::cout << "Error: " << error.what() << std::endl;
            return;
        }

        std::cout << "\nDog successfully added\n";
    }

    void addEdgesByMenu()                   //only add relations (edges). used for manually filling empty graph
    {

        int fid, sid, percent;

        try
        {

            std::cout << "\nDog 1 ID: ";
            userInput(fid, "The id should be an integer");
            std::cout << "\nDog 2 ID: ";
            userInput(sid, "The id should be an integer");
            std::cout << "Enter percentage of similarity: "; // might throw exception
            userInput(percent, "The percentage should be an interger");

            Edge newedge(*(graph->returnVertexPtrbyID(fid)), *(graph->returnVertexPtrbyID(sid)), percent); // might throw exception
            graph->addEdge(newedge);
        }
        catch (const std::runtime_error &error)
        {
            std::cout << "Error: " << error.what() << std::endl;
        }

        std::cout << "\nEdges successfully added\n";
    }

    void removeVertexByMenu()               //remove dog (vertex) and all edges it is linked to
    {

        std::string breed;
        std::cout << "\nEnter dog breed to remove from database (case sensitive): ";

        try
        {
            userInput(breed);
            graph->ReturnVertexByName(breed);
            graph->removeVertex(breed);
        }
        catch (const std::runtime_error &error)
        {
            std::cout << "Error: " << error.what() << std::endl;
        }
    }

    void printDogByMenu()                   //print individual dogs' information
    {
        std::string breed;
        std::cout << "\nEnter dog breed that you would like to see info on (case sensitive): ";

        try
        {
            userInput(breed);
            graph->queryByVertexValue(breed);
        }
        catch (const std::runtime_error &error)
        {
            std::cout << "Error: " << error.what() << std::endl;
        }
    }
    void findDogRelationshipByMenu()        //check if two dogs are directly related and list their information
    {
        std::string firstbreed, secondbreed;
        std::cout << "\nEnter two dog breeds to see if they're related (case sensitive): \n";

        try
        {
            std::cout << "First dog breed: ";
            userInput(firstbreed);
            std::cout << "Second dog breed: ";
            userInput(secondbreed);
            graph->queryByEdge(Edge(graph->ReturnVertexByName(firstbreed), graph->ReturnVertexByName(secondbreed)));
        }
        catch (const std::runtime_error &error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    void pathFinderByMenu()             //list all possible paths from 1 individually chosen dog            
    {
        int id;
        std::cout << "\nEnter dog breed ID that you would like to see the relationship graph for: ";

        try
        {
            userInput(id, "Please input the ID as an integer");
            graph->pathFinder(id);
        }
        catch (const std::runtime_error &error)
        {
            std::cout << error.what() << std::endl;
        }
    }

    void aPathFinderByMenu()            //list paths between two chosen dogs (vertices)
    {
        std::string dog1, dog2;
        std::cout << "\nPlease enter starting dog breed and ending dog breed (case sensitive):\n";

        try
        {
            std::cout << "First dog breed: ";
            userInput(dog1);
            std::cout << "Second dog breed: ";
            userInput(dog2);
            graph->pathFinder(graph->ReturnVertexByName(dog1).getId(), graph->ReturnVertexByName(dog2).getId());
        }
        catch (const std::runtime_error &error)
        {
            std::cout << error.what() << std::endl;
        }
    }
};