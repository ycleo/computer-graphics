# Deprecated -- no need to complete

**Note to students** This is the old lab just in case you want to learn about building your own math library from scratch.


# Lab - Math Foundations Library (Vector and Matrix)

<img align="right" width="300px" src="http://gamedevelopertips.com/wp-content/uploads/2017/11/image13-570x500.png">

> A linear algebra framework for graphics

**Lab materials must be pushed to your repository one week from now before the next class begins**

**Read:** *Labs are designed to be finished in class if you work diligently, but expected to take 1-2 hours outside of class. They are often more 'tutorial' in style, and sometimes the solution may even be provided in pieces for you to type in and experiment. Copying & Pasting is discouraged however--make mistakes, play, and you will further learn the material.*

# Logistics

You will be working on your laptop to implement part of a C++ math library with two custom data types [./include/Vector4f.h](./include/Vector4f.h) and [./include/Matrix4f.h](./include/Matrix4f.h).

# Resources to help

Some additional resources to help you through this assignment.

- [OpenFrameworks GLM Reference](https://openframeworks.cc/documentation/glm/)
	- A nice searchable GLM reference on the openFrameworks library
- Math Related
	1. [Handy Course on Vector and Matrix Math](http://chortle.ccsu.edu/vectorlessons/vectorIndex.html#10)
	2. [Dot Product better explained](https://betterexplained.com/articles/vector-calculus-understanding-the-dot-product/)


# Description

Building a custom math library is something I believe every graphics program should go through at least one time. At the very least, it is a good way to learn some more modern C++. Math libraries also make programmers think about optimization which would be important for your career later on. For this lab, we are going to build part of a math library, and also get introduced to a professional grade math library called [GLM](https://glm.g-truc.net/0.9.9/index.html).

# Part 1 - Designing a Custom Math Library in C++

Included in our repository is the [OpenGL Mathematics library (GLM)](https://glm.g-truc.net/0.9.9/index.html). It has been well tested and is designed for C++. So why build our own C++ Math Library? Here is why:

0. We need just a little more practice with C++.
	- Observing another library and implementing our own will do the trick!
1. Consistency
   - We can name our API as we need. Refactoring an open source library would take quite a bit of time.
2. Performance
   - By building the library ourselves, we can optimize as we need for the architecture we are developing on. We have the flexibility to implement a better algorithm for matrix multiply for example in the future.
	- Pragmatically will our library be as fast as something like GLM? Believe it or not, our library may actually be as fast or faster! GLM fully admits their library is designed for convenience in some spots as opposed to performance. 
	- Our library is much smaller and likely to compile faster because of the small amount of code we have (as we will omit features we do not need)!
3. Features
   - When you implement your own library, you have complete control over the features implemented. We control the destiny of this library much more easily!
4. Portability
   - We have the source, so any platform that supports C++ can use this library.
5. Education
   - As mentioned before, doing this once is good for the programmers soul.

### Further discussion

Further discussion by Sean Middleditch on developing [Custom Math Libraries](https://www.youtube.com/watch?v=v4Ubu7BMXXk) and why one would go through this process.

# Part 2 - C++ operators

In order make our math library easy to use([./include/Vector4f.h](./include/Vector4f.h) and [./include/Matrix4f.h](./include/Matrix4f.h)), we are going to overload several operators(i.e. `+,-,*,/`) for doing various vector and matrix operations. An example is provided below to show how to create a Vector2D and overload the `+` operator.

```cpp
// Compile with: g++ -std=c++11 operator.cpp -o operator
#include <iostream>

// Small example of C++ templates
struct Vector2D{
    // Member variables
    float x,y;
	
    // Constructor
    Vector2D(float _x, float _y):x(_x),y(_y){
    }    

};

// Here is an example of overloading the '+' operator.
// '+' itself is just a function--it may be helpful to think
// '+' as just a one character function name in this case.
// The 'const' property means we are not modifying a or b.
// Each of a and b are also passed by reference to avoid an
// additional copy.
Vector2D operator +(const Vector2D& a, const Vector2D& b){
    Vector2D result(0,0);
    
    result.x = a.x + b.x;    
    result.y = a.y + b.y;    

    return result;
}

int main(){

    Vector2D vec1(1,1);    
    Vector2D vec2(77,66);    
    // A new vector is returned as a result of '+' operations
    // and assigned to 'test'
    Vector2D test = vec1 + vec2;

    // Validate the results of our test operation.
    std::cout << "test is (" << test.x << "," << test.y << ")" << std::endl;

    return 0;
}
```

For another useful introduction see [functions 2](http://www.cplusplus.com/doc/tutorial/functions2/) and [Classes 2](http://www.cplusplus.com/doc/tutorial/templates/) which covers operators on the [cplusplus tutorial](http://www.cplusplus.com/doc/tutorial/).

### C++ Style Note

Generally for well-defined mathematical data structures like vector and matrix, it is a fine practice to overload the operators (`[],+,-,/,-=,+=,etc`). For other abstract data types, like a List, we generally prefer named functions like`.add` as opposed to overloading `+`.

# Part 3 - Implementing Vector4f.h and Matrix4f.h

From the code repository, you will see the function prototypes for the library. Understanding the fundamentals of math is important for computer graphics, and the exercise of building a library will help you practice your C++. The good news is that one good math library really only needs to be written once (Unless math changes...in which case we have bigger problems!).

## The Task

Implement the functions with 'TODO' in [./include/Vector4f.h](./include/Vector4f.h) and [./include/Matrix4f.h](./include/Matrix4f.h).

### Requirements

1. The one requirement is that there are NO loops in your code. While we do not have to be 100% efficient in this class, using loops to initialize our data is slower than initializing the data directly (You ask me to elaborate further on things like loop unrolling and data oriented design in the forums if you want more information.).

# Part 4 - Testing Vector4f.h and Matrix4f.h

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working math library implementation against another library--the GLM library. 

```cpp
// Create a 1-vector
bool unitTest1(){
  Vector4f a(1.0f,1.0f,1.0f,1.0f);
  
  if(a.x == 1.0f && a.y == 1.0f && a.z == 1.0f && a.w==1){
    return true;
  }
    return false;
}
```

I have provided at least 2 unit tests as samples in [./src/main.cpp](./src/main.cpp) that you may use to check if the math works. You may write additional unit tests to validate your work. I will be testing your library against the GLM library to ensure it works. A sample of the [GLM library documentation](https://glm.g-truc.net/0.9.2/api/a00001.html) is provided here which will be helpful for building more tests.


## How to run your program

Your solution should compile by typing in [python3 build.py](./build.py).

# Submission/Deliverables

### Submission

- Commit all of your files to github, including any additional files you create.
- Do not commit any binary files unless told to do so.
- Do not commit any 'data' files generated when executing a binary.

### Deliverables

- Implement [./include/Vector4f.h](./include/Vector4f.h) and [./include/Matrix4f.h](./include/Matrix4f.h).


# Going Further

What is that, you finished Early? Did you enjoy this assignment? Here are some (optional) ways to further this assignment.

- Implement the functions with the SIMD AVX Intrinsics (either AVX, AVX2, or AVX512).
- Implement more functions you think may be of use!
	- You may eventually implement the transformations.
- Implement Vector2f, Vector3f, and Matrix2f, and Matrix3f.
- Consider changing all of your classes and structures into templates.
  - [C++ Templates Tutorial](http://www.cplusplus.com/doc/oldtutorial/templates/)
  - For this course, we will however only need floating point precision for most of our work.

### Template code example

```cpp
// compile: clang++ -std=c++11 Vector2DTemplate.cpp -o example
// run: ./example
#include <iostream>

// Small example of C++ templates
template <class T>
struct Vector2D{
    T x,y;
	
    // Note that default gives us the compiler generated
    // constructor.
    // If we wanted to forbid this, we could use 'delete'
    // and force users to have to use our other constructor.
    Vector2D() = default;

	// Constructor for our 2D vector.
    Vector2D(T _x, T _y):x(_x),y(_y){
    }

};

int main(){

    // Notice here we 'instantiate' the type within the <>'s
    // This creates a Vector2D with the specified type 'T'.
    // The caveat is that our member functions should all work with
    // any given type.
    // If they do not--then you may have to explore template specialization
    // See: http://www.gotw.ca/gotw/049.htm
    // e.g. What would it mean to compute the dot product of two strings?
    // You might have a specialization that handles that(if it makes sense)
    // or otherwise rule that operation out.
    Vector2D<int> myVecInt(1,2);
    Vector2D<bool> myVecBool(true,false);

    return 0;
}
```

# F.A.Q. (Instructor Anticipated Questions)

- Q: Why are we not supporting operation X?
	- A: Add it! We will add as needed.
- Q: Can I add more tests?
	- A: Yes.
- Q: Can I use my own library instead of glm throughout the semester?
	- A: Yes

# Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

- Fun fact: The famous computer scientist Donald Knuth would pay folks one $2.56 for errors in his published works. [[source](https://en.wikipedia.org/wiki/Knuth_reward_check)]
- Unfortunately, there is no monetary reward in this course :)
