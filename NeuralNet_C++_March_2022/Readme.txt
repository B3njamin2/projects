The program is a fully connected feed foward neural network made using vectors.
The user can change the layout of the neural net and the learning rate.
There are already multiple trainning data in this folder that can be tested.
You can test the neural net with your own training data as long as it is in a txt file.
The inputs and target must be seperated by a space in that order
and the data must be seperated by a new line for each epoch
as the program will check that the input and target size matches with the neural net

Settings that Works!!!

sometimes we get unlucky with the random weight initialization
and exploding and vanishing gradients happen
rerunning the program can fix it

---trainingAllGates.txt---

leakyRelu setlearning 0.2   | setConstant(0.5) | layout 2,8,4 
sigmoid   setlearning 10-1  | layout 2,(4-8),4
Tanh      setlearning 0.1   | layout 2,8,4

---Training with individual gates---

leakyRelu learning rate = 0.1 | setConstant(0.1) | layout 2,3,1
sigmoid   learning rate = 1   | layout 2,4,1 
Tanh      learning rate = 0.1 | layout 2,3,3,1   



