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

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/bouncing_ball.gif">
</p>

### 2.1 Types Of Easings
There are some different types of easings, which can be sorted like that:

First of all, there are 3 easings types:
   1. Ease in: This type of easing, describes the movement of an object with POSITIVE acceleration.
   2. Ease Out: This type of easing, describes the movement of an object with NEGATIVE acceleration.
   3. Mixed: This one, mixes the both previous types (Usually describes a positive acceleration first, and then a negative one).
   
<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/types%20of%20easings.png">
</p>

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

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/easing%20usability.gif">
</p>

### 2.3 How Does It Work
Now, I'll explain how splines work in our area, and how to manage them in our project.

Imagine that we have a player and we want to move it by using splines. For example, back splines. We will have the following function:

    float position = backEaseIn(currentIteration,initialPosition,deltaPosition,totalIterations);

Our game run at 60 fps and we want that the player movement takes a total amount of 7 seconds, so our totalIterations number will be calculated like this (60 fps * 7 sec = 420 totalIterations). Now we have the totalIterations we'll need. But we also need to know on each moment which is our current iteration, and we will store that value in "currentIteration", which starts in zero and each frame it increase one unit, until currentIteration is equal to totalIterations.
    
    float totalIterations = 420;

    float currentIteration = 0;

    float position = backEaseIn(currentIteration,initialPosition,deltaPosition,totalIterations);

    ++currentIteration;
    
Once we know the total iterations and the current iteration, we must decide which will be the initial position, and the delta position (finalPos - initialPos). In our case, let's suppose that the initial position value is "initialPosition = 0", and that we desire moving 500 pixels.

    float totalIterations = 420;

    float currentIteration = 0;

    float initialPosition = 0;

    float deltaPosition = 500;



    float position = backEaseIn(currentIteration,initialPosition,deltaPosition,totalIterations);

    ++currentIteration;
    


Right now, this function will return the speed the player needs at each frame to arrive from initialPosition, until finalPosition.

