#include <iostream>
#include <fstream>
#include <sstream>
#include "PPM.hpp"

// Constructor loads a filename with the .ppm extension
PPM::PPM(std::string fileName){
    // TODO:    Load and parse a ppm to get its pixel
    //          data stored properly.
    m_PixelData = new std::vector<uint8_t>();
	// open up a file
	std::ifstream inputFile;
	inputFile.open(fileName);

    bool foundP3 = false;
	bool foundDimensions = false;
	bool foundRange = false;
	// bool readingPixels = false;

    // If file successfully open up
	if (inputFile.is_open()) {
		std::cout << fileName << " was open\n";
		std::string line;
		while (std::getline(inputFile, line)) {
			std::stringstream stream(line);
			// Read each space separated char
			std::string chunk_of_data;
			while (stream >> chunk_of_data) {
				// Handle comments
				if (chunk_of_data[0] == '#') {
					std::cout << "comment: " << line << std::endl;
					break;
				} 
				else if (false==foundP3) {
					if(chunk_of_data == "P3") {
						std::cout << "Found P3: " << line << std::endl;
					}
					foundP3 = true;
				} else if (false==foundDimensions) {
                    std::cout << "Found width and height: " << line << std::endl;
					m_width = std::stoi(chunk_of_data);
					stream >> chunk_of_data;
					m_height = std::stoi(chunk_of_data);
					foundDimensions = true;
				} else if (false==foundRange) {
					std::cout << "Found range: " << line << std::endl;
					foundRange = true;
				} else {
                    int data = std::stoi(chunk_of_data);
					m_PixelData->push_back((uint8_t)data);
				}
			}
		}
		inputFile.close();
	}
}

// Destructor deletes(delete or delete[]) any memory that has been allocated
// or otherwise calls any 'shutdown' or 'destroy' routines for this deletion
// to occur.
PPM::~PPM(){
    // TODO: Reclaim any allocated memory
    delete m_PixelData;
}

// Saves a PPM Image to a new file.
void PPM::savePPM(std::string outputFileName) const {
    // TODO: Save a PPM image to disk
    std::ofstream myFile;
	myFile.open(outputFileName);
	myFile << "P3\n";
	myFile << "# saved by us\n";
    myFile << getWidth() << " " << getHeight() << '\n';
	myFile << "255\n";
    std::vector<uint8_t>* myPixelData = pixelData();
	for (uint8_t& pixelValue : *myPixelData) {
		myFile << (int)pixelValue << "\n";
	}
	myFile.close();
}

// Darken halves (integer division by 2) each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be less than
// 0 in a ppm.
void PPM::darken(){
    // TODO: Output a 'filtered' PPM image.
    std::vector<uint8_t>* myPixelData = pixelData();
	for (uint8_t& pixelValue : *myPixelData) {
        int darkenValue = (int)pixelValue / 2;
        pixelValue = (uint8_t)std::clamp(darkenValue, 0, 255);
	}
}

// Lighten doubles (integer multiply by 2) each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be greater than
// 255 in a ppm.
void PPM::lighten(){
    // TODO: Output a 'filtered' PPM image.
    std::vector<uint8_t>* myPixelData = pixelData();
	for (uint8_t& pixelValue : *myPixelData) {
        int lightenValue = (int)pixelValue * 2;
        pixelValue = std::clamp(lightenValue, 0, 255);
	}
}

// Sets a pixel to a specific R,G,B value 
// Note: You do not *have* to use setPixel in your implementation, but
//       it may be useful to implement.
void PPM::setPixel(int x, int y, uint8_t R, uint8_t G, uint8_t B){
    // TODO: Optional to implement.
}
