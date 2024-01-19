## Please read this section and your appropriate operating system.

Please follow the respective tutorial below for your operating system that you plan to use throughout the semester. 

You will know your environment works if you can run [python3 build.py](./build.py) and execute the **lab**.

* `python3 build.py`
* `./prog` or `./lab` (Whatever the binary files is named -- windows users may need to add .exe if you are running natively on windows)

- I would encourage students to Ubuntu Linux + a virtual machine for this course simplicity.
	- Make sure you otherwise enable 'hardware acceleration' if that is an option on your virtual machine.
- **Very important note** I would encourage students this semester to try utilizing SDL 3, as that is the latest version coming out.
	- By default, Spring 2024, it is okay to otherwise use SDL2 if that is easy enough to setup.
 	- Most support code will otherwise use SDL2.
- In some cases, if python3 does not work you can try the following:
  	- On Linux: `g++ -std=c++20 main.cpp -o prog `pkg-config --libs --cflags sdl3` `
  	- ^ Mac will be the same, though you may need to install pkg-config (e.g. brew install pkg-config, and you may also need to install brew first...).
  	- Windows on mingw should also be similar, though you may need to use 'pacman' if you are using mysys to install pkg-config.

I have provided some links below otherwise with instructions for getting setup.

[Lazy Foo](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php) also has a nice set of tutorials for helping  you configure how to run your program on your respective operating system.

## Linux

In most cases users from a terminal can install the `sudo apt-get install libsdl2-dev` on their machines and then they are all set. Further directions follow.

* See the video tutorial listed here: [SDL2 Linux command line setup with Glad and OpenGL](https://www.youtube.com/watch?v=P3_xhDIP7bc&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=3)
* An older writeup of directions is located here
	* [Linux Setup Tutorial and Video](http://www.mshah.io/comp/Spring18/graphics/Lab/1/linux.html) (Tested on Ubuntu)

## Mac

* See the video tutorial listed here: [SDL Mac Including M1 Setup with Simple OpenGL Application](https://www.youtube.com/watch?v=V6ACATpl2LQ&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=4)
* An older version of the tutorial is here with a writeup.
	* [Mac Setup Tutorial and Video](http://www.mshah.io/comp/Spring18/graphics/Lab/1/mac.html) (Tested on High Sierra 10.13.2 Operating System)

## Windows

* See the video tutorial listed here: [SDL Windows Setup with Mingw and Simple OpenGL Application](https://www.youtube.com/watch?v=DQ-NBjBFLJ4&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=3)

* Other Windows setup options
  * Option 1: 
    * Download mysys from here: [Google Drive Mirror](https://drive.google.com/file/d/116IIh7n8aoWXKDiQeonZjxXEkPPh3RME/view?usp=sharing)
    * unzip the contents to a location on your machine.
    * From mysys64 launch the mingw64 terminal(a blue icon).
      * Note, you may have to navigate to the lab folder wherever you have cloned this repo. (e.g. cd /c/Users)
    * Try running the build script with `python build.py` and then execute lab.exe
  * Option 2: 
    * [MinGW 64](http://www.mshah.io/comp/Spring18/graphics/Lab/1/MinGW.html) (Tested on Windows 10)
      * These are some more scattered instructions on installation.
  * Option 3:
  	*  Try this tutorial to setup mingw following the instructions here: https://www.youtube.com/watch?v=UvJt9MZs_M8
  * Option 3:
    * In the past, folks have found integrations for VSCode that seem to 'just work' by installing g++. You may try that as well. 
  * Option 4: (Least preferred)
      * Use visual studio here: http://www.mshah.io/comp/Spring18/graphics/Lab/1/windows.html

## Nothing Works? Try a Virtual Machine with linux

* Note -- using a virtual machine on linux is also an option in this course, as I generally recommend developing in a linux environment!
  	- [Mirror 1](https://drive.google.com/file/d/1ntaw4P-Z11rW0sdTUHRjbESS6MbnIPsM/view?usp=sharing) (password for VM is 'user')
	- [Mirror 2](https://storage.cloud.google.com/elevated-nuance-167519.appspot.com/Ubuntu20-ShahCourse.ova?_ga=2.123310094.-42712688.1583790606) (password for VM is 'user')
		- Generally you should be able to just install virtual box, and then open the .ova by double-clicking it, and then virtual box should open up and install the VM.

Note: The virtual machine will limit you to OpenGL 3.3, which is probably fine for 95% of this course.

## Still nothing?

 * Something else? Let your instructor know. Typically labs and assignments are tested on all three configurations above (though in the future there will be 1 set of directions to follow after you are setup!)
* Remote graphics through a terminal (Optional--and here primarily for very limited situations)
