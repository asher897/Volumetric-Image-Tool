#include "volImage.h"

using namespace SHRAAR001;

int main(int argc, char *argv[]){

    VolImage *vol = new VolImage;
    std::string fileSeq(argv[1]);

    vol -> readImages(fileSeq);

    std::ifstream infile(fileSeq + ".data");
    int numImages;
    infile >> numImages;
    infile >> numImages;
    infile >> numImages;
    infile.close();

    std::cout << "Number of images: " << numImages << std::endl;
    std::cout << "Number of bytes required: " << vol -> volImageSize() << std::endl;

    if(argc > 2){

        std::string op(argv[2]);

        if(op.compare("-d") == 0){
            std::string arg1(argv[3]);
            std::string arg2(argv[4]);
            std::string outputFile(argv[5]);        

            int i = std::stoi(arg1);
            int j = std::stoi(arg2);

            vol -> diffmap(i, j, outputFile);
            std::cout << "Calculated difference map using slices " << i << " and " << j << " and wrote output to file " << outputFile <<"." << std::endl;

        }else if(op.compare("-x") == 0){;
            std::string arg1(argv[3]);
            std::string outputFile(argv[4]);

            int i = std::stoi(arg1);

            vol -> extract(i, outputFile);
            std::cout << "Performed extract operation using slice " << i << " and wrote output to file " << outputFile <<"." << std::endl;

    }
    


    }

    delete vol;
}