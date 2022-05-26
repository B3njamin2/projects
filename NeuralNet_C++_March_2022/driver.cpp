#include <vector>
#include <iostream>
#include "neuralNet.h"

// The driver is already set up to work with the "trainingALLGates.txt" training file
// check output data file after running for results
// Check Readme for other settings that work with other training files
int main(){

    // 1* neuralNet layout 

    // (can have multiple hidden layer ex: (2,3,3,3)) 
    // Therefore, it has (2 input ,2 x 3 nodes hidden layer, 3 output nodes)
    std::vector<int> map = {2,8,4};
    
    // 2* choose one activation function 

    LeakyRelu net(map);
    //Sigmoid net(map);
    //Tanh net(map);
    
    // 3* set learning rate
    net.setLearningRate(0.2);

    // 3.5* ONLY for LeakyRelu set constant
    net.setConstant(0.5);

    net.weightIntialization();

    // 4* train network

    // ("trainingfile.txt", "create_Output_filename.txt" , 1 or 0 )  
    // 1 = export weight and node data ||  0 = nothing)
    try{
        net.readandTrain("trainingAllGates.txt","_outputDataAllGates.txt",0);
    }
    catch(const std::runtime_error& error){
        std::cout<<"Error : "<<error.what()<<std::endl;
    }
    


    // (optional) test neural net with input using terminal and verify the outputs
    // net.test();
    

    /* list of all net. user functions 

        void weightIntialization()
        void forwardProp(const std::vector<double> &inputs);
        void backProp(const std::vector<double> &targets)
        std::vector<double> getOutput()
        double costFunction(const std::vector<double> &outputs,const std::vector<double> &targets) const
        void importWeights(std::string filename)
        void exportWeights(std::string filename )const
        void exportNodeInfo(std::string filename)
        static void setLearningRate(double Rate)
        void readandTrain(std::string trainingFile,std::string OutputFileName,int outputData)
        void test()
    */
}