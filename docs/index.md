# Easings and Splines for UI Animations
## Index
1. Introduction and goals

2. Easings

      2.1. Types of Easings
   
      2.2. Uses of Easings
   
      2.3. How does it work
   
      2.4. Easing Functions

3. Splines

      3.1. Types of Splines
   
      3.2. Uses of Splines

4. Improvements

5. Pros and Cons

6. Conclusion

7. References

## 1. Introduction and goals
I'm [Adrián Aroca](https://www.linkedin.com/in/adri%C3%A1n-aroca-mascaraque-4570001a2/), a student of the [Bachelor's Degree in Design and Develpment of Videogames at CITM (UPC)](https://www.citm.upc.edu/). This is my personal research for the subject "Project 2" which is given by [Ramon Santamaria](https://www.linkedin.com/in/raysan/), the main developer of [Raylib](https://www.raylib.com/).

My main goal in this research is creating a C++ library that let my class mates create his own animations based on easings and splines for their videogames, as easily as possible. Then, I must do a presentation where I will explain all the content i have prepared, in order to everyone can understand what an easing and spline is, and how they work. Moreover, I need to implement a soulution where I will show how I implemented all the easings types in a Visual Studio project. On this project, I will be able to move a player with any Easing type.

## 2. Easings
There is no object in real life that just start and stop instantly, and almost never move at constant speed. For example, when you drop a ball from your arms, it first gains velocity (accelerate downwards), and then bounce back up after hitting the floor (accelerate upwards). This is what easings are, and this is what i will explain here.
Implementing animations that describes movements of this type frame by frame, would be a nightmare. But, luckyly, there are mathematical functions that can be implemented by coders. And this is something that can diminish the amount of work of animators. Moreover, with that functions, the results obtained will be much more smooth. In the case of the bouncing ball, instead of coding the amount of distance it needs to travel each frame, using easings, you can just give the ball a speed depending on the distance from his objective position.

All the easing functions depends on four parameters:

- Current time (t) which is the moment where the object is.
- Begginning position (b) which is the position the object have at time "t".
- Change in distance (c) which is the difference of distance between the beggining position and the final one (f-b).
- Duration (d) that represent the amount of total iterations you want for complete your animation.

<p align="left">
   <img src="images/bouncing_ball.gif">
</p>

### 2.1 Types Of Easings
There are some different types of easings, which can be sorted like that:

First of all, there are 3 easings types:
   1. Ease in: This type of easing, describes the movement of an object with POSITIVE acceleration.
   2. Ease Out: This type of easing, describes the movement of an object with NEGATIVE acceleration.
   3. Mixed: This one, mixes the both previous types (Usually describes a positive acceleration first, and then a negative one).
   
<p align="center">
   <img src="images/types%20of%20easings.png">
</p>

That 3 types were the biggest types of easing, the most global ones. But, there is a lot of specific functions you can use to describe movements based on easings. 

- Standard Functions (Uses pows from 1-6)

  1.Linear: Using a pow of 1, it describes a linear movement with no acceleration (constant speed).
 
  2.Quad: Describes a movement accelerated, where the speed is increased by a pow of 2.
  
  3.Cubic: Describes a movement accelerated, where the speed is increased by a pow of 3.
  
  4.Quart: Describes a movement accelerated, where the speed is increased by a pow of 4.
  
  5.Quint or Strong: Describes a movement accelerated, where the speed is increased by a pow of 5.
   
  6.Circular: Describes a movement accelerated, where the speed is increased by a pow of 6.
   
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
   <img src="images/easing%20usability.gif">
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
   <img src="images/ease%20out%20example.gif">
</p>

### 2.4 Easing Functions 



- Back Ease In

    		float Easing::backEaseIn(float t, float b, float c, float d)
    		{
	   	 	float s = 1.70158f;
	   	 	float aux = t /= d;
	   	 	return c * (aux)*t * ((s + 1) * t - s) + b;
    		}

   
<p align="center">
   <img src="images/Easings/easeInBack.PNG">
</p>

- Back Ease Out

		float Easing::backEaseOut(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			return c * ((t = t / d - 1) * t * ((s + 1) * t + s) + 1) + b;
		}

<p align="center">
   <img src="images/Easings/easeOutBack.PNG">
</p>

- Back Ease In/Out

		float Easing::backEaseInOut(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			if ((t /= d / 2) < 1) return c / 2 * (t * t * (((s *= (1.525f)) + 1) * t - s)) + b;
			float aux = t -= 2;
			return c / 2 * ((aux)*t * (((s *= (1.525f)) + 1) * t + s) + 2) + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutBack.PNG">
</p>

- Bounce Ease In

		float Easing::bounceEaseIn(float t, float b, float c, float d)
		{
			return c - bounceEaseOut(d - t, 0, c, d) + b;
		}

<p align="center">
   <img src="images/Easings/easeInBounce.PNG">
</p>

- Bounce Ease Out

		float Easing::bounceEaseOut(float t, float b, float c, float d)
		{
			if ((t /= d) < (1 / 2.75f)) {
				return c * (7.5625f * t * t) + b;
			}
			else if (t < (2 / 2.75f)) {
				float aux = t -= (1.5f / 2.75f);
				return c * (7.5625f * (aux)*t + .75f) + b;
			}
			else if (t < (2.5 / 2.75)) {
				float aux = t -= (2.25f / 2.75f);
				return c * (7.5625f * (aux)*t + .9375f) + b;
			}
			else {
				float aux = t -= (2.625f / 2.75f);
				return c * (7.5625f * (aux)*t + .984375f) + b;
			}
		}
		
<p align="center">
   <img src="images/Easings/easeOutBounce.PNG">
</p>

- Bounce Ease In/Out

		float Easing::bounceEaseInOut(float t, float b, float c, float d)
		{
			if (t < d / 2) return bounceEaseIn(t * 2, 0, c, d) * .5f + b;
			else return bounceEaseOut(t * 2 - d, 0, c, d) * .5f + c * .5f + b;
		}
		
<p align="center">
   <img src="images/Easings/easeInOutBounce.PNG">
</p>

- Circular Ease In

		float Easing::circularEaseIn(float t, float b, float c, float d)
		{
			return -c * (sqrt(1 - (t /= d) * t) - 1) + b;
		}
		
<p align="center">
   <img src="images/Easings/easeInCirc.PNG">
</p>

- Circular Ease Out

		float Easing::circularEaseOut(float t, float b, float c, float d)
		{
			return c * sqrt(1 - (t = t / d - 1) * t) + b;
		}
		
<p align="center">
   <img src="images/Easings/easeOutCirc.PNG">
</p>

- Circular Ease In/Out

		float Easing::circularEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return -c / 2 * (sqrt(1 - t * t) - 1) + b;
			return c / 2 * (sqrt(1 - t * (t -= 2)) + 1) + b;
		}
		
<p align="center">
   <img src="images/Easings/easeInOutCirc.PNG">
</p>

- Cubic Ease In

		float Easing::cubicEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t * t + b;
		}

