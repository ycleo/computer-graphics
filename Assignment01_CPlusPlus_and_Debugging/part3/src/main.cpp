// Include our custom library
#include "PPM.hpp"

void unitTest1(){
    // Darken Test
    PPM myPPM("./../../common/textures/big_buck_bunny_blender3d.ppm");
    myPPM.darken();
    myPPM.savePPM("./darken.ppm");
}

void unitTest2(){
    // Lighten Test
    PPM myPPM2("./../../common/textures/big_buck_bunny_blender3d.ppm");
    myPPM2.lighten();
    myPPM2.savePPM("./lighten.ppm");    
}
 
void unitTest3(){
    // More difficult parsing test
    // If you open this file up you'll notice that the formatting is a bit
    // more weird.
    PPM myPPM3("./../../common/textures/big_buck_bunny_blender3d_with_weird_formatting.ppm");
    myPPM3.lighten();
    myPPM3.savePPM("./parse.ppm"); 
}


// Entry point into the program
int main(int argc, char* argv[]){

    // Run each unit test one after the other
    unitTest1();
    unitTest2();
    unitTest3();
    
    return 0;
}
