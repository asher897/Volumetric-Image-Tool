# Volumetric-Image-Tool
A volumetric image tool to load a stack of 2D images and manipulate them as a group. This was created in response to an assignment. The pictures and Python files were received and not created by me.

# Files
### volImage.h
This is the header file. It contains the class VolImage with it's
public and private member variables and functions.

### volImage.cpp
This is the implementation file which defines all the methods, constructor (only default) and destructor.
It contains all the methods in the header file.

### driver.cpp
This is the main driver file. This is used to create the executable to perform the various functions defined.

### Makefile
The makefile compiles the abovementioned files and creates the binary files and the executable (volimage.exe).

### viewer.py
This file is used to render .raw images.<br>
`python viewer.py <filename> <width> <height>`

## Image Files
An exmaple direcotry of image files is given in `brain_mri_raws`. Each collection of files has a header file, a `.data` binary file. This specifies the `width height number_of_images`, in that order. The width and height refers to the pixels in each image and the number_of_images is the amount of images in the sequence. The remaining files are .raw binary files of brain mri scans.

# Building the Program
The makefile can be called with the "make" command line instruction in the linux terminal.

# Running the program
Once compiled the program can be run in various ways:<br>
`./volimage &ltimage base&gt [-d i j output_file_name] [-x i output_file_name]`

### -d i j output_file_name
This will compute a difference map between image slices i and j and writes it out to a file with file name equal to output_file_name.

### -x i output_file_name
This extracts the slice with index i and writes it out to a file with file name equal to output_file_name.

### No optional commands given
This will display:<br>
The number of Images: (int)<br>
The number of bytes required: (int)<br>
(this is the number of bytes required to store the images)

In all 3 cases, image_base is the base name of the images used for these functions. In the case of this assignment it was "brain_mri_raws/MRI".
Therefore, an example of a command line instruction would be './volimage brain_mri_raws/MRI -x 10 output_file_name' and this would perform the
extraction operation on slice 10 of the MRI image files and output the result to a file called output_file_name.raw.
