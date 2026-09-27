#include "image_Class.h"
#include <iostream>
using namespace std;
int z ;
void lines(Image& image, int design) {
    int w = image.width;
    int h = image.height;
    for (int i = 0; i < 2; i++) {
        for (int j = design; j < w - design; j++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
    for (int i = h - 2; i < h; i++) {
        for (int j = design; j < w - design; j++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
    for (int j = 0; j < 2; j++) {
        for (int i = design; i < h - design; i++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
    for (int j = w - 2; j < w; j++) {
        for (int i = design; i < h - design; i++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
    for (int i = 6; i < 9; i++) {
        for (int j = design; j < w - design; j++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
    for (int i = h - 9; i < h - 6; i++) {
        for (int j = design; j < w - design; j++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
    for (int j = 6; j < 9; j++) {
        for (int i = design; i < h - design; i++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
    for (int j = w - 9; j < w - 6; j++) {
        for (int i = design; i < h - design; i++) {
            image(j, i, 0) = 255;
            image(j, i, 1) = 255;
            image(j, i, 2) = 255;
        }
    }
}
void filter_4_2(Image& image) {
    int design;
    cin >> design;
    int arm = design/3;
    for (int i = 0; i < design; i++) {
        for (int j = 0; j < design; j++) {
            bool first = i<2 ||j<2||(i>=design-2&&j<arm)||(j>=design-2&&i<arm);
            bool second =(i >= 4 && i < 6 && j < design - 4) ||(j >= 4 && j < 6 && i < design - 4);
            if (first) {
                for (int k = 0; k < 3; k++) {
                    image(j,i,k)=255;
                }
            }else if (second) {
                for (int k = 0; k < 3; k++) {
                    image(j,i,k)=255;
                }
            }
        }
    }
    int dot = 4;
    for (int i = 0; i < dot; i++) {
        for (int j = 0; j < dot; j++) {
            for (int k = 0; k < 3; k++) {
                image(j,i,k)=255;
            }
        }
    }for (int i = 0; i < design; i++) {
        for (int j = image.width-design; j < image.width; j++) {
            bool first = i < 2 || j >= image.width - 2 || (i >= design - 2 && j >= image.width - arm) || (j < image.width - design + 2 && i < arm);

            bool second = (i >= 4 && i < 6 && j >= image.width - design + 4) || (j >= image.width - 6 && j < image.width - 4 && i < design - 4);

            if (first) {
                for (int k = 0; k < 3; k++) {
                    image(j, i, k) = 255;
                }
            }
            else if (second) {
                for (int k = 0; k < 3; k++) {
                    image(j, i, k) = 255;
                }
            }
        }
    }for (int i = 0; i < dot; i++) {
        for (int j = image.width-dot; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                image(j,i,k)=255;
            }
        }
    }for (int i = image.height - design; i < image.height; i++) {
        for (int j = 0; j < design; j++) {
            bool first = i >= image.height - 2 || j < 2 || (i < image.height - design + 2 && j < arm) || (j >= design - 2 && i >= image.height - arm);
            bool second = (i >= image.height - 6 && i < image.height - 4 && j < design - 4) || (j >= 4 && j < 6 && i >= image.height - design + 4);
            if (first) {
                for (int k = 0; k < 3; k++) {
                    image(j, i, k) = 255;
                }
            }
            else if (second) {
                for (int k = 0; k < 3; k++) {
                    image(j, i, k) = 255;
                }
            }
        }
    }for (int i = image.height - dot; i < image.height; i++) {
        for (int j = 0 ; j < dot; j++) {
            for (int k = 0; k < 3; k++) {
                image(j,i,k)=255;
            }
        }
    }for (int i = image.height - design; i < image.height; i++) {
        for (int j = image.width - design; j < image.width; j++) {
            bool first =i >= image.height - 2 || j >= image.width - 2 ||(i < image.height - design + 2 && j >= image.width - arm) ||(j < image.width - design + 2 && i >= image.height - arm);
            bool second =(i >= image.height - 6 && i < image.height - 4 && j >= image.width - design + 4) || (j >= image.width - 6 && j < image.width - 4 && i >= image.height - design + 4);
                if (first) {
                for (int k = 0; k < 3; k++) {
                    image(j, i, k) = 255;
                }
            }
            else if (second) {
                for (int k = 0; k < 3; k++) {
                    image(j, i, k) =  255;
                }
            }
        }
    }
    for (int i = image.height - dot; i < image.height; i++) {
        for (int j = image.width - dot; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;
            }
        }
    }
    lines(image,design);
}
void filter_4(Image& image) {
    int thickness;
    cin >> thickness;
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            if (i < thickness ||i >= image.height - thickness ||j < thickness ||j >= image.width - thickness) {
                for (int k = 0; k < 3; k++) {
                    if (k==0) {
                        image(j,i,k)=0;
                    }else if (k==1) {
                        image(j,i,k)=0;
                    }else {
                        image(j,i,k)=255;
                    }
                }
            }
        }
    }
}
Image filter_8(Image& image) {
    int oldWidth = image.width;
    int oldHeight = image.height;
    int newWidth, newHeight;
    cin >> newWidth;
    cin >> newHeight;
    Image result(newWidth,newHeight);
    double scale1 =(double)oldWidth/newWidth;
    double scale2 =(double)oldHeight/newHeight;
    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int x= (int) (i*scale1);
            int y= (int) (j*scale2);
            for (int k = 0; k < 3; k++) {
                result.setPixel(i, j, k, image.getPixel(x,y,k));
            }
        }
    }
    return result;
}
int main() {
    cin >> z;
    if (z==0){
        Image image;
            image.loadNewImage("cry.jpg.jpg");
            filter_4_2(image);
            image.saveImage("cry.jpg.png");
            return 0;
    }else if (z==4) {
        Image image;
        image.loadNewImage("cry.jpg.jpg");
        filter_4(image);
        image.saveImage("cry.jpg.png");
        return 0;
    }else if (z==40) {
        Image image;
        image.loadNewImage("cry.jpg.jpg");
        filter_4(image);
        filter_4_2(image);
        image.saveImage("cry.jpg.png");
        return 0;
    }
    else if (z==8) {
        Image image;
        image.loadNewImage("Wano 2.jpg.jpg");
        Image resized = filter_8(image);
        resized.saveImage("Wano 2.jpg.png");
        return 0;
    }
}
