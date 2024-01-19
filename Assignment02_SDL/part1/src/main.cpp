/** @file main.cpp
 *  @brief Entry point into our program.
 *         Support Code written by Michael D. Shah
 *         Last Updated: 5/07/21
 *         Please do not redistribute without asking permission.
 *
 *  @author Mike Shah
 *  @bug No known bugs.
 */

// Functionality that we created
#include "SDLGraphicsProgram.hpp"

// Create an instance of an object for a SDLGraphicsProgram
// Note: The 'g' prefix indicates that this is a
//       global variable.
// Note: 'globals' generally are bad as they can clutter
//       the program. Havin '1' is sometimes okay.
SDLGraphicsProgram gSDLGraphicsProgram(1280,720,1);

// Called once before the main loop
// Useful for any 'setup' that you need to do.
void PreLoop(void){
    std::cout << "Called before the loop one time!\n";
}

// Handle any 'user input' here.
void Input(void){
	// Event handler that handles various events in SDL
    // that are related to input and output
    SDL_Event e;
    // Enable text input
    // SDL_StartTextInput();
	//Handle events on queue
	while(SDL_PollEvent( &e ) != 0){
		// User posts an event to quit
		// An example is hitting the "x" in the corner of the window.
		// Set our 'flag' to true so that we quit executing the Loop() function..
		if(e.type == SDL_QUIT){
            gSDLGraphicsProgram.TerminateLoop();
		}
        // TODO Refactor the code such that you can change the background
        // TODO color based on the keypress 1, 2, or 3 to red, green, and blue.
        // TODO You can refactor however you like. A sample of finding a keydown
        // TODO event is otherwise shown.
        // TODO For help: 
        // TODO https://lazyfoo.net/tutorials/SDL/04_key_presses/index.php
        // Or a video tutorial on keyboard input: https://www.youtube.com/watch?v=piEekEUqvKY
        if(e.type == SDL_KEYDOWN){
            gSDLGraphicsProgram.SetClearColor(0.5,0.0,0.0,1.0);
        }else{
            gSDLGraphicsProgram.SetClearColor(0.0,0.5,0.0,1.0);
        }

	} // End SDL_PollEvent loop.

    //Disable text input
    //SDL_StopTextInput();
}

// Per frame update called in the main loop.
void Update(void){

}

// Per frame render called in the main loop
// Used for rendering geometry/graphics to the screen.
void Render(void){
    // Sets up the default rendering state in
    // OpenGL
    gSDLGraphicsProgram.SetDefaultOpenGLState();
}


// Default entry point into any C++ program
int main(int argc, char* argv[]){
	// Starting program
	std::cout << "Entry Point to Program\n";
	// Confirm our OpenGL Version Number
	gSDLGraphicsProgram.GetOpenGLVersionInfo();
    // Setup each of your function pointers before
    // the main loop.
    gSDLGraphicsProgram.SetPreLoopCallback(PreLoop);
    gSDLGraphicsProgram.SetInputCallback(Input);
    gSDLGraphicsProgram.SetUpdateCallback(Update);
    gSDLGraphicsProgram.SetRenderCallback(Render);
	// Run our program forever in an infinite loop
    // Your 'infinite loop' will calle each of the
    // callsbacks in the order of Input->Update->Render
    // (PreLoopCallback is called once before the loop)
	gSDLGraphicsProgram.Loop();
	// When our program ends, it will exit scope, the
	// destructor will then be called and clean up the program.
	return 0;
}
