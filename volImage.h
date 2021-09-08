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


    private:
        double width, height;
        std::vector<unsigned char**> slices;

    public:
        VolImage();
        ~VolImage();

        bool readImages(std::string &baseName);

        void diffmap(int &sliceI, int &sliceJ, std::string &output_prefix);

        void extract(int &sliceId, std::string &output_prefix);

        void extractNew(int &sliceId, std::string &output_prefix);

        int volImageSize(void);

        double getHeight();

};

#endif