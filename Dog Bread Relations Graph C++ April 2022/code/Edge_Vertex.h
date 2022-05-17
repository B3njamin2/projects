#pragma once
#include <iostream>
#include <string>

// DogBreed class 
class DogBreed
{   
    // member variables
    std::string breed;
    double height;
    double lifeExpectancy;

public:
    //constructor
    DogBreed() : breed(""), height(0), lifeExpectancy(0) {}
    DogBreed(std::string Breed, double Height = 0, double life = 0) : breed(Breed), height(Height), lifeExpectancy(life) {}
    DogBreed(const DogBreed& copy) {breed = copy.breed; height = copy.height; lifeExpectancy = copy.lifeExpectancy;}
    //setters and getters
    std::string getBreed() const { return breed; }
    void setBreed(std::string Breed) { breed = Breed; }

    double getHeight() const { return height; }
    void setHeight(double Height) { height = Height; }

    double getLifeExpectancy() const { return lifeExpectancy; }
    void setLifeExpectancy(double life) { lifeExpectancy = life; }
};  

// vertex class
class Vertex
{   
    //member variables
    int id;
    DogBreed dog;
    static int idCounter;

public:
    // constructors
    Vertex()
    {

        id = ++idCounter;
    }
    Vertex(const DogBreed &Dog) : dog(Dog)
    {
        id = ++idCounter;
    }
    Vertex(std::string breed) : dog(breed)
    {
        id = ++idCounter;
    }

    // getters
    int getId() const { return id; }

    const DogBreed &getDog() const { return dog; }
    // tostring

    std::string toString() const
    {
        std::string str = "(" + std::to_string(id) + ", " + dog.getBreed() + ")";
        return str;
    }
};
int Vertex::idCounter = 0;

//Edge class
class Edge
{
    // member variables
    Vertex V1, V2;
    int weight;

public:

    //constructors
    Edge() : weight(0) {}
    Edge(const Vertex &v1, const Vertex &v2, int Weight = 0)
        : V1(v1), V2(v2), weight(Weight) {}

    // setter & getter
    Vertex getV1() const { return V1; }
    void setV1(const Vertex &v1) { V1 = v1; }

    Vertex getV2() const { return V2; }
    void setV2(const Vertex &v2) { V2 = v2; }

    int getWeight() const { return weight; }
    void setWeight(int Weight) { weight = Weight; }

    // toString() for directed and undirected
    std::string directedToString() const
    {
        std::string str = V1.toString() + "---" + std::to_string(weight) + "--->" + V2.toString();
        return str;
    }
    std::string undirectedToString() const
    {
        std::string str = V1.toString() + "<---" + std::to_string(weight) + "--->" + V2.toString();
        return str;
    }
};
