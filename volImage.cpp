#include "volImage.h"
#include <iostream>
#include <fstream>

using namespace SHRAAR001;

VolImage::VolImage(){
    width = 0;
    height = 0;
};
VolImage::~VolImage(){
    for(int i = 0; i < slices.size(); i++){
        for(int j = 0; j < height; j++){
            delete[] slices[i][j];
        }
        delete[] slices[i];
    }
};

bool VolImage::readImages(std::string &baseName){
    std::ifstream infile(baseName + ".data");

    if(!infile){
        std::cerr << "File not found." << std::endl;
        return false;
    }
    int numImages;
    infile >> width >> std::ws >> height >> std::ws >> numImages;
    infile.close();

    std::cout << "width: " << width << " height: " << height << std::endl;



    for(int sliceIndex = 0; sliceIndex < numImages; sliceIndex++){
        std::fstream inRaw(baseName + std::to_string(sliceIndex)  + ".raw", std::ios::in | std::ios::binary);
        slices.push_back(new unsigned char*[int(height)]);
        
        for(int i = 0; i < height; i++){
            slices[sliceIndex][i] = new unsigned char[int(width)];
            inRaw.read(reinterpret_cast<char*>(slices[sliceIndex][i]), width);
        }

        inRaw.close();
    }

    return true;
    
}

void VolImage::diffmap(int &sliceI, int &sliceJ, std::string &output_prefix){
    std::fstream outFile(output_prefix + ".raw", std::ios::out | std::ios::binary);

    for(int row = 0; row < height; ++row){

            for(int col = 0; col < width; ++col){
                outFile << (unsigned char)(abs((float)slices[sliceI][row][col] - (float)slices[sliceJ][row][col])/2);
            }

        }

    outFile.close();

}


void VolImage::extract(int &sliceId, std::string &output_prefix){
    std::fstream outFile(output_prefix + ".raw", std::ios::out | std::ios::binary);

    std::ofstream dataFile(output_prefix + ".data");
    dataFile << width << " " << height << " 1" << std::endl;
    dataFile.close();
        
        for(int i = 0; i < height; i++){

            outFile.write(reinterpret_cast<char *>(slices[sliceId][i]), width);
            
        }

        outFile.close();
    
}

int VolImage::volImageSize(void){
    return slices.size()*height*width + (slices.size()*height*8) + slices.size()*8;
}

void VolImage::extractNew(int &rowId, std::string &output_prefix) {
    std::ofstream output_file(output_prefix + ".raw", std::ios::out | std::ios::binary);

    for( int image = 0; image < slices.size(); ++image ) {

        output_file.write(reinterpret_cast<char *>(slices[image][rowId]), width);

    }


    output_file.close();
}

double VolImage::getHeight() {
    return height;
}