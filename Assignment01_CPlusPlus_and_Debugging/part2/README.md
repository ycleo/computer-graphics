# Part 2 - Debugging

<!-- <img align="right" src="./media/debugging.gif" width="300px" alt="picture"> -->

> How to debug C++ Code

## Implementation Logistics

- You may use whatever operating system, IDE, or tools for completing this lab/assignment.
	- However, my instructions will usually be using the command-line, and that is what I will most easily be able to assist you with.
- In the future there may be restrictions, so please review the logistics each time.

**For this Lab/Assignment**: You will be working on your own laptop/desktop machine.


# Resources to help

Some additional resources to help you through this lab assignment

- For Linux Users
	- [GDB Beginner Masterclass](https://www.youtube.com/watch?v=MTkDTjdDP3c)
	- [My debugging tutorial 2](https://youtu.be/RuMMw7pBtnw)
- For Mac users
	- [My LLDB Debugging tutorial](https://www.youtube.com/watch?v=v_C1cvo1biI)
	- [Quick and Dirty LLDB: All you need in 5 minutes.
](https://www.youtube.com/watch?v=3BkEOvI36Ds)
- For Windows users
	- (Same as my gdb tutorial if working on command line)
	- If using Visual Studio try: https://www.youtube.com/watch?v=0ebzPwixrJA

# Description

Debugging is an essential skill for programmers, especially graphics and engine programmers who have to be able to navigate large codebases. For this portion of the assignment, I want you to use a debugger (GDB is recommended or otherwise one integrated into your IDE) to practice debugging. For some of you this may be the first time using such a tool, so I want you to have some exposure at the least (For others of you, perhaps you have some experience).

## Why

Interactive debuggers are significantly more powerful than using 'printf or 'cout' statements in your code (although that can be effective). The reality is that your iteration time to 'save', 'compile', 'run' goes up significantly versus just using a debugger. Debuggers also give you the ability to easily investigate stack traces, memory addresses, and what arguments were called for example. 

## Task 1 - Debugging

Please watch the first video [GDB Beginner Masterclass](https://www.youtube.com/watch?v=MTkDTjdDP3c&list=PLvv0ScY6vfd-GGT-aUH31X2yXgBSYXo6t&index=2&)

Note: For Mac users, you'll likely have to use LLDB, and you can instead watch this video - [My LLDB Debugging tutorial](https://www.youtube.com/watch?v=v_C1cvo1biI)


* Some notes on GDB:
	* Compile your program with the '-g' option
	* `gdb ./prog `
		* This will run the program
	* `gdb ./prog --tui`
		* This will run the program and start the Text User Interface (Otherwise, just hit ctrl+x then 1)
		* If this does not work, than you can type `layout src` once gdb has launched normally to see the source view.
	* `start` 
		* Starts your program
	* <kbd>n</kbd> or 'next'
		* moves to the next line that is visible
	* <kbd>s</kbd> or 'step'
		* Steps into a function
	* `br` *function or line*
		* insert a breakpoint
		* 'info breakpoints' will display our breakpoints.
	* <kbd>c</kbd> or 'continue'
		* continues
	* <kbd>enter</kbd>
		* repeats the previous comand
	* <kbd>bt</kbd> or 'backtrace'
		* shows you the call frame
	* 'info locals'
		* Shows you the local variables

Please watch the second following video: [https://youtu.be/RuMMw7pBtnw](https://youtu.be/RuMMw7pBtnw) The origin of this video was actually from office hours, and I think learning how to debug code makes ones life much easier as a programmer (it's what we spend most of our time honestly doing!). Your task will be to work through and understand some of the basics of how to use your debugger for your system and then report on your learnings.

And here is a bonus third tutorial: [Give me 15 minutes & I'll change your view of GDB](https://www.youtube.com/watch?v=PorfLSr3DDI). Some of you may have already watched it, which is wonderful! 


### Deliverables

- Write in [exercise.md](./exercise.md) two new things you learned about debugging.
	- Note: You do not have to use GDB, it is okay if you have a different debugger.
- Upload a screenshot called [debug.jpg](./debug.jpg) into this directory showing you using a debugger.
	- Note: Show yourself actively debugging your code or a simple c++ file.
 
# Going Further

What is that, you finished Early? Did you enjoy this assigment? Here are some (optional) ways to further this assignment.

- Try more debugging tutorials

# F.A.Q. (Instructor Anticipated Questions)

- Q: Can I use the VSCode Integration for GDB or lldb?
	- A: Yes, go for it. 
- Q: Can I use my IDE (Visual Studio, XCode, QTCreator, IntelliJ, CLion, Codeblocks, etc.) and the integrated debugger to complete this?
	- A: Yes

# Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

- Fun fact: The famous computer scientist Donald Knuth would pay folks one $2.56 for errors in his published works. [[source](https://en.wikipedia.org/wiki/Knuth_reward_check)]
- Unfortunately, there is no monetary reward in this course :)