<p align="center">
   <img src="images/Easings/easeInCubic.PNG">
</p>

- Cubic Ease Out

		float Easing::cubicEaseOut(float t, float b, float c, float d)
		{
			return c * ((t = t / d - 1) * t * t + 1) + b;
		}

<p align="center">
   <img src="images/Easings/easeOutCubic.PNG">
</p>

- Cubic Ease In/Out

		float Easing::cubicEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t * t * t + b;
			return c / 2 * ((t -= 2) * t * t + 2) + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutCubic.PNG">
</p>

- Elastic Ease In

		float Easing::elasticEaseIn(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d * .3f;
			float a = c;
			float s = p / 4;
			float aux = a * pow(2, 10 * (t -= 1));
			return -(aux * sin((t * d - s) * (2 * PI) / p)) + b;
		}

<p align="center">
   <img src="images/Easings/easeInElastic.PNG">
</p>

- Elastic Ease Out

		float Easing::elasticEaseOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d * .3f;
			float a = c;
			float s = p / 4;
			return (a * pow(2, -10 * t) * sin((t * d - s) * (2 * PI) / p) + c + b);
		}

<p align="center">
   <img src="images/Easings/easeOutElastic.PNG">
</p>

- Elastic Ease In/Out

		float Easing::elasticEaseInOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d / 2) == 2) return b + c;
			float p = d * (.3f * 1.5f);
			float a = c;
			float s = p / 4;

			if (t < 1)
			{
				float aux = a * pow(2, 10 * (t -= 1));
				return -.5f * (aux * sin((t * d - s) * (2 * PI) / p)) + b;
			}
			float aux = a * pow(2, -10 * (t -= 1));
			return aux * sin((t * d - s) * (2 * PI) / p) * .5f + c + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutElastic.PNG">
