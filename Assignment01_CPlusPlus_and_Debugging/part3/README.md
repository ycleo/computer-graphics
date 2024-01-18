# Part 3 - PPM Library

## Implementation Logistics

- You may use whatever operating system, IDE, or tools for completing this lab/assignment.
	- However, my instructions will usually be using the command-line, and that is what I will most easily be able to assist you with.
- In the future there may be restrictions, so please review the logistics each time.

**For this Lab/Assignment**: You will be working on your own laptop/desktop machine.

# Resources to help

- Image Library related
	- The PPM Format Specification
		- http://netpbm.sourceforge.net/doc/ppm.html

# Description

For this assignment you are going to implement a PPM library. PPM is a data format for structuring image data. You likely have used or saved images formatted as .jpg, .bmp, .png, or .gif, and now you will understand .ppm. 

For this first exercise you are going to build an image parser in C++. This project will introduce you to some common C++ libraries we will use throughout the course. It will also introduce you to how image data is stored. The **deliverables** section describes the expected output.

## Images

<img align="right" src="./media/RGB-animation.gif" width="400px" alt="RGB Animation">

Images are made up of pixels, which are located with an x,y coordinate. That is, a 64x128 image, is 64 pixels wide, and 128 pixels high. Within each pixel (say pixel (2,100)) are three values, that specify the red, green, and blue components for that individual pixel. The higher the value from a range of 0-255, the more that color is expressed.

The PPM format looks something like this:

```
P3
# some_image.ppm (Note this is just a comment)
64 128
255
 0  0  0    0  0  0    0  0  0   125 0  125 .... 60 more triples.
 0  0  0    0 225 7    0  0  0    0  0  0   .... 60 more triples.
 0  0  0    0  0  0    0 15  7    0  0  0   .... 60 more triples.
15  0 15    0  0  0    0  0  0    0  0  0   .... 124 more rows follow.
```

1. The first line is the 'header' data of the file, which describes which specific format of PPM data you are loading.
2. The second line begins with a '#' which is merely a comment. This line should be ignored when reading in data.
3. The third line specifies the width (64 pixels) and the height(128) pixels.
4. The fourth line specifies the maximum value for an individual color value(i.e. the red, green, or blue component). So values will range from 0 to 255.
	- One thing to note here, is that if we are only storing values between 0-255, we can use an uint8_t (i.e. an *unsigned char*) to be efficient.

### Structure of our library

You are given a [./include/PPM.hpp](./include/PPM.hpp) header file. Header files in C++ are like 'interfaces' that describe our class for the PPM image. You will implement the functionality for that class in the [./src/ppm.cpp](./src/ppm.cpp) file (i.e. .cpp files are the implementation of source that gets compiled). A corresponding [./src/main.cpp](./src/main.cpp) file is where the program will begin, as the main.cpp has the 'int main()' function. 

Note: It's important that you internally store your PPM images for this course as a 'char' type (e.g. uint8_t or char).

## How to run your program

Your solution should compile using the [build.py](./build.py) file. That is, we will run your program by typing [python3 build.py](./build.py) and it should just work.

## Deliverables

* Implement the PPM Library such that an image can be loaded, then a darker version or a lighter version of the image can be saved out.
	* Make sure to commit your source code changes to the code repository.
	* Note: You should not implement the PPM images to the repository.
	* Note: You should not commit your .ppm images to the repository.

# F.A.Q. (Instructor Anticipated Questions)

- Q: Should I divide or doulbe the 'max_range' when I lighten or darken?
	- A: Short answer -- no.
	- A: Careful! Think about what this will effectively be doing. For example, assume your max range is '1' (0 is black, 1 is white). The max range may interpret (if you half the max_range from 255 to 127), that 127 actually should be interpreted as 255 (i.e. when you noramlize the scale) when read in some other program.
- Q: My darken value is not properly staying at 255 when exceeding 255.
	- A: Careful! The data type I have provided by default provides a range of 0-255. So when you exceed that range (say lighten a pixel of value 200, and it becomes 200 x 2=400, it exceeds the data types range), you should compute that in an intermediate data type that is larger, say an 'int', and then store the result back into the unsigned 8 bit type.
