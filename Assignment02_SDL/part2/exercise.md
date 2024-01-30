# exercise.md

The following are a list of questions about the design of our math library and also further your C++/general programming knowledge.

1. In C++ what are the three instances where you would use the keyword [const](https://en.cppreference.com/w/cpp/keyword/const)?
2. What does [inline](https://en.cppreference.com/w/cpp/language/inline) do? Why might a programmer use it?
3. Why do you think libraries like GLM are implemented as a header only library? 
	- (Sometimes you will see this, and you may research [.inl files](https://stackoverflow.com/questions/1208028/significance-of-a-inl-file-in-c) in C++)
4. C++ allows for something known as 'operator overloading'. This means we can define (or redefine) how operators like +,-,/,etc. work--but this means additional symbols like `<<`. Would it be helpful to implement the '<<' operator for a mat4 type? (i.e. `operator<<`)? What might you use this for? Does the GLM library overload the '<<' operator? (i.e., `std::cout << some_mat4`)
5. For the floating-point data type, would it be dangerous to overload the operator for '=='?
	- How might you mitigate this? [reference](https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/)
	- The question I am really asking is, why is it a problem to compare two floating point numbers?
6. What is a template in C++? Is the GLM library using templates?
7. Do a little research on your own for this one. How closely named are the functions in GLM versus the GL Shading Language(GLSL) (i.e., Was the GLM library designed to closely match GLSL?)
8. Do you feel comfortable working with pointers? (Yes/No) -- If not -- here's a video: https://www.youtube.com/watch?v=2R5cjpi9Fzw

You may add your notes here:

1. </br>
- Constant Variables: `const int num = 10;` (the value of the num cannot be modified after initialization)
- Constant Pointers: `int* const ptr = &value;` (the pointer itself is constant, but the value it points to can be modified. Once a constant pointer is assigned a memory address, it cannot be reassigned to point to a different memory location)
- Constant Method: `void func() const {}` (It's a promise to the compiler that the function will not modify any non-static data members of the class)
2. </br>
- `inline` suggests that the compiler substitutes the code within the function definition in place of each call to that function. 
- Reason to use `inline`: Eliminates the overhead of a function call, as there is no need to push and pop the function's stack frame. 
3. </br>
- Making GLM a header-only library simplifies the usage for users. Users only need to include the appropriate header files in their projects, and there's no need to separately compile and link against a GLM library.
- The use of `.inl` files is a practice to include the actual implementation of templated functions separately while still keeping the implementation within the header file.
4. </br>
- Yes, implementing the `<<` operator for a `mat4` type can be very helpful. It allows you to define a custom way to display or output the contents of a `mat4` matrix when using the `<<` operator with an output stream.
- I will use it for debugging to log the contents of a `mat4` matrix.
- Yes, the GLM library does overload the `<<` operator for various types, including `mat4`.
5. </br>
- Yes, it's dangerous.
  - The finite precision of floating-point numbers can lead to precision errors, and directly comparing two floating-point numbers for exact equality may not produce the expected results due to rounding errors. (Rounding errors occur when a number that cannot be represented exactly in the chosen precision is rounded to the nearest representable value.)
  - To mitigate these issues, it's recommended to use an epsilon-based approach for floating-point comparisons. Instead of checking for exact equality, you can check if the difference between two floating-point numbers is within a small tolerance value (epsilon).
6. </br>
- Template is a way to define functions or classes with placeholders for the types of data they will work with. These placeholders are represented by template parameters.
- Yes, GLM uses templates to define classes and functions that work with different numeric types. Users can instantiate these templates with specific types.
7. GLM was indeed designed to closely align with GLSL in terms of function names, conventions, and math operations.
8. Yes, I am comfortable working with pointers.