When the path ends, we must reset the number of currentIterations and a bool variable to manage if the easing are activated or not. We must do it because if not, the movement could be infinite. The code will looks more or less like this:

    bool easingActivated = false;

    totalIterations = 420;

    currentIteration = 0;

    initialPosition = 0;

    deltaPosition = 500;


    if (app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
    {

        currentIteration = 0;
    
        position = 0;
    
        easingActivated = true;
    
    }

    if (easingActivated = true)
    {
        position = backEaseIn(currentIteration, initialPosition, deltaPosition, totalIterations);
    }

    if (currentIteration < totalIterations)
    {
        ++currentIteration;
    }

    else
    {
        currentIteration = 0;
    
        easingActivated = false;
    }

This code, should be enough to perform a backEaseIn. But if you want to implement other easing type, is exactly the same, but changing the function you use. For example, if you need to use a exponentialEaseOut, you will just change the name of the function, keeping all the other variables like before.

Video Example of a Golem moving using a backEaseOut (The Hunter Odyssey):

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/ease%20out%20example.gif">
</p>
### 2.4 Easing Functions 



1. Back Ease In

    		float Easing::backEaseIn(float t, float b, float c, float d)
    		{
	   	 float s = 1.70158f;
	   	 float postFix = t /= d;
	   	 return c * (postFix)*t * ((s + 1) * t - s) + b;
    		}

   
<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInBack.PNG">
</p>

2. Back Ease Out

		float Easing::backEaseOut(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			return c * ((t = t / d - 1) * t * ((s + 1) * t + s) + 1) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutBack.PNG">
</p>

3. Back Ease In/Out

		float Easing::backEaseInOut(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			if ((t /= d / 2) < 1) return c / 2 * (t * t * (((s *= (1.525f)) + 1) * t - s)) + b;
			float postFix = t -= 2;
			return c / 2 * ((postFix)*t * (((s *= (1.525f)) + 1) * t + s) + 2) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutBack.PNG">
</p>

4. Bounce Ease In

		float Easing::bounceEaseIn(float t, float b, float c, float d)
		{
			return c - bounceEaseOut(d - t, 0, c, d) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInBounce.PNG">
</p>

5. Bounce Ease Out

		float Easing::bounceEaseOut(float t, float b, float c, float d)
		{
			if ((t /= d) < (1 / 2.75f)) {
				return c * (7.5625f * t * t) + b;
			}
			else if (t < (2 / 2.75f)) {
				float postFix = t -= (1.5f / 2.75f);
				return c * (7.5625f * (postFix)*t + .75f) + b;
			}
			else if (t < (2.5 / 2.75)) {
				float postFix = t -= (2.25f / 2.75f);
				return c * (7.5625f * (postFix)*t + .9375f) + b;
			}
			else {
				float postFix = t -= (2.625f / 2.75f);
				return c * (7.5625f * (postFix)*t + .984375f) + b;
			}
		}
		
<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutBounce.PNG">
</p>

6. Bounce Ease In/Out

		float Easing::bounceEaseInOut(float t, float b, float c, float d)
		{
			if (t < d / 2) return bounceEaseIn(t * 2, 0, c, d) * .5f + b;
			else return bounceEaseOut(t * 2 - d, 0, c, d) * .5f + c * .5f + b;
		}
		
<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutBounce.PNG">
</p>

7. Circular Ease In

		float Easing::circularEaseIn(float t, float b, float c, float d)
		{
			return -c * (sqrt(1 - (t /= d) * t) - 1) + b;
		}
		
<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInCirc.PNG">
</p>

8. Circular Ease Out

		float Easing::circularEaseOut(float t, float b, float c, float d)
		{
			return c * sqrt(1 - (t = t / d - 1) * t) + b;
		}
		
<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutCirc.PNG">
</p>

9. Circular Ease In/Out

		float Easing::circularEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return -c / 2 * (sqrt(1 - t * t) - 1) + b;
			return c / 2 * (sqrt(1 - t * (t -= 2)) + 1) + b;
		}
		
<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutCirc.PNG">
</p>

10. Cubic Ease In

		float Easing::cubicEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t * t + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInCubic.PNG">
</p>

11. Cubic Ease Out

		float Easing::cubicEaseOut(float t, float b, float c, float d)
		{
			return c * ((t = t / d - 1) * t * t + 1) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutCubic.PNG">
</p>

12. Cubic Ease In/Out

		float Easing::cubicEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t * t * t + b;
			return c / 2 * ((t -= 2) * t * t + 2) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutCubic.PNG">
</p>

13. Elastic Ease In

		float Easing::elasticEaseIn(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d * .3f;
			float a = c;
			float s = p / 4;
			float postFix = a * pow(2, 10 * (t -= 1));
			return -(postFix * sin((t * d - s) * (2 * PI) / p)) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInElastic.PNG">
</p>

14. Elastic Ease Out

		float Easing::elasticEaseOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d * .3f;
			float a = c;
			float s = p / 4;
			return (a * pow(2, -10 * t) * sin((t * d - s) * (2 * PI) / p) + c + b);
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutElastic.PNG">
</p>

15. Elastic Ease In/Out

		float Easing::elasticEaseInOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d / 2) == 2) return b + c;
			float p = d * (.3f * 1.5f);
			float a = c;
			float s = p / 4;

			if (t < 1)
			{
				float postFix = a * pow(2, 10 * (t -= 1));
				return -.5f * (postFix * sin((t * d - s) * (2 * PI) / p)) + b;
			}
			float postFix = a * pow(2, -10 * (t -= 1));
			return postFix * sin((t * d - s) * (2 * PI) / p) * .5f + c + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutElastic.PNG">
</p>

16. Exponential Ease In

		float Easing::exponentialEaseIn(float t, float b, float c, float d)
		{
			return (t == 0) ? b : c * pow(2, 10 * (t / d - 1)) + b;
		}	

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInExpo.PNG">
</p>

17. Exponential Ease Out

		float Easing::exponentialEaseOut(float t, float b, float c, float d)
		{
			return (t == d) ? b + c : c * (-pow(2, -10 * t / d) + 1) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutExpo.PNG">
</p>

18. Exponential Ease In/Out

		float Easing::exponentialEaseInOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;
			if (t == d) return b + c;
			if ((t /= d / 2) < 1) return c / 2 * pow(2, 10 * (t - 1)) + b;
			return c / 2 * (-pow(2, -10 * --t) + 2) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutExpo.PNG">
</p>

19. Linear Ease

		float Easing::linearEaseNone(float t, float b, float c, float d)
		{
			return c * t / d + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/linearEase.PNG">
</p>

20. Quad Ease In

		float Easing::quadEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easiInQuad.PNG">
</p>

21. Quad Ease Out

		float Easing::quadEaseOut(float t, float b, float c, float d)
		{
			return -c * (t /= d) * (t - 2) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutQuad.PNG">
</p>

22. Quad Ease In/Out

		float Easing::quadEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return ((c / 2) * (t * t)) + b;
			return -c / 2 * (((t - 2) * (--t)) - 1) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutQuad.PNG">
</p>

23. Quart Ease In

		float Easing::quartEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t * t * t + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInQuart.PNG">
</p>

24. Quart Ease Out

		float Easing::quartEaseOut(float t, float b, float c, float d)
		{
			return -c * ((t = t / d - 1) * t * t * t - 1) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutQuart.PNG">
</p>

25. Quart Ease In/Out

		float Easing::quartEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t * t * t * t + b;
			return -c / 2 * ((t -= 2) * t * t * t - 2) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutQuart.PNG">
</p>

26. Quint Ease In

		float Easing::quintEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t * t * t * t + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInQuint.PNG">
</p>

27. Quint Ease Out

		float Easing::quintEaseOut(float t, float b, float c, float d)
		{
			return c * ((t = t / d - 1) * t * t * t * t + 1) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutQuint.PNG">
</p>

28. Quint Ease In/Out

		float Easing::quintEaseInOut(float t, float b, float c, float d) 
		{
			if ((t /= d / 2) < 1) return c / 2 * t * t * t * t * t + b;
			return c / 2 * ((t -= 2) * t * t * t * t + 2) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutQuint.PNG">
</p>

29. Sine Ease In

		float Easing::sineEaseIn(float t, float b, float c, float d)
		{
			return -c * cos(t / d * (PI / 2)) + c + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInSine.PNG">
</p>

30. Sine Ease Out

		float Easing::sineEaseOut(float t, float b, float c, float d)
		{
			return c * sin(t / d * (PI / 2)) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeOutSine.PNG">
</p>

31. Sine Ease In/Out 

		float Easing::sineEaseInOut(float t, float b, float c, float d)
		{
			return -c / 2 * (cos(PI * t / d) - 1) + b;
		}

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/Easings/easeInOutSine.PNG">
</p>

## 3. Splines
In *maths* area, a spline is a function defined piece by piece, by polynomials. In interpolating problems, spline interpolation is usually preferred over polynomial interpolation because it performs practically the same, even using low degree polynomials, while avoiding [Runge's phenomenon](https://en.wikipedia.org/wiki/Runge%27s_phenomenon) for higher degrees.

In *computer science*, when you talk about splines, you're talking about a piecewise polynomial curve. Splines are popular curves on this field because of the simplicity of their construction, their ease and accuracy of evaluation, and their capacity to approximate complex shapes through curve fitting and interactive curve design.

Now, let's see it from the field we're interested on, the Animation. Here, a spline is another method for creating animations on an easy way. Using splines, you will be able to create smooth animations just moving curves on a graph. So, using splines, you can do your work easyly, saving your time and effort.

There are some different types of splines, let's see them.
### 3.1 Types Of Splines
1. Bezier: Is just a spline defined "point by point", by different Bezier curves.

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/bezier.PNG">
</p>

2. Cubic: This one gives an interpolation polynomial that is smoother and has less error than some other interpolating polynomials. It's used to avoid the problem of Runge's phenomenon.

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/cubic%20spline.PNG">
</p>

3. B-Spline: Is a spline function that has minimal support with respect to a given degree, smoothness, and domain partition. All the spline functions of a given degree can be expressed as a linear combination of B-splines.

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/b-spline.PNG">
</p>

4. Linear: Is a continuous function defined by linear polynomials. So, it's a continuous set of straight lines.

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/linear%20spline.PNG">
</p>

5. NURBS (Non-uniform rational B-Spline): This one is just a mathematical model using B-Splines, usually used in computer graphics for representing curves and surfaces. It gives a great flexibility and precision for handling both analytic and model shapes.

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/nurbs%20spline.PNG">
</p>

6. Catmull-Rom: A catmull-rom spline is a curve named like this because of his creators ([Edwin Catmull](https://en.wikipedia.org/wiki/Edwin_Catmull) and [Raphael Rom](https://es.wikipedia.org/w/index.php?title=Raphael_Rom&action=edit&redlink=1)). The main advantage of this techinque is that the original set of points are also part of the control points from the curve spline.

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/catmull-rom%20spline.PNG">
</p>

### 3.2 Uses Of Splines
The splines are very used in a lot of areas, like I said [before](https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations#3-splines). But now, I'll take a look on a more specific area, Videogames:

In videogames, splines have some uses, but the main is creating paths for the enemies to follow. If you want a smooth motion, the path of the enemies should be continuous (just what splines offers). Other common use of splines in videogames is to design and then define the necessary experience needed to increse levels. Splines are also used in 3D and VR videogames, taking a great importance on camera views, in order to give a smooth camera movement in games where the camera used is the first person (First Person Shooter usually). Moreover, splines are used to create most smoother animations in videogames (also in animation films).
Here we have some graphic examples of what I have said on the previous lines:

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/doom%20eternal.gif">
</p>

Here, we can see how splines are used in "[Doom Eternal](https://en.wikipedia.org/wiki/Doom_Eternal)" to give a smooth camera movement to the players.

<p align="center">
   <img src="https://github.com/adrianam4/Easings-and-Splines-for-UI-Animations/blob/main/docs/crash.gif">
</p>

On "[Crash Bandiccot: N.Sane Trilogy](https://en.wikipedia.org/wiki/Crash_Bandicoot_N._Sane_Trilogy)", splines are used to define the path the apples follow until they arrive to his destiny.


## 4. Improvements
## 5. References

