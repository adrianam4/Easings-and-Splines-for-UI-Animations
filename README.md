# Easings and Splines for UI Animations
## Index
1. [Introduction and goals](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/README.md#1-introduction-and-goals)

2. [Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#2-easings)

   2.1. [Types of Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#21-types-of-easings)
   
   2.2. [Uses of Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#22-uses-of-easings)
   
   2.3. [How does it work](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#23-how-does-it-work)
   
   2.4. [Easing Functions](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#24-easing-functions)

3. [Splines](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#3-splines)
   
   3.1. [Uses of Splines](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#31-uses-of-splines)

4. [Improvements](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#4-improvements)

5. [References](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#5-references)

## 1. Introduction and goals
I'm [Adrián Aroca](https://www.linkedin.com/in/adri%C3%A1n-aroca-mascaraque-4570001a2/), a student of the [Bachelor's Degree in Design and Develpment of Videogames at CITM (UPC)](https://www.citm.upc.edu/). This is my personal research for the subject "Project 2" which is given by [Ramon Santamaria](https://www.linkedin.com/in/raysan/), the main developer of [Raylib](https://www.raylib.com/).

My main goal in this research is creating a C++ library that let my class mates create his own animations based on easings and splines for their videogames, as easily as possible. Then, I must do a presentation where I will explain all the content i have prepared, in order to everyone can understand what an easing and spline is, and how they work. Moreover, I need to implement a soulution where I will show how an animated logo can be created using easings and splines. 

## 2. Easings
There is no object in real life that just start and stop instantly, and almost never move at constant speed. For example, when you drop a ball from your arms, it first gains velocity (accelerate downwards), and then bounce back up after hitting the floor (accelerate upwards). This is what easings are, and this is what i will explain here.
Implementing animations that describes movements of this type frame by frame, would be a nightmare. But, luckyly, there are mathematical functions that can be implemented by coders. And this is something that can diminish the amount of work of animators. Moreover, with that functions, the results obtained will be much more smooth. In the case of the bouncing ball, instead of coding the amount of distance it needs to travel each frame, using easings, you can just give the ball a speed depending on the distance from his objective position.

All the easing functions depends on four parameters:

- Current time (t) which is the moment where the object is.
- Begginning position (b) which is the position the object have at time "t".
- Change in distance (c) which is the difference of distance between the beggining position and the final one (f-b).
- Duration (d) that represent the amount of total iterations you want for complete your animation.

![Bouncing Ball Example](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/bouncing_ball.gif)

### 2.1 Types Of Easings
There are some different types of easings, which can be sort like that:

First of all, there are 3 easings types:
   1. Ease in: This type of easing, describes the movement of an object with POSITIVE acceleration.
   2. Ease Out: This type of easing, describes the movement of an object with NEGATIVE acceleration.
   3. Mixed: This one, mixes the both previous types (Usually describes a positive acceleration first, and then a negative one).
   
   ![Types of easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/types%20of%20easings.png)

That 3 types were the biggest types of easing, the most global ones. But, there is a lot of specific functions you can use to describe movements based on easings. 

- Standard Functions (Uses pows from 1-6)
  1. Linear: Using a pow of 1, it describes a linear movement with no acceleration (constant speed).
 
  2. Quad: Describes a movement accelerated, where the speed is increased by a pow of 2.
  
  3. Cubic: Describes a movement accelerated, where the speed is increased by a pow of 3.
  
  4. Quard: Describes a movement accelerated, where the speed is increased by a pow of 4.
  
  5. Quint or Strong: Describes a movement accelerated, where the speed is increased by a pow of 5.
   
  6. Circular: Uses a pow of 6, and describes a circular movement.
   
- Complex Functions

  1.Sinusoidal: Is achieved by using the mathematical sin and cos methods.
  
  2.Bounce: This one is used for recreate how a bouncing ball would be moved by gravity force. Applying first an ease in, and then an ease out.
  
  3.Back: On this one, the object goes until an objective position, and then, it comes back. 
  
  4.Exponential: The exponential function is similar to the standard ones, but this one, increase or/and decrease exponentially to the initial value.
  
  5.Elastic: The elastic function is needed when you want to describe a movement where your object is accelerated and decelerated so smoothly. 
   
### 2.2 Uses of Easings
### 2.3 How Does It Work
### 2.4 Easing Functions 
## 3. Splines
### 3.1 Uses Of Splines
## 4. Improvements
## 5. References

