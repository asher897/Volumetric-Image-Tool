#ifndef VOLIMAGE_H
#define VOLIMAGE_H

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

namespace SHRAAR001{}

class VolImage
{


    private: //private members
        double width, height;
        std::vector<unsigned char**> slices;

    public: //public members
        VolImage(); //default constructor
        ~VolImage(); // default constructor

        //populate the object with images in stack and
        //set member variables
        bool readImages(std::string baseName);

        //compute difference map and write out;
        void diffmap(int sliceI, int sliceJ, std::string output_prefix);

        //extract slice sliceId and write to output -
        void extract(int sliceId, std::string output_prefix);

        //number of bytes uses to store image data bytes
        //and pointers (ignore vector<> container, dims etc)
        int volImageSize(void); 

};

#endif