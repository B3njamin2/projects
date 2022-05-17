#include "directedGraph.h"
#include "undirectedGraph.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
    // initializing vertices
    Vertex ver1(DogBreed("Labrador", 57, 11));
    Vertex ver2(DogBreed("Bulldog", 63, 23));
    Vertex ver3(DogBreed("Corgie", 49, 14));
    Vertex ver4(DogBreed("Chihuahua", 29, 18));
    Vertex ver5(DogBreed("Poodle", 15, 29));
    
  

    // initializing edges
    Edge edge1(ver1, ver2, 10);
    Edge edge2(ver3, ver1, 20);
    Edge edge3(ver1, ver4, 30);
    Edge edge4(ver2, ver4, 40);
    Edge edge5(ver4, ver3, 50);
    Edge edge6(ver4, ver5, 60);

    // creating the arrays to be passed into graph
    std::vector<Vertex> Vs{ver1, ver2, ver3, ver4, ver5};
    std::vector<Edge> Es{edge1, edge2, edge3, edge4, edge5, edge6};

    // initializing the graph 

    Graph *graph;


    
    std::cout << "\n----------WoofWoof to the DBD (Dog Breed Database)----------\n";
    std::cout << "\nWith this program, you can see the information about the dogs in our list!\n";

    std::cout << "\n[1] Directed Graph\n"                               //first menu to decide to ask for type of graph
                 "[2] Undirected Graph\n"
                 "[3] End Program\n";

    int UserSelection = -1;
    int escape=1;

    while (escape)
    {
        std::cout << "\nWhat would you like to do? ";                   
        if (!(std::cin >> UserSelection))
        {
            std::cin.clear();
            std::cout << "\nPlease enter an integer from 1 to 3\n";
            
        }
        else
        {
            switch (UserSelection)
            {
            case 1:
                graph = new DirectedGraph;                              //sets graph type to Directed Graph
                escape=0;
                break;
            case 2:
                graph = new UndirectedGraph;                            //sets graph type to Undirected Graph
                escape=0;
                break;
            case 3:
                std::cout << "\n\nEnding Program!\n\n\n";              
                exit(1);
            default:
                std::cout << "\nThe number entered is not one of the choices (integer from 1 to 3), please try again \n";
            }
        }
        std::string dump;
        std::getline(std::cin, dump);
    }

    std::cout << "\n[1] Use pre-made database of dogs\n"                         //second menu asks if pre-set data to be used or to create and start graph from scratch
                 "[2] Add your own dogs (vertices) and relations (edges)\n"
                 "[3] End Program\n";

    escape = 1;
    while (escape)
    {
        std::cout << "\nWhat would you like to do? ";
        if (!(std::cin >> UserSelection))
        {
            std::cin.clear();
            std::cout << "\nPlease enter an integer from 1 to 3\n";
        }
        else
        {
            switch (UserSelection)
            {
            case 1:
                graph->addVertices(Vs);                 //adds pre-set data to graph
                graph->addEdges(Es);
                escape=0;
                break;
            case 2:
                escape=0;                               //leaves graph empty for data to be added manually
                break;
            case 3:
                std::cout << "\n\nEnding Program!\n\n\n";
                exit(1);

            default:
                std::cout << "\nThe number entered is not one of the choices (integer from 1 to 3), please try again \n";
            }
        }
        std::string dump;
        std::getline(std::cin, dump);
    }
    

    Menu M(graph);                      //creates Menu class object and passes the graph in to it
    M.DisplayMenu();                    //function displays third and final menu

    while (UserSelection != 14)                                             
    {
        std::cout << "\nWhat would you like to do? [0] to see menu: ";         
        if (!(std::cin >> UserSelection))
        {                                                               //this section checks for invalid input
            std::cin.clear();
            std::cout << "\nPlease enter an integer from 0 to 14\n";
        }
        else
        {
            switch (UserSelection)
            {
            case 0:
                M.DisplayMenu();                                        //displays menu
                break;
            case 1:
                M.listDatabase();                                       //lists dogs and their ids
                break;
            case 2:
                M.listDatabaseWithEdges();                              //list dogs(vertices) and their relations(edges)
                break;
            case 3:
                graph->printAllDogs();                                  //prints all dogs' information
                break;
            case 4:
                M.addVertexByMenu();                                    //add dog and created edge to other dog
                break;
            case 5:
                M.addVerticesByMenu();                                  //only add dog, no edge. used for manually filling empty graph
                break;
            case 6:
                M.addEdgesByMenu();                                     //only add relations (edges). used for manually filling empty graph
                break;
            case 7:
                M.removeVertexByMenu();                                 //remove dog (vertex) and all edges it is linked to
                break;
            case 8:
                M.printDogByMenu();                                     //print individual dogs' information
                break;
            case 9:
                graph->allPathFinder();                                 //list all possible paths from every dog (vertex)
                break;
            case 10:
                M.pathFinderByMenu();                                   //list all possible paths from 1 individually chosen dog
                break;
            case 11:
                M.findDogRelationshipByMenu();                          //check if two dogs are directly related and list their information
                break;
            case 12:
                M.aPathFinderByMenu();                                  //list paths between two chosen dogs (vertices)
                break;
            case 13:
                graph->clean();                                         //clear out all vertices and edges in graph
            case 14:
                break;                                                  //end program

            default:
                std::cout << "\nThe number entered is not one of the choices (integer from 0 to 14), please try again \n";
            }
        }
        std::string dump;
        std::getline(std::cin, dump);
    }
    std::cout << "\n\nEnding Program!\n\n\n";
}
