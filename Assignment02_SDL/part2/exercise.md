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

1. *answer to number 1*
2. *answer to number 2*
3. *answer to number 3*
4. *answer to number 4*
5. *answer to number 5*
6. *answer to number 6*
7. *answer to number 7*
8. *answer to number 8*
