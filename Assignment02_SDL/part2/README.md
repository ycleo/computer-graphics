# GLM and C++

<img align="right" width="300px" src="http://gamedevelopertips.com/wp-content/uploads/2017/11/image13-570x500.png">

> A linear algebra framework for graphics

# Logistics

You will be learning about the GL Mathematics (GLM) library and reviewing a few C++ concepts.

# Resources to help

Some additional resources to help you through this assignment.

| SDL2 related links                                    | Description                       |
| --------------------------------------------------    | --------------------------------- |
| [SDL API Wiki](https://wiki.libsdl.org/APIByCategory) | Useful guide to all things SDL2   |
| [My SDL2 Youtube Playlist](https://www.youtube.com/playlist?list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0) | My Guide for using SDL2 in video form.   |
| [Lazy Foo](http://lazyfoo.net/tutorials/SDL/)         | Great page with written tutorials for learning SDL2. Helpful setup tutorials for each platform. |
| [Lazy Foo - Handling Key Presses](https://lazyfoo.net/tutorials/SDL/04_key_presses/index.php) | Useful tutorial for learning how to handle key presses | 

| OpenGL related links                                | Description                       |
| --------------------------------------------------  | --------------------------------- |
| [My OpenGL Youtube Series](https://www.youtube.com/playlist?list=PLvv0ScY6vfd9zlZkIIqGDeG5TUWswkMox) | My video series for learning OpenGL |
| [docs.gl](http://docs.gl)                           | Excellent documentation to search for OpenGL commands with examples and description of function parameters   |
| [learnopengl.com](https://learnopengl.com)          | OpenGL 3.3+ related tutorial and main free written resource for the course   |


| C++ related links                                   | Description                       |
| --------------------------------------------------  | --------------------------------- |
| [My C++ Youtube Series](https://www.youtube.com/playlist?list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L) | My video series playlist for learning C++ |
| [cppreference](https://en.cppreference.com/w/)      | Definitive, more encyclopedic guide to C++ (less beginner focused, but excellent technically) |
| [cplusplus.com](http://www.cplusplus.com)           | Nice website with examples and tutorials geared more for beginners, reference has lots of examples, and the tutorial page is a great starting point |
| [learncpp.com](https://www.learncpp.com/)           | Handy page for learning C++ in tutorial form   |


- GLM Related
 	- [OpenFrameworks GLM Reference](https://openframeworks.cc/documentation/glm/)
		- A nice searchable GLM reference on the openFrameworks library
	- [http://www.c-jump.com/bcc/common/Talk3/Math/GLM/GLM.html](http://www.c-jump.com/bcc/common/Talk3/Math/GLM/GLM.html)
		- Another tutorial with some examples of how to use the GLM library.
- Math Related
	1. [Handy Course on Vector and Matrix Math](http://chortle.ccsu.edu/vectorlessons/vectorIndex.html#10)
	2. [Dot Product better explained](https://betterexplained.com/articles/vector-calculus-understanding-the-dot-product/)


# Description

OpenGL version 3.3 and beyond requires us to use our own vector or matrix operations in order to perform transformations. Luckily, there are many good libraries to facilitate this so that we do not have to implementt everything from scratch. Some folks have developed the [GLM library](https://glm.g-truc.net/0.9.9/) (or [the github link](https://glm.g-truc.net/) ) which gives us a relatively comprehensive set of vectors and matrices classes with appropriate operations to work in 3D graphics. 

Provided below is a guide to some common GLM library operations you will be using. Note that most of the operations very closely map to the OpenGL Shading Language (GLSL) which we will also be using. Thus, we will use GLM in our code in our .cpp and .hpp files, and for our GPU programming where we write our shader programs, we use the native GLSL which has many built in functions and data structures that GLM provides us.

# Task 1 - GLM Cheat Sheet

## GLM Cheat Sheet

|**Types**   				|   		|
|---					|---		|
|`glm::vec3`   				| 3D Vector  	|
|`glm::mat4`   				| 4x4 Matrix  	|
|**Vector Methods**   			|   		|
|---   					|   		|
|`glm::vec3( float, float, float )`	   	|glm::vec3 Constructor			|
|`glm::vec4( float, float, float, float )`	|glm::vec4 Constructor   		|
|`glm::vec4( glm::vec3, 1. )`	   		|glm::vec3-to-glm::vec4 Constructor   	|
|`glm::vec3 = glm::vec3 + glm::vec3`	   	|Addition   				|
|`glm::vec3 = glm::vec3 - glm::vec3`	   	|Subtraction   				|
|`glm::vec3 glm::cross( glm::vec3, glm::vec3 )`	|Cross product  			|
|`float glm::dot( glm::vec3, glm::vec3 )`	|Dot product   				|
|`float glm::length( glm::vec3 )`	   	|Vector length   			|
|`glm::vec3 glm::normalize( glm::vec3 )`	|Unitize a glm::vector   		|
|`.x, .y, .z`	   				|Access individual elements   		|
|`[0], [1], [2]`	   			|Alternative way to access individual elements ([0]=x, [1]=y,[2]=z)	|
|**Matrix methods:**   				|   					|
|`glm::mat4( glm::vec4, glm::vec4, glm::vec4, glm::vec4)`   	|Constructor by columns |
|`glm::mat4 = glm::mat4 * glm::mat4`	   			|Multiply two matrices   		|
|`glm::vec4 = glm::mat4 * glm::vec4`	   			|Multiply vector and a matrix  		|
|`[c][r]`   							| Access specific element by column(c) and row(r)  	|
|`glm::mat4 glm::rotate( glm::mat4, float, glm::vec3 )`   	|Angle in radians, Axis of rotation specified as a vec3  		|
|`glm::mat4 glm::scale( glm::mat4, glm::vec3 )`	   		|x, y, and z scale factors   			|
|`glm::mat4 glm::translate( glm::mat4, glm::vec3 )`	   	|Translation amount   				|

### C++ Review -- Namespaces

With our new glm library, you are going to notice that things are organized into 'namespaces'. That is, you will see the library functions prefixed with 'glm::'. This means that the scope of our functions and data types are within the glm namespace. The purpose of this is to ensure that someone elses math library function names would not clash with this library.

In practice, it looks something like this:

```cpp

namespace glm{
	struct mat4{
		// ... implementation
	};

}

// Now we have to use mat4 as glm::mat4, because it is in the glm namespace.

Note: You can see the actual [mat4 type here](https://github.com/g-truc/glm/blob/master/glm/detail/type_mat4x4.hpp).

```

### GLM Helper Functions

Debugging your transformations can sometimes be tricky. A common error that folks will make is to assume that they have an identity matrix. The question is, how would we know? Well, we have to inspect our `mat4` type, and a nice way to do this is to print it out!

```cpp
// Helper Function to print out a matrix
// For this helper function it is okay to print out a loop for debugging purposes.
void
printMatrix( glm::glm::mat4 glm::mat ){
        for( int row = 0; row < 4; row++ ){
                fprintf( stderr, "  %7.2f %7.2f %7.2f %7.2f\n",
			glm::mat[0][row], glm::mat[1][row], glm::mat[2][row], glm::mat[3][row] );
        }
}
```

Note: You may also use `glm::to_string` to retrieve matrix values, but I prefer to output the actual values in a grid.

### GLM Gotcha's

If you're compiling with g++, you may need to add some #define statements before any of the glm headers to help *conditionally* compile the glm libraries. Unfortunately not all C++ compilers work the same way.

```c++
    #define GLM_FORCE_PURE                                                             
    #define GLM_FORCE_SWIZZLE
```
## Exercises

It's worth looking at the GLM library to learn a little more about how it was implemented. It is also worth taking some time to make sure we understand the C++. Your deliverable for this assignment is to fill in the [exercise.md](./exercise.md) file with some C++ and GLM questions.

## How to run your program

- N/A

# Submission/Deliverables

### Submission

- Commit all of your files to github, including any additional files you create.
- Do not commit any binary files unless told to do so.
- Do not commit any 'data' files generated when executing a binary.

### Deliverables

- Fill in the [exercise.md](./exercise.md) file

# Going Further

What is that, you finished Early? Did you enjoy this assignment? Here are some (optional) ways to further this assignment.

- N/A

# F.A.Q. (Instructor Anticipated Questions)

- Q: Can I use my own library instead of glm throughout the semester?
	- A: Yes, and it's actually a great exericse.
	- Fair warning that you should make sure your library is well tested!

# Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this assignment, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

- Fun fact: The famous computer scientist Donald Knuth would pay folks one $2.56 for errors in his published works. [[source](https://en.wikipedia.org/wiki/Knuth_reward_check)]
- Unfortunately, there is no monetary reward in this course :)