</p>

- Exponential Ease In

		float Easing::exponentialEaseIn(float t, float b, float c, float d)
		{
			return (t == 0) ? b : c * pow(2, 10 * (t / d - 1)) + b;
		}	

<p align="center">
   <img src="images/Easings/easeInExpo.PNG">
</p>

- Exponential Ease Out

		float Easing::exponentialEaseOut(float t, float b, float c, float d)
		{
			return (t == d) ? b + c : c * (-pow(2, -10 * t / d) + 1) + b;
		}

<p align="center">
   <img src="images/Easings/easeOutExpo.PNG">
</p>

- Exponential Ease In/Out

		float Easing::exponentialEaseInOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;
			if (t == d) return b + c;
			if ((t /= d / 2) < 1) return c / 2 * pow(2, 10 * (t - 1)) + b;
			return c / 2 * (-pow(2, -10 * --t) + 2) + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutExpo.PNG">
</p>

- Linear Ease

		float Easing::linearEaseNone(float t, float b, float c, float d)
		{
			return c * t / d + b;
		}

<p align="center">
   <img src="images/Easings/linearEase.PNG">
</p>

- Quad Ease In

		float Easing::quadEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t + b;
		}

<p align="center">
   <img src="images/Easings/easiInQuad.PNG">
</p>

- Quad Ease Out

		float Easing::quadEaseOut(float t, float b, float c, float d)
		{
			return -c * (t /= d) * (t - 2) + b;
		}

<p align="center">
   <img src="images/Easings/easeOutQuad.PNG">
</p>

- Quad Ease In/Out

		float Easing::quadEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return ((c / 2) * (t * t)) + b;
			return -c / 2 * (((t - 2) * (--t)) - 1) + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutQuad.PNG">
</p>

- Quart Ease In

		float Easing::quartEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t * t * t + b;
		}

<p align="center">
   <img src="images/Easings/easeInQuart.PNG">
</p>

- Quart Ease Out

		float Easing::quartEaseOut(float t, float b, float c, float d)
		{
			return -c * ((t = t / d - 1) * t * t * t - 1) + b;
		}

<p align="center">
   <img src="images/Easings/easeOutQuart.PNG">
</p>

- Quart Ease In/Out

		float Easing::quartEaseInOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t * t * t * t + b;
			return -c / 2 * ((t -= 2) * t * t * t - 2) + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutQuart.PNG">
</p>

- Quint Ease In

		float Easing::quintEaseIn(float t, float b, float c, float d)
		{
			return c * (t /= d) * t * t * t * t + b;
		}

<p align="center">
   <img src="images/Easings/easeInQuint.PNG">
</p>

- Quint Ease Out

		float Easing::quintEaseOut(float t, float b, float c, float d)
		{
			return c * ((t = t / d - 1) * t * t * t * t + 1) + b;
		}

<p align="center">
   <img src="images/Easings/easeOutQuint.PNG">
</p>

