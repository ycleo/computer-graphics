# Part 2 - Modern C++ Exercises

## Implementation Logistics

- You may use whatever operating system, IDE, or tools for completing this lab/assignment.
	- However, my instructions will usually be using the command-line, and that is what I will most easily be able to assist you with.
- In the future there may be restrictions, so please review the logistics each time.

**For this Lab/Assignment**: You will be working on your own laptop/desktop machine.

# Resources to help

- C++ Related
	- A Standard Tutorial: http://www.cplusplus.com/doc/
	- The ISO Standard for the language: https://isocpp.org
		- Typically the latest and greatest information will always be here.
	- Thoughts on vectors vs lists
		- https://baptiste-wicht.com/posts/2012/12/cpp-benchmark-vector-list-deque.html

# Description

C++ is the standard programming language for programming in the computer graphics, gaming, entertainment, and other industies that require high performance. While we can learn computer graphics in any general purpose language, the long term outlook for jobs appears to remain in C++ (And besides, once you learn how to work in C++, you could work in other languages as needed. We'll also see the OpenGL Shading Langauge(GLSL) language is C-based). For this exercise (and all that follow), you will be using modern C++. This means C++11 and beyond (C++11 is the standard of the language in the year 2011. There are further versions C++14, C++17, C++20, C++23, etc).

# C++ Introduction

**Your instructions for this part:** Read and type out the examples below in the associated .cpp file to get some practice with C++. Understanding each of them will help you complete the final deliverable and succeed in this course.

### Exercise Files Table of Contents for This Part

1. [Primitive data types](./exercise/datasize.cpp)
2. [Basic I/O](./exercise/io.cpp)
3. Writing and Reading data from Files
	- [Writing data from Files](./exercise/output.cpp)
	- [Reading data from Files](./exercise/input.cpp)
4. [Working with Strings](./exercise/string.cpp)
5. C++ and the Standard Template Library (Reading only)
6. Handy Container Data Structures - std::vector
	- [Handy Container Data Structures](./exercise/vector.cpp) - std::vector
	- [Handy Container Data Structures and sizeof](./exercise/vector2.cpp) - std::vector
8. [Pointers](./exercise/pointers.cpp)
9. [Memory](./exercise/memory.cpp)
10. [C++ Iterators](./exercise/iterator.cpp)
11. [One more look at vectors](./exercise/vector_data.cpp)
12. [Object-Oriented Programming and Classes](./exercise/class.cpp)


## Task 1 - Primitive data types (int, char, float, etc.)

C++ has many different data types built in by default. Below is a table of the default data types that are provided. A more complete set is found [here, cpp reference data types](https://en.cppreference.com/w/cpp/language/types):

<table>
  <tbody>
    <tr>
      <th>Data Type</th>
      <th>Size in Bytes</th>
      <th>Range</th>	    
    </tr>
    <tr>
      <td>long int</td>
      <td>4</td>
      <td>-2,147,483,648 to 2,147,483,647</td>	    
    </tr>
    <tr>
      <td>unsigned int</td>
      <td>4</td>
      <td>0 to 4,294,967,295</td>	    
    </tr>
    <tr>
      <td>signed char</td>
      <td>1</td>
      <td>-128 to 127</td>	    
    </tr>
    <tr>
      <td>unsigned char</td>
      <td>1</td>
      <td>0 to 255</td>	    
    </tr>
    <tr>
      <td>float</td>
      <td>4</td>
      <td>+/- 1.4023x10^-45 to 3.4028x10^+38</td>	    
    </tr>
    <tr>
      <td>double</td>
      <td>8</td>
      <td>+/- 4.9406x10^-324 to 1.7977x10^308</td>	    
    </tr>	  
  </tbody>
</table>

What is important to understand is that we need to select the appropriate data type for the information we are storing. This control means we have a greater responsibilitiy as programmers, with the tradeoff being we can really optimize our programs.

Here is a C++ example showing different data types and their sizes programmatically. We will cover input and output in the next part.

```cpp
// Compile with:
// g++ -std=c++17 datasize.cpp -o prog
#include <iostream>

int main(){

	// Most of the time a 'signed int' is abbreviated as simply an 'int'e.
	std::cout << "Data size of int in bytes = " << sizeof(int) << std::endl;
	// Most of the time a 'signed char' is abbreviated as simply a 'char'.	
	std::cout << "Data size of char in bytes = " << sizeof(char) << std::endl;
	// If we are truly trying to represent a number, than a uint8_t is preferred.
	// This is an 'unsigned integer' that can hold 8 bits of information.	
	std::cout << "Data size of uint8_t in bytes = " << sizeof(uint8_t) << std::endl;
	
	// Additionally, we have types that allow us decimal precision.
	std::cout << "Data size of float in bytes = " << sizeof(float) << std::endl;
	std::cout << "Data size of double in bytes = " << sizeof(double) << std::endl;

	return 0;
}

```

**Now you try!** [Primitive data types](./exercise/datasize.cpp)  (<-- Implement the code sample)

## Task 2 - Basic I/O 

To start, click on this URL (And then hit the C++11 tab): http://www.cplusplus.com/reference/iostream/. Take a moment to browse the Objects you have available. It may also be worth bookmarking that website as a reference.

<table>
  <tbody>
    <tr>
      <th>Object</th>
      <th align="center">Description</th>
    </tr>
    <tr>
      <td>cin</td>
      <td align="left">Handles user input</td>
    </tr>
    <tr>
      <td>cout</td>
      <td align="left">Handles output of text</td>
    </tr>
    <tr>
      <td>cerr</td>
      <td align="left">Handles output of text for error purposes</td>
    </tr>
    <tr>
      <td>clog</td>
      <td align="left">Handles output of text for logging purposes</td>
    </tr>	  
  </tbody>
</table>

Try the following example below. You will compile this from a terminal window.

```cpp
// Compile with:
// g++ -std=c++17 io.cpp -o prog
#include <iostream> // The standard input/output library

// Entry-point to our program.
int main(){

	// We output some text. Note we start with std:: because this
	// is part of the standard library namespace.
	std::cout << "Hello" << std::endl;
	std::cout << "How old are you?" << std::endl;
	
	
	// Let's use some of the primitive variable types in C++
	// to store input.
	int age;
	
	// Now we want to get c++ input (i.e. cin)
	std::cin >> age;
	
	std::cout << "That is great you are " << age << std::endl;

	return 0;
}
```

**Now you try!** [Basic I/O](./exercise/io.cpp)  (<-- Implement the code sample)

## Task 3 - Writing and Reading data from Files

Read this section to learn about file handling in C++ | [Read about this topic in anothers words here](http://www.cplusplus.com/doc/tutorial/files/)

The datasets we are going to be working with in graphics are several kilobytes to several megabytes. Files of this size are far too large to store within a source file (Many graphics datasets are even in gigabytes in domains like medical visualization). So in order for us to manipulate data within our programs, we are going to read and write modified data into files using C++'s file libraries.

Here is an example of creating a new file and writing output to it.

```cpp
// Compile with:
// g++ -std=c++17 output.cpp -o prog
#include <iostream>
#include <fstream>

int main(int argc, char** argv){


    // Opens a file to output
    std::ofstream outFile;
    // Write to a new file called 'temp.txt'
    // This overwrites a previous file, or otherwise
    // creates a new file if it does not exist.
    outFile.open("temp.txt");
    
    // We can work with files similar to how we
    // work with cout and cin.
    outFile << "# Some image data" << std::endl;
    outFile << "P3" << std::endl;

    // Closes the file we are streaming data to
    outFile.close();

    return 0;
}
```

**Now you try!** - [Writing data from Files](./exercise/output.cpp)  (<-- Implement the code sample)

**Note**: One 'gotcha' spot I see with folks is when writing out character data, and expecting integer output (i.e. If you are storing integers in a 'unsigned char' type, they may be written out as a character value, rather than the value between 0-255).

In order to fix this, cast the value out. e.g. `outFile << static_cast<int>(my_unsigned_char);`

Here is an example for opening a file and reading the input.

```cpp
// Compile with:
// g++ -std=c++17 input.cpp -o prog
#include <iostream>
#include <fstream>
#include <string> // new library!

int main(int argc, char** argv){


    // Opens a file to output
    // You will notice the name is 'ifstream'
    // This means 'input file stream'
    std::ifstream inFile;

    // Now we are going to read in some data.
    // I want to actually make our program more flexible
    // and read in a file from the command line.
    // To do this, we'll use the argc, and argv**
    // arguments of our main function.
    // So when we run our program, we will type on the command-line:
    // ./prog ./../../../common/objects/bunny_centered.obj"
    
    // Let's enforce that there needs to be one argument.
    // argc is the "argument count" parameter.
    // Note: cerr will write to stderr (the standard error output stream).
    //       This is a better practice for error reporting versus std::cout
    //       to ensure the error message is flushed out to the user.
    if (argc != 2){
        std::cerr << "Oops, exactly two arguments needed.\n";
        std::cerr << "ProgramName file_path.\n";
        return 0;
    }
    // Now we can open our file.
    // Think about why this is argv[1].
    // Try printing it out to see what this is.
    inFile.open(argv[1]);
    
    // Lets also check to make sure the filepath is correct.
    if(inFile.is_open()){
        // Now we can do some work
        // We'll learn about strings in a moment,
        // but we are using getline to read in
        // one string of text at a time, until
        // we have nothing left to read.
        std::string line;   // A string object.
        while(getline(inFile,line)){
            std::cout << line << std::endl;
        }
    }else{
    	std::cout << "Filepath does not exist" << argv[1] << std::endl;
	std::cout << "Make sure the path is relative to where you are executing your program" << std::endl;
    }
    
    // Closes the file we are reading from
    inFile.close();

    return 0;
}

```

**Now you try!** [Reading data from Files](./exercise/input.cpp)  (<-- Implement the code sample)


## Task 4 - Working with Strings

Wonderful, we can read and write data to files! But files in graphics (and other domains) are often very structured. This means that if we want to access various parts of the file, then we might need better granularity than accessing them one line at a time.

Strings are typically implemented as character arrays, such that each index is an unsigned char, and is terminated with the null character [see character sequences](http://www.cplusplus.com/doc/tutorial/ntcs/).

<table>
  <tbody>
    <tr>
      <th>0</th>
      <th>1</th>
      <th>2</th>
      <th>3</th>
      <th>4</th>
      <th>5</th>	    
    </tr>
    <tr>
      <td>'h'</td>
      <td>'e'</td>
      <td>'l'</td>
      <td>'l'</td>
      <td>'o'</td>
      <td>'\0'</td>
    </tr>
  </tbody>
</table>

In our previous example, we saw the std::string data type. This is provided through the <string> library, which provides us a slightly more convenient way to work with textual data.
	
The [reference page](http://www.cplusplus.com/reference/string/string/) provides several handy methods for performing operations like searching strings, adding characters, and navigating them. Here is a very brief example. Use the reference to see more examples.

```cpp
// Compile with:
// g++ -std=c++17 string.cpp -o prog
#include <iostream>
#include <string>

int main(){
    // Create a string
    std::string fullName = "Mike Shah";
    // Store a portion of the string
    std::string firstName = fullName.substr(0,4);
    std::string lastName = fullName.substr(5,9);
    // Output our strings
    std::cout << "First: " << firstName << std::endl;
    std::cout << "Last: " << lastName << std::endl;

    // Iterate through our string one
    // character at a time.
    // We break if we find a space.
    // You will also note two ways
    // to access a strings individual
    // characters.
    unsigned int i =0;
    while(i < fullName.length()){
        if(fullName.at(i)==' '){
            // Terminate from our loop
            break;
        }
        std::cout << fullName[i];
        ++i;
    }


    return 0;
}
```

**Now you try!**  [Working with Strings](./exercise/string.cpp)  (<-- Implement the code sample)

## Task 5 - C++ and the Standard Template Library (STL)

C++ comes with "batteries included", meaning that several general purpose algorithms and data structures have been built for us. This is a good thing, as it avoids us from having to do a lot of work and instead we can use well tested and standardized data structures and algorithms. In this course,  you are encouraged to use **The Standard Template Library** (STL). The Standard Template Library (STL) is *templated* which means it can work with many data structures. If you have used languages like Java, then you are likely familiar with the concept of a generic class which is the equivalent of a template in C++. The next sections will describe parts of the Standard Template Library (STL) that will be helpful in achieving your task.

[See the other container data structures](http://www.cplusplus.com/reference/stl/)

**Nothing to try here** Move on to the next task!

## Task 6 - Handy Container Data Structures - The Vector

Often we will want to store different collections of data. This is very useful in situations where we do not know how much data either during compile-time(i.e. before we are running the program). This means we need a flexible expanding data structure to store data. The <vector> header includes the std::vector which is the standard tool to do this.

Below is a brief example.

```cpp
// g++ -std=c++17 vector.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

    // Create a vector which stores
    // 'unsigned char' data.
    std::vector<unsigned char> myData;
    
    // Add data into our vector.
	// The push_back member function automatically adds and expands our vector
    for(unsigned int i = 65; i < 91; ++i){
        myData.push_back(i);
    }

    // Iterate through our container structure
    // and print out the data in our vector.
    for(unsigned int i = 0; i < myData.size(); ++i){
        std::cout << myData[i];
		// std::cout << myData.at(i); // This line does the same thing
    }

    return 0;
}
```

**Now you try!**  [Handy Container Data Structures](./exercise/vector.cpp)  (<-- Implement the code sample)

One thing to be careful about with a vector, is retrieving the 'size' of the vector. Make sure to use the '.size()' member function, as opposed to 'sizeof'. 'sizeof' merely returns the size of the datatype (or, in the case of an array, the sizeof an array that has been allocated on the stack. 
																				 
Note that a std::vector is merely a wrapper around a raw array, and it has the ability to dynamically reallocate (i.e. resize the array) in order to store more elements. You can access the underlying raw array, and we are going to need to sometimes in this course.

Below is a brief example.

```cpp
// g++ -std=c++17 vector2.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

    // Create a vector which stores
    // 'unsigned char' data.
    std::vector<unsigned char> myVector;
    
	for(unsigned int i = 0; i < 91; ++i){
        myVector.push_back(i);
    }
	
	// Remember, std::vector is a data structure storing a specific type of element.
	// std::vector is a 'dynamically resizing' array.								
    std::cout << "(number of elements) myVector.size()                           = " << myVector.size() << std::endl;
    std::cout << "(size of data structure) sizeof(myVector)                      = " << sizeof(myVector) << std::endl;
    std::cout << "(raw array myVector is built on top of) sizeof(myVector.data())= " << sizeof(myVector.data()) << std::endl;
	std::cout << std::endl;
																															
	// Compare the std::vector to a raw array when using sizeof
	// sizeof can figure out the size of the array, if we are checking the 'sizeof' within the same block scope the raw array was declared.
	int rawArray[100];
	std::cout << "locally allocated, i.e. stack allocated array) sizeof(rawArray)=" << sizeof(rawArray) << std::endl;
	std::cout << std::endl;
																												
	// Compare the raw array to a heap allocated array
	int* heapArray = new int[52];
	// In this case, because heapArray is a pointer, sizeof will only return the size of a pointer type, usually 8 bytes.
	std::cout << "heap allocated array, (i.e. pointer to a chunk of memory) sizeof(heapArray)=" << sizeof(heapArray) << std::endl;
	std::cout << std::endl;	

	// Note: We should also delete any heap allocated memory.
	delete[] heapArray;
						  
    return 0;
}
```

**Now you try!**  [Handy Container Data Structures and sizeof](./exercise/vector2.cpp)  (<-- Implement the code sample)																				 
																				 
## Task 7 - Pointers

Here's a quick example on pointers. Remember that a pointer stores a memory address. If we want the actual value at that memory address we 'dereference' with the asterisk(\*) symbol before the variable. Try this sample out.

```cpp
// g++ -std=c++17 pointers.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

    // Here we create a pointer.
    // It points to nothing.
    int* px= nullptr;
    // Let's create another variable so we can point to it.
    int x = 7;
    // Now we use the 'assignment operator' to point to
    // the variable x. Our pointers 'point' to things remember.
    px = &x; // The 'ampersand gives us the 'address of' a varaible.
             // Remember, pointers store addresses.

    // Let's now dereference 'px' to get the value of the 'thing'
    // that px points to.
    std::cout << "px dereferenced is = " << *px << "\n"; 


    return 0;
}
```

**Now you try!**  [Pointers](./exercise/pointers.cpp)  (<-- Implement the code sample)

It is also worth noting that you can have pointers to functions as well. This is a [tutorial](https://www.cprogramming.com/tutorial/function-pointers.html) if you are curious.
	
I have also recorded a guide on pointers here: [Understand (almost) everything about the fundamentals of C++ pointers in 96 minutes
](https://www.youtube.com/watch?v=2R5cjpi9Fzw&list=PLvv0ScY6vfd8YRjgGvXKJRAMZQAxNypcH&index=6)

## Task 8 - Memory (new and delete)

Those with C experience will recall you have to manage your own memory in C. In C++, you have to do the same thing. However, we use 'new' and 'delete' operators instead. 

```cpp
// g++ -std=c++17 memory.cpp -o prog
#include <iostream>
#include <vector>


int main(int argc, char** argv){

    // In this example I am allocating some memory
    // dynamically. That means when the program
    // starts running, I request a chunk of memory.
    // A contiguous chunk of memory, is otherwise
    // just known as an 'array' if all of the elements
    // are the same type.
    uint8_t* contiguous_chunk_of_memory = new uint8_t[80];
       
    // Sometimes we want to just allocate one item too.
    uint8_t* one_item = new uint8_t;

    // One thing to keep in mind is that memory that
    // we allocate dynamically (i.e. using 'new'),
    // we cannot determine the 'size' or how big the
    // array is.
    std::cout << "sizeof(contiugous...) =" << sizeof(contiguous_chunk_of_memory) << std::endl;
    // ^ Notice that this will only return the size of our data type,
    //   which is the 'pointer'.


    // It's important that I delete this chunk of memory.
    // There are two ways to do this:
    // 1.   delete   // will only delete a single element.
    // 2.   delete[] // will delete the entire contiguous chunk of
    //                  memory.
    delete one_item;
    delete[] contiguous_chunk_of_memory;

    return 0;
}

```

**Note**: We never would mix malloc with delete or new with free for example. Doing so causes unpredictable behavior. In this course,  you reclaim memory with 'new' with the 'delete' operator every time.

**Now you try!**  [Memory](./exercise/memory.cpp)  (<-- Implement the code sample)

## Task 9 - C++ Iterators

Here's another way to 'move' through data using what is called an 'iterator' in C++. Iterators are provided in the standard template library(STDL) for all of our data structures such that we can move from one item to the next. In a vector this is relatively trivial, but imagine a 'tree' data structure in which we may want an easy way to traverse a tree. Luckily, C++ provides us with just that. :) 

And don't worry, I do not mind if you prefer for loops versus iterators in this course--but you should be aware of them and where they are handy!

```cpp
// g++ -std=c++17 iterator.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

    // Create a vector which stores
    // 'unsigned char' data.
    std::vector<unsigned char> myData;
    
    // Add data into our vector.
    for(unsigned int i = 65; i < 91; ++i){
        myData.push_back(i);
    }

	
	// Here's another way to iterate through data using
	// what is called an 'iterator'
	// Iterators are nice because they show the intent of
	// what we are doing--that is, iterating through the
	// entire collection of data.
	// We create an iterator and point it to the
	// start of our data.
	std::vector<unsigned char>::iterator it = myData.begin(); 
	// Same thing for the end.
	std::vector<unsigned char>::iterator end = myData.end();
	// Now we just move forward one element at a time
	// in our collection of data.
	for(; it != end; it++){
	// Note: Our iterator is a 'pointer' to the next
	//       piece of data. So we have to put a '*'
	//       in front of it to dereference the pointer
	//       and retrieve a value back.
		std::cout << *it;	
	} 

    return 0;
}

```

**Now you try!**  [C++ Iterators](./exercise/iterator.cpp)  (<-- Implement the code sample)

## Task 10 - One more look at vectors.

Sometimes we want to directly access the internal data structure of a vector (i.e. the dynamically allocated array). Here's how in this example.

```cpp
// g++ -std=c++17 vector_data.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

    // Let's store some integers here
    // this time to change our data.
    std::vector<int> myData;
    
    // Let's add some data into our vector.
    for(int i=0; i < 42; ++i){
        myData.push_back(i);
    }

    // One thing to know about a vector, is
    // that it really is just a nice 'wrapper'
    // around a dynamically sized array.
    //
    // We can access the contents of the array
    // as follows.
    // 
    // In otherwords, the .data() member function
    // of a vector returns us a pointer to the
    // array data structure.
    int* internalArray = myData.data();
    // So we're just pointing to a 'chunk' of data
    // inside our vector. We can iterate through
    // this data like a normal array.
    for(int i=0; i < myData.size(); i++){
        std::cout << internalArray[i] << "\n";
    }

    return 0;
}
```


**Now you try!** [One more look at vectors](./exercise/vector_data.cpp)  (<-- Implement the code sample)

## Task 11 - Object-Oriented Programming and Classes

C++ is a programming language with Object-Oriented capabilities. C++ was initially "C with classes" when Bjarne Strousoupe first added classes to the language. Classes are the primary mechanism that allows users to build their own data types. The custom data type, which is a class, is often referred to as a 'blueprint' for an 'object'.

Posted below is a simple example. I would suggest as a complete resource this 'classes' section of the tutorial: [http://www.cplusplus.com/doc/tutorial/](http://www.cplusplus.com/doc/tutorial/) (Read at a minimum classes(1)).

```cpp
// compile with: g++ -std=c++17 class.cpp -o prog

class PPM{
public: // Member Functions/Variables available

    // Constructor called when object
    // is first created.
    PPM(unsigned int width, unsigned int height){
        // Allocate some memory
        pixelData = new unsigned char[width*height*3];
    }
    // Destructor called when object is
    // destroyed.
    ~PPM(){
        // Reclaim our memory when we are done.
        delete[] pixelData;
    }
    
private:    // Data not visible to a user of 
            // this object.
    uint8_t* pixelData;

};

int main(){

    // Create an instance an object with 
    // a data type of 'PPM'
    PPM myPPM(64,128);

    return 0;
}
```

**Note**: The above example is 'condensed' to one file to make things simple. Normally the class declaration and the class definitions (i.e. the body of the code within the member functions) are in separate files. You'll see a cleaner implementation in your Image library that you later see.

**Now you try!** [Object-Oriented Programming and Classes](./exercise/class.cpp) (<-- Implement the code sample)

### Aside on structs

If you have programmed in C++ before, then you may also know that *structs* are another way to create custom data type. In C++, structs and classes are equivalent. The only difference is a struct by default make their members public, whereas a class makes its members private. By convention, structs are also used as [POD data types](https://en.wikipedia.org/wiki/Passive_data_structure).

## Final notes

With a little bit of prior programming experience and experimentation you can pick up C++. More C++ will be introduced as needed as we solve additional problems. At this point, you are starting to get a little dangerous with your new C++ knowledge!

If you need more practice (and in particular part 3 is very useful for this assignment), here are some video lessons (repeated from lab 1)
* [C++ Quick Start Part 1](https://www.youtube.com/playlist?list=PLvv0ScY6vfd-R9N-vIDXdd4HO9IYATIxJ)
* [Classes and Compiling multiple files (program structure)](https://www.youtube.com/watch?v=0DZyFOa-PrQ&list=PLvv0ScY6vfd-R9N-vIDXdd4HO9IYATIxJ&index=3)
* [Read, write, and parse files(fstream, string, & stringstream)](https://www.youtube.com/watch?v=CAqX8YT4lHI&list=PLvv0ScY6vfd-R9N-vIDXdd4HO9IYATIxJ&index=4)
* [References, Pointers, and Dynamic Memory Allocation](https://www.youtube.com/watch?v=P2_z98wEU6M&list=PLvv0ScY6vfd-R9N-vIDXdd4HO9IYATIxJ&index=4)
