# Easings and Splines for UI Animations
## Index
1. [Introduction and goals](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/README.md#1-introduction-and-goals)

2. [Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#2-easings)

    2.1. [Types of Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#21-types-of-easings)
   
    2.2. [Uses of Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#22-uses-of-easings)
   
    2.3. [How does it work](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#23-how-does-it-work)
   
    2.4. [Easing Functions](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#24-easing-functions)

3. [Splines](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#3-splines)

    3.1. [Types of Splines](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/README.md#31-types-of-splines) 
   
    3.2. [Uses of Splines](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/README.md#32-uses-of-splines)

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
There are some different types of easings, which can be sorted like that:

First of all, there are 3 easings types:
   1. Ease in: This type of easing, describes the movement of an object with POSITIVE acceleration.
   2. Ease Out: This type of easing, describes the movement of an object with NEGATIVE acceleration.
   3. Mixed: This one, mixes the both previous types (Usually describes a positive acceleration first, and then a negative one).
   
   ![Types of easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/types%20of%20easings.png)

That 3 types were the biggest types of easing, the most global ones. But, there is a lot of specific functions you can use to describe movements based on easings. 

- Standard Functions (Uses pows from 1-6)

  1.Linear: Using a pow of 1, it describes a linear movement with no acceleration (constant speed).
 
  2.Quad: Describes a movement accelerated, where the speed is increased by a pow of 2.
  
  3.Cubic: Describes a movement accelerated, where the speed is increased by a pow of 3.
  
  4.Quart: Describes a movement accelerated, where the speed is increased by a pow of 4.
  
  5.Quint or Strong: Describes a movement accelerated, where the speed is increased by a pow of 5.
   
  6.Circular: Uses a pow of 6, and describes a circular movement.
   
- Complex Functions

  1.Sinusoidal: Is achieved by using the mathematical sin and cos methods.
  
  2.Bounce: This one is used for recreate how a bouncing ball would be moved by gravity force. Applying first an ease in, and then an ease out.
  
  3.Back: On this one, the object goes until an objective position, and then, it comes back. 
  
  4.Exponential: The exponential function is similar to the standard ones, but this one, increase or/and decrease exponentially to the initial value.
  
  5.Elastic: The elastic function is needed when you want to describe a movement where your object is accelerated and decelerated so smoothly. 
   
### 2.2 Uses of Easings

Like said previously, easings are used to create animations that describes accelerated movements by an easy way, because if that animations were created frame by frame, it would suppose a big amount of work, which is boring and unnecessary. Almost all the Software programs dedicated to 2D-3D Animation (For Example, Toon Boom Harmony), uses the easing functions (and most of them let the users previsualize the easing curves ). That allow the users to avoid creating hundreds of frames for a simple movement, and instead it does it automatically taking into account the distance between frames. Easings are also used in the area of Camera views, where the easing functions, allow the users to create a smooth experience and saving a lot of time and work, because they dont need to "Hard Code" the camera progress.

All this is possible thanks to all the Programmers or Coders that implement all the math functions explained [here](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#21-types-of-easings).

![Uses of Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/easing%20usability.gif)

### 2.3 How Does It Work
### 2.4 Easing Functions 
## 3. Splines
In *maths* area, a spline is a function defined piece by piece, by polynomials. In interpolating problems, spline interpolation is usually preferred over polynomial interpolation because it performs practically the same, even using low degree polynomials, while avoiding [Runge's phenomenon](https://en.wikipedia.org/wiki/Runge%27s_phenomenon) for higher degrees.

In *computer science*, when you talk about splines, you're talking about a piecewise polynomial curve. Splines are popular curves on this field because of the simplicity of their construction, their ease and accuracy of evaluation, and their capacity to approximate complex shapes through curve fitting and interactive curve design.

Now, let's see it from the field we're interested on, the Animation. Here, a spline is another method for creating animations on an easy way. Using splines, you will be able to create smooth animations just moving curves on a graph. So, using splines, you can do your work easyly, saving your time and effort.

There are some different types of splines, let's see them.
### 3.1 Types Of Splines
1. Bezier: Is just a spline defined "point by point", by different Bezier curves.

![Bezier](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/bezier.PNG)

2. Cubic: This one gives an interpolation polynomial that is smoother and has less error than some other interpolating polynomials. It's used to avoid the problem of Runge's phenomenon.

![Cubic](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/cubic%20spline.PNG)

3. B-Spline: Is a spline function that has minimal support with respect to a given degree, smoothness, and domain partition. All the spline functions of a given degree can be expressed as a linear combination of B-splines.

![b-spline](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/b-spline.PNG)

4. Linear: Is a continuous function defined by linear polynomials. So, it's a continuous set of straight lines.

![linear](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/linear%20spline.PNG)

5. NURBS (Non-uniform rational B-Spline): This one is just a mathematical model using B-Splines, usually used in computer graphics for representing curves and surfaces. It gives a great flexibility and precision for handling both analytic and model shapes.

![nurbs](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/nurbs%20spline.PNG)

6. Catmull-Rom: A catmull-rom spline is a curve named like this because of his creators ([Edwin Catmull](https://en.wikipedia.org/wiki/Edwin_Catmull) and [Raphael Rom](https://es.wikipedia.org/w/index.php?title=Raphael_Rom&action=edit&redlink=1)). The main advantage of this techinque is that the original set of points are also part of the control points from the curve spline.

![catmull](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/catmull-rom%20spline.PNG)

### 3.2 Uses Of Splines
The splines are very used in a lot of areas, like I said [before](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#3-splines). But now, I'll take a look on a more specific area, Videogames:

In videogames, splines have some uses, but the main is creating paths for the enemies to follow. If you want a smooth motion, the path of the enemies should be continuous (just what splines offers). Other common use of splines in videogames is to design and then define the necessary experience needed to increse levels. Splines are also used in 3D and VR videogames, taking a great importance on camera views, in order to give a smooth camera movement in games where the camera used is the first person (First Person Shooter usually). Moreover, splines are used to create most smoother animations in videogames (also in animation films).
Here we have some graphic examples of what I have said on the previous lines:

![doom](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/doom%20eternal.gif)
Here, we can see how splines are used in Doom Eternal to give a smooth camera movement to the players.

![crash](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/crash.gif)
Here, splines are used to define the path the apples follow until they arrive to his destiny.


## 4. Improvements
## 5. References