- Quint Ease In/Out

		float Easing::quintEaseInOut(float t, float b, float c, float d) 
		{
			if ((t /= d / 2) < 1) return c / 2 * t * t * t * t * t + b;
			return c / 2 * ((t -= 2) * t * t * t * t + 2) + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutQuint.PNG">
</p>

- Sine Ease In

		float Easing::sineEaseIn(float t, float b, float c, float d)
		{
			return -c * cos(t / d * (PI / 2)) + c + b;
		}

<p align="center">
   <img src="images/Easings/easeInSine.PNG">
</p>

- Sine Ease Out

		float Easing::sineEaseOut(float t, float b, float c, float d)
		{
			return c * sin(t / d * (PI / 2)) + b;
		}

<p align="center">
   <img src="images/Easings/easeOutSine.PNG">
</p>

- Sine Ease In/Out 

		float Easing::sineEaseInOut(float t, float b, float c, float d)
		{
			return -c / 2 * (cos(PI * t / d) - 1) + b;
		}

<p align="center">
   <img src="images/Easings/easeInOutSine.PNG">
</p>

## 3. Splines
In *maths* area, a spline is a function defined piece by piece, by polynomials. In interpolating problems, spline interpolation is usually preferred over polynomial interpolation because it performs practically the same, even using low degree polynomials, while avoiding [Runge's phenomenon](https://en.wikipedia.org/wiki/Runge%27s_phenomenon) for higher degrees.

In *computer science*, when you talk about splines, you're talking about a piecewise polynomial curve. Splines are popular curves on this field because of the simplicity of their construction, their ease and accuracy of evaluation, and their capacity to approximate complex shapes through curve fitting and interactive curve design.

Now, let's see it from the field we're interested on, the Animation. Here, a spline is another method for creating animations on an easy way. Using splines, you will be able to create smooth animations just moving curves on a graph. So, using splines, you can do your work easyly, saving your time and effort.

There are some different types of splines, let's see them.
### 3.1 Types Of Splines
- Bezier: Is just a spline defined "point by point", by different Bezier curves.

<p align="center">
   <img src="images/bezier.PNG">
</p>

- Cubic: This one gives an interpolation polynomial that is smoother and has less error than some other interpolating polynomials. It's used to avoid the problem of Runge's phenomenon.

<p align="center">
   <img src="images/cubic%20spline.PNG">
</p>

- B-Spline: Is a spline function that has minimal support with respect to a given degree, smoothness, and domain partition. All the spline functions of a given degree can be expressed as a linear combination of B-splines.

<p align="center">
   <img src="images/b-spline.PNG">
</p>

- Linear: Is a continuous function defined by linear polynomials. So, it's a continuous set of straight lines.

<p align="center">
   <img src="images/linear%20spline.PNG">
</p>

- NURBS (Non-uniform rational B-Spline): This one is just a mathematical model using B-Splines, usually used in computer graphics for representing curves and surfaces. It gives a great flexibility and precision for handling both analytic and model shapes.

<p align="center">
   <img src="images/nurbs%20spline.PNG">
</p>

- Catmull-Rom: A catmull-rom spline is a curve named like this because of his creators ([Edwin Catmull](https://en.wikipedia.org/wiki/Edwin_Catmull) and [Raphael Rom](https://es.wikipedia.org/w/index.php?title=Raphael_Rom&action=edit&redlink=1)). The main advantage of this techinque is that the original set of points are also part of the control points from the curve spline.

<p align="center">
   <img src="images/catmull-rom%20spline.PNG">
</p>

### 3.2 Uses Of Splines
The splines are very used in a lot of areas, like I said before. But now, I'll take a look on a more specific area, Videogames:

In videogames, splines have some uses, but the main is creating paths for the enemies to follow. If you want a smooth motion, the path of the enemies should be continuous (just what splines offers). Other common use of splines in videogames is to design and then define the necessary experience needed to increse levels. Splines are also used in 3D and VR videogames, taking a great importance on camera views, in order to give a smooth camera movement in games where the camera used is the first person (First Person Shooter usually). Moreover, splines are used to create most smoother animations in videogames (also in animation films).
Here we have some graphic examples of what I have said on the previous lines:

<p align="left">
   <img src="images/doom%20eternal.gif">
</p>

Here, we can see how splines are used in "[Doom Eternal](https://en.wikipedia.org/wiki/Doom_Eternal)" to give a smooth camera movement to the players.

<p align="left">
   <img src="images/crash.gif">
</p>

On "[Crash Bandiccot: N.Sane Trilogy](https://en.wikipedia.org/wiki/Crash_Bandicoot_N._Sane_Trilogy)", splines are used to define the path the apples follow until they arrive to his destiny.


## 4. Improvements
I feel that the main goal I wanted to achieve is done. I created a C++ Library that let to all the developers who want to use it, implement all the different types of easings, moreover on an easy way. But, despite all, I would like to remark some points that could improve the work I did.

1. Having a code even more polished, and easier to understand.
2. I would have liked that the Library were defined as a static library, instead creating a source and a header file.
3. I created a enum class that stored the easing type (cubic,bounce,linear,etc...), but when I tried to use it, the game crashes, so I created that class, but it's useless and I had to create extra variables in order to store the easing type I wanted. 
4. May be it would be possible to create just a few functions (instead the 33 that I've created), that recieving the easing type as parameter, this function reproduce the easing you want.

<p align="center">
	<img src="images/improvements.jpg">
</p>

## 5. Pros and Cons
The use of easings in videogames can make your work as developer easier in a lot of ways, and it's hard for me saying a lot of disadvantage about using easings on videogames development. But, I'll try to say something bad about them.

- PROS

     1.Easings makes you saving a lot of time and effort.
     
     2.Easings are easy to understand, easy to implement in your code and easy to use them.

     3.Easings let the developer create smooth movements or animations quickly and easily.  
     
     4.Easings also are useful to create camera movements smoother, to create paths, and to create dynamic UI that looks so cool. 
     

- CONS

     1.The maths you must know to create all the easing functions could be difficult for some people.
     
     2.The library requires implementing 33 functions, and it's a lot of work.
     
     
     
     <p align="center">
	<img src="images/pros%20and%20cons.png">
     </p>
        
## 6. Conclusion
In conclusion, I think that easings and splines are fabulous to any videogames developer. Like i said before a lot of times, they let you make paths, animations, smooth movements, etc... 

Without using easings, this work would be slow, heavy and harder. But using them, you will be able to achieve great results (better than if you don't use them). Moreover, that results will be achieved so much sooner and easily. So, I highly recommend everyone using my C++ Easings Library (or others), and then you will understand why easings and splines like me so much.

I'm glad of the results I've obtained after a lot of hours of work, and I must say that the area of splines is very interesting (more than what I expected), and I  hope that you find this research as useful as I have found.

## 7. References
[https://medium.com/motion-in-interaction/animation-principles-in-ui-design-understanding-easing-bea05243fe3](https://medium.com/motion-in-interaction/animation-principles-in-ui-design-understanding-easing-bea05243fe3)

[https://easings.net/](https://easings.net/)

[http://robertpenner.com/easing/](http://robertpenner.com/easing/)

[https://github.com/raysan5/raylib/blob/master/src/easings.h](https://github.com/raysan5/raylib/blob/master/src/easings.h)

[https://github.com/marcgreig/Easing-and-Splines-Research](https://github.com/marcgreig/Easing-and-Splines-Research)

[http://www.animschoolblog.com/2017/07/stepped-or-spline.html](http://www.animschoolblog.com/2017/07/stepped-or-spline.html)

[http://euklid.mi.uni-koeln.de/c/mirror/www.cs.curtin.edu.au/units/cg351-551/notes/lect6c1.html](http://euklid.mi.uni-koeln.de/c/mirror/www.cs.curtin.edu.au/units/cg351-551/notes/lect6c1.html)

