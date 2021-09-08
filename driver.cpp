#include "volImage.h"

using namespace SHRAAR001;

int main(int argc, char *argv[]){

    VolImage *vol = new VolImage;
    std::string fileSeq(argv[1]);

    vol -> readImages(fileSeq);

    std::ifstream infile(fileSeq + ".data");
    int numImages = 0;
    infile >> numImages;
    infile >> numImages;
    infile >> numImages;
    infile.close();

    if(argc > 2){

        std::string op(argv[2]);

        if(op.compare("-d") == 0){
            std::string arg1(argv[3]);
            std::string arg2(argv[4]);
            std::string outputFile(argv[5]);        

            int i = std::stoi(arg1);
            int j = std::stoi(arg2);
            if( i > numImages || j > numImages ) {
                std::cerr << "The slices specified are too high.";
                return 0;
            }

            vol -> diffmap(i, j, outputFile);
            std::cout << "Calculated difference map using slices " << i << " and " << j << " and wrote output to file " << outputFile <<"." << std::endl;

        }else if(op.compare("-x") == 0){;
            std::string arg1(argv[3]);
            std::string outputFile(argv[4]);

            int i = std::stoi(arg1);
            if( i > numImages ) {
                std::cerr << "The slice specified are too high.";
                return 0;
            }

            vol -> extract(i, outputFile);
            std::cout << "Performed extract operation using slice " << i << " and wrote output to file " << outputFile <<"." << std::endl;

    }

    std::cout << "Number of images: " << numImages << std::endl;
    std::cout << "Number of bytes required: " << vol -> volImageSize() << std::endl;
    


    }

    delete vol;
}