from math import sqrt
import turtle
from random import randint



def KnightMovement(posx, posy):  # gives all the possible moves of the knight from a point
    posx1 = posx + 1
    posy1 = posy + 2

    posx2 = posx1
    posy2 = posy - 2

    posx3 = posx - 1
    posy3 = posy1

    posx4 = posx3
    posy4 = posy2

    posx5 = posx + 2
    posy5 = posy + 1

    posx6 = posx - 2
    posy6 = posy5

    posx7 = posx5
    posy7 = posy - 1

    posx8 = posx6
    posy8 = posy7

    # retuns all the 8 possible moves of a knight
    return (posx1, posy1), (posx2, posy2), (posx3, posy3), (posx4, posy4), (posx5, posy5), (posx6, posy6), (posx7, posy7), (posx8, posy8)

def outOfBounds(list): #remove all out of positions out of the board
    return [item for item in list if (item[0]<5 and item[0]>-6) and (item[1]<6 and item[1]>-6)]
    

def MinKnightMovement(posx, posy, desx, desy):
    print(F"{posx+5,posy+5}", end="\t")
    count = 1  # defining a variable that keeps count of the number of moves we need to make
    
    b=65 # b and c helps with the alignment when drawing on the screen
    c=30 

    # Draws info on the chess board
    win=turtle.Screen()
    turtle.colormode(255)
    win.bgpic("Chess Board.gif")
    turtle.pensize(4)
    turtle.penup()
    turtle.speed(10)
    for i in range(11):
        turtle.goto(-370,-340+(i*65))
        turtle.pendown()
        turtle.write(f"{i}",font=("Arial",20,"normal"))
        turtle.penup()
    for i in range(10):
        
        turtle.goto(-300+(i*65),-400)
        turtle.pendown()
        turtle.write(f"{i}",font=("Arial",20,"normal"))
        turtle.penup()
    turtle.speed(2)   
    
    turtle.goto(desx*b+c,desy*b)
    turtle.pendown()
    turtle.fillcolor('yellow')
    turtle.begin_fill()
    turtle.circle(15,steps=3)
    turtle.end_fill()
    turtle.penup()
    turtle.goto(posx*b+c,posy*b)
    turtle.pendown()
    turtle.fillcolor('blue')
    turtle.begin_fill()
    turtle.circle(15,steps=3)
    turtle.end_fill()

    next_pos = outOfBounds(list(KnightMovement(posx, posy))) # store all next possible position form the start position
    first_per_des = outOfBounds(list(KnightMovement(desx, desy))) # all the first possible position form the destination
    second_per_des=[] 

    for i in range(len(first_per_des)): # store all possible position two steps from the destination
        second_per_des.extend(outOfBounds(list(KnightMovement(first_per_des[i][0], first_per_des[i][1]))))       

    if posx==desx and posy==desy: # if destination and position are the same 
        turtle.penup()
        turtle.goto(-160,370) 
        turtle.color('black')
        turtle.write("0 moves to reach destination",font=("Arial",16,"normal"))
        count-=1
        return count

    elif (desx, desy) in next_pos:  # if we can reach the des x and y in one move
        turtle.color(randint(0,255),randint(0,255),randint(0,255))
        turtle.goto(desx*b+c,turtle.ycor())
        turtle.goto(desx*b+c,desy*b)
        turtle.penup()
        turtle.goto(desx*b+c+5,desy*b+5)
        turtle.color("red")
        turtle.write(f"{count}",font=("Arial",20,"normal"))
        turtle.penup()
        turtle.goto(-160,370) 
        turtle.color('black')
        turtle.write(f"{count} move to reach destination",font=("Arial",16,"normal"))
        print(f"{desx+5, desy+5}") 
        return count
    elif any(item in next_pos for item in first_per_des):  # if we can reach the des x and y in two move
        count +=1
        indermediate=list(set(next_pos).intersection(set(first_per_des)))[0]
        
        turtle.color(randint(0,255),randint(0,255),randint(0,255))
        turtle.goto(indermediate[0]*b+c,int(turtle.ycor()))
        turtle.goto(indermediate[0]*b+c,indermediate[1]*b)
        turtle.color("red")
        turtle.write("1",font=("Arial",20,"normal"))
        turtle.color(randint(0,255),randint(0,255),randint(0,255))
        turtle.goto(desx*b+c,turtle.ycor())
        turtle.goto(desx*b+c,desy*b)
        turtle.penup()
        turtle.goto(desx*b+c+5,desy*b+5)
        turtle.color("red")
        turtle.write("2",font=("Arial",20,"normal"))
        turtle.penup()
        turtle.goto(-160,370) 
        turtle.color('black')
        turtle.write(f"{count} moves to reach destination",font=("Arial",16,"normal"))
        indermediate=(indermediate[0]+5,indermediate[1]+5)
        print(indermediate)
        print(f"{desx+5, desy+5}")
        return count
        
                    
    else:  # if we can't reach the destination in one or two moves
        
        while any(item in next_pos for item in second_per_des) == False: # While the current position and destination is not 3 steps ways
                
            for i in range(len(next_pos)-1): #organize the next position list from closest distance to farthest distance from the destination       
                if sqrt(((next_pos[i][0])-desx)**2+((next_pos[i][1])-desy)**2) <= sqrt(((next_pos[i+1][0])-desx)**2+((next_pos[i+1][1])-desy)**2):
                    next_pos[i],next_pos[i+1]=next_pos[i+1],next_pos[i] 
                
            next_pos=[next_pos[len(next_pos)-1]]
            
            turtle.color(randint(0,255),randint(0,255),randint(0,255))
            turtle.goto(next_pos[0][0]*b+c,turtle.ycor())
            turtle.goto(next_pos[0][0]*b+c,next_pos[0][1]*b)
            turtle.color("red")
            turtle.write(f"{count}",font=("Arial",20,"normal"))
            
            forprint=(next_pos[0][0]+5,next_pos[0][1]+5)
            print(forprint, end="\t")
            
            for a in range(len(next_pos)):
                next_pos.extend(outOfBounds(list(KnightMovement(next_pos[a][0], next_pos[a][1]))))
            next_pos.pop(0)                    
            count += 1  # increases the count ( we made an extra move)
        
        # find the intersection between the list of possible moves from second position fron destination 
        # and next possible move from current position
        intersection=list(set(next_pos).intersection(set(second_per_des)))  
        print2=(intersection[0][0]+5,intersection[0][1]+5)
        print(print2, end="\t")

        next_pos = list(KnightMovement(intersection[0][0], intersection[0][1])) # next possible move after match 
        intersect2 = list(set(next_pos).intersection(set(first_per_des)))
        print3=(intersect2[0][0]+5,intersect2[0][1]+5)
        print(print3, end="\t") 
        print(f"{desx+5, desy+5}")
        
        turtle.color(randint(0,255),randint(0,255),randint(0,255))
        turtle.goto(intersection[0][0]*b+c,turtle.ycor())
        turtle.goto(intersection[0][0]*b+c,intersection[0][1]*b)
        turtle.color("red")
        turtle.write(f"{count}",font=("Arial",20,"normal"))
        count += 1
        turtle.color(randint(0,255),randint(0,255),randint(0,255))
        turtle.goto(intersect2[0][0]*b+c,turtle.ycor())
        turtle.goto(intersect2[0][0]*b+c,intersect2[0][1]*b)
        turtle.color("red")
        
        turtle.write(f"{count}",font=("Arial",20,"normal"))
        count += 1
        turtle.color(randint(0,255),randint(0,255),randint(0,255))
        turtle.goto(desx*b+c,turtle.ycor())
        turtle.goto(desx*b+c,desy*b)
        turtle.penup()
        turtle.goto(desx*b+c+5,desy*b+5)
        turtle.color("red")
        turtle.write(f"{count}",font=("Arial",20,"normal"))
        turtle.penup()
        turtle.goto(-160,370) 
        turtle.color('black')
        turtle.write(f"{count} moves to reach destination",font=("Arial",16,"normal"))
        
        return count  # returns the number of moves needed to reach the destination

a,b,c,d = (eval(input("x:(0-9) y(0-10) Input location and destination in form (x1,y1,x2,y2): ")))
 
a-=5
c-=5
b-=5
d-=5

if (a> 4 or a <-5) or (b>5 or b<-5) or (c> 4 or c <-5) or (d>5 or d<-5):
    print("coordinates not on board")
else:   
    print(f"{MinKnightMovement(a,b,c,d)} moves to reach destination")
    turtle.done()
    
    