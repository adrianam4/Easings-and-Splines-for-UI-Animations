# Easings and Splines for UI Animations
[1. Introduction and goals](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/README.md#1-introduction-and-goals)
[2. Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#2-easings)
    [2.1. Types of Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#21-types-of-easings)
    [2.2. Uses of Easings](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#22-uses-of-easings)
    [2.3. How does it work](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#23-how-does-it-work)
    [2.4. Easing Functions](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#24-easing-functions)
[3. Splines](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#3-splines)
    [3.1. Uses of Splines](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#31-uses-of-splines)
[4. Improvements](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#4-improvements)
[5. References](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#5-references)

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
### 2.2 Uses of Easings
### 2.3 How Does It Work
### 2.4 Easing Functions 
## 3. Splines
### 3.1 Uses Of Splines
## 4. Improvements
## 5. References

