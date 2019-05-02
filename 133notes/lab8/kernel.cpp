#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
  char c;
  int x;
  ifstream instr; //open image
  instr.open("inImage.pgm"); //open image

  // read the header P2
  instr >> c;
  assert(c == 'P');
  instr >> c;
  assert(c == '2');

  // skip the comments (if any)
  while ((instr>>ws).peek() == '#') {
    instr.ignore(4096, '\n');
  }

  instr >> width;
  instr >> height;

  assert(width <= MAX_W);
  assert(height <= MAX_H);
  int max;
  instr >> max;
  assert(max == 255);

  for (int row = 0; row < height; row++)
    for (int col = 0; col < width; col++)
      instr >> image[row][col];
  instr.close();
  return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open("outImage.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };

  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      ostr << image[row][col] << ' ';
      ostr << endl;
    }
  }
  ostr.close();
  return;
}


int main() {

  int img[MAX_H][MAX_W];
  int h, w;

  readImage(img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data

  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  
  for(int row = 1; row < h-1; row++) {
    for(int col = 1; col < w-1; col++) {
      int a=img[row-1][col-1];
      int b=img[row-1][col];
      int c=img[row-1][col+1];
      int d=img[row][col-1];
      int e=img[row][col];
      int f=img[row][col+1];
      int g=img[row+1][col-1];
      int h=img[row+1][col];
      int i=img[row+1][col+1];
      int temp = (g+2*h+i)-(a+2*b+c);
      if(temp<0){
	out[row][col] = 0;
      }
      else if(temp>255){
	out[row][col] = 255;
      }
      else{
	out[row][col] = temp;
      }
      //std::cout << img[row][col] << std::endl;
    }
  }

// and save this new image to file "outImage.pgm"
  writeImage(out, h, w);
}