- Q: Why are some of the comments weirdly formatted in this assignment?
	- A: They are formatted such that a tool called [doxygen](http://www.doxygen.nl/) can take these comments and create a nice html help page. For future assignments where I provide support code, this is helpful to have. It is also good programming practice to document things well!
- Q: Will PPM images be valid?
	- A: Yes, I will not for example send in dimensions of 10x10 and only supply 1 pixel of data. Although, this might be nice functionality to handle in your PPM class!
- Q: What does it mean to handle ppm values with only one value on a line versus multiple?
	- A: (below)
	
One value per line
```
P3
# some_image.ppm (Note this is just a comment)
64 
128
255
0
0
0
0
0
0
0
0
0
125
0
125
```

multiple values per line
```
P3
# some_image.ppm (Note this is just a comment)
64 128
255
 0  0  0    0  0  0    0  0  0   125 0  125
```

- Q: What is the difference between a P3 and P6 PPM Image (Note: You only need to support P3, but P6 is also useful if you do support it)
	- A: https://my.eng.utah.edu/~cs5610/ppm.html
	- <details>
				<summary>A copy and paste of the website above</summary>

		## PPM

		A PPM file consists of two parts, a header and the image data. The header consists of at least three parts normally delinineated by carriage returns and/or linefeeds but the PPM specification only requires white space. The first "line" is a magic PPM identifier, it can be "P3" or "P6" (not including the double quotes!). The next line consists of the width and height of the image as ascii numbers. The last part of the header gives the maximum value of the colour components for the pixels, this allows the format to describe more than single byte (0..255) colour values. In addition to the above required lines, a comment can be placed anywhere with a "#" character, the comment extends to the end of the line.

		The following are all valid PPM headers.

		## Header example 1
		```
		P6 1024 788 255
		```

		## Header example 2

		```
		P6 
		1024 788 
		# A comment
		255
		```

		## Header example 3

		```
		P3
		1024 # the image width
		788 # the image height
		# A comment
		1023
		```

		The format of the image data itself depends on the magic PPM identifier. If it is "P3" then the image is given as ascii text, the numerical value of each pixel ranges from 0 to the maximum value given in the header. The lines should not be longer than 70 characters.

		## PPM example 4

		```
		P3
		# example from the man page
		4 4
		15
		 0  0  0    0  0  0    0  0  0   15  0 15
		 0  0  0    0 15  7    0  0  0    0  0  0
		 0  0  0    0  0  0    0 15  7    0  0  0
		15  0 15    0  0  0    0  0  0    0  0  0
		```

		If the PPM magic identifier is "P6" then the image data is stored in byte format, one byte per colour component (r,g,b). Comments can only occur before the last field of the header and only one byte may appear after the last header field, normally a carriage return or line feed. "P6" image files are obviously smaller than "P3" and much faster to read. Note that "P6" PPM files can only be used for single byte colours.

		While not required by the format specification it is a standard convention to store the image in top to bottom, left to right order. Each pixel is stored as a byte, value 0 == black, value 255 == white. The components are stored in the "usual" order, red - green - blue.
		</details>
- Q: Do we have to save the comments when we save the PPM.
	- A: Nope. It may be a nice feature, but not necessary.
- Q: How do I create my own .ppm image?
	- A: I recommend using the program GIMP (free on Linux, Windows, and Mac). You can then export .ppm, and if you export to ASCII you will be able to see the output of your file. If you choose 'raw' then you will output the binary format (P6 format) which by default our loaders did not load, unless you implement that feature. 
- Q: Can I write out floats? 
	- A: No, that is a portable float map (PFM) image. It is 4 times as large, and we do not quite need that precision for now. If you use floats, you may also exceed the expected RGB value of 255.
 - 
# Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

- Fun fact: The famous computer scientist Donald Knuth would pay folks one $2.56 for errors in his published works. [[source](https://en.wikipedia.org/wiki/Knuth_reward_check)]
- Unfortunately, there is no monetary reward in this course :)

