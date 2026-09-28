#include "image_Class.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <limits>
using namespace std;
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
    Image img1;
    string filename;
    int savechoice;
    while (true) {
        cout << "\n=== AKS Filter ===\n";
        cout << "1. Load Image\n";
        cout << "2. Apply Filter\n";
        cout << "3. Save Image\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> savechoice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (savechoice == 1) {
            cout << "Enter File Name:\n";
            cin >> filename;

            if (img1.loadNewImage(filename)) {
                cout << "File Loaded Successfully\n";
            }
            else {
                cout << "Failed To Load Image. Check The File Name!\n";
            }
        }
        else if (savechoice == 2) {
            int filter;
            cout << "\n=== Choose filter ===\n";
            cout << "1. Grayscale Conversion\n";
            cout << "2. Black and White\n";
            cout << "3. Invert Image\n";
            cout << "4. Adding a Frame to the Picture\n";
            cout << "5. Flip Image\n";
            cout << "6. Rotate Image\n";
            cout << "7. Darken and Lighten Image\n";
            cout << "8. Resizing Images\n";
            cout << "Enter choice: ";

            if (!(cin >> filter)) {
                cout << "Invalid filter choice!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (filter == 2) {
                Image image("building.jpg");
                for(int i = 0 ; i < image.width; ++i){
                    for(int j = 0 ; j < image.height; ++j ){
                        unsigned int avg = 0 ;
                        for(int k = 0 ; k < image.channels; ++k ){
                            avg += image(i,j,k);
                        }
                        avg = avg/3 ;
                        if( avg >= 128){
                            avg = 255 ;
                        }
                        else{
                            avg = 0 ;
                        }
                        for(int k =0 ; k < image.channels ; ++k){
                            image(i,j,k)= avg ;
                        }
                    }
                }
            }
            else if (filter == 3) {
                cout << "Applying Invert Filter...\n";
                for (int i = 0; i < img1.height; ++i) {
                    for (int j = 0; j < img1.width; ++j) {
                        img1(j, i, 0) = 255 - img1(j, i, 0);
                        img1(j, i, 1) = 255 - img1(j, i, 1);
                        img1(j, i, 2) = 255 - img1(j, i, 2);
                    }
                }
                cout << "Invert Filter Applied Successfully!\n";
            }
            else if (filter == 0) {
                Image image;
                filter_4_2(image);
            }
            else if (filter == 4) {
                Image image;
                filter_4(image);
            }
            else if (filter == 40) {
                Image image;
                filter_4(image);
                filter_4_2(image);
            }else if (filter == 6) {
                int angle;
                cout << "Enter Your angle (90, 180, 270): ";
                cin >> angle;
                Image image2("BlueCar.jpg");
                Image image_rotated90(image2.height, image2.width); // for  angle = 90
                Image image_rotated180(image2.width, image2.height); // for angle =  180
                Image image_rotated270(image2.height, image2.width); // for angle =  270
                if (angle == 90){
                    for (int x = 0; x < image2.width; ++x){
                        for (int y = 0; y < image2.height; ++y){
                            for (int z = 0; z < image2.channels; ++z){
                                image_rotated90(image2.height - 1 - y, x, z) = image2(x, y, z);
                            }
                        }
                    }
                    image_rotated90.saveImage("BlueCar_Rotated90.png");
                }
                else if (angle==180){
                    for (int x = 0; x < image2.width; ++x){
                        for (int y = 0; y < image2.height; ++y){
                            for (int z = 0; z < image2.channels; ++z){
                                image_rotated180(image2.width - 1 - x, image2.height - 1 - y, z) = image2(x, y, z);
                            }
                        }
                    }
                    image_rotated180.saveImage("BlueCar_Rotated180.png");
                }
                else if ( angle == 270 ){
                    for (int x = 0; x < image2.width; ++x){
                        for (int y = 0; y < image2.height; ++y){
                            for (int z = 0; z < image2.channels; ++z){
                                image_rotated270(y, image2.width - 1 - x , z) = image2(x, y, z);
                            }
                        }
                    }
                    image_rotated270.saveImage("BlueCar_Rotated270.png");
                }
                else {
                    cout <<"Invalid angle! Please enter 90 , 180 , 270 "<<endl ;
                }
                image2.saveImage("BlueCar.jpg");
                image2.saveImage("building.png");
            }else if (filter == 7) {
                int choice;
                cout << "1. Darken Image (50%)\n";
                cout << "2. Lighten Image (50%)\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1) {
                    for (int i = 0; i < img1.height; ++i) {
                        for (int j = 0; j < img1.width; ++j) {
                            img1(j, i, 0) = img1(j, i, 0) / 2;
                            img1(j, i, 1) = img1(j, i, 1) / 2;
                            img1(j, i, 2) = img1(j, i, 2) / 2;
                        }
                    }
                    cout << "Darken Filter Applied Successfully!\n";
                }
                else if (choice == 2) {
                    for (int i = 0; i < img1.height; ++i) {
                        for (int j = 0; j < img1.width; ++j) {
                            for (int c = 0; c < 3; ++c) {
                                int newValue = (int)(img1(j, i, c) * 1.5);
                                if (newValue > 255) newValue = 255;
                                img1(j, i, c) = newValue;
                            }
                        }
                    }
                    cout << "Lighten Filter Applied Successfully!\n";
                }
                else {
                    cout << "Invalid choice!\n";
                }
            }else if (filter == 8) {
                Image image;
                image.loadNewImage("Wano 2.jpg.jpg");
                Image resized = filter_8(image);
                resized.saveImage("Wano 2.jpg.png");
            }
            else {
                cout << "Filter under development or invalid choice!\n";
            }
        }
        else if (savechoice == 3) {
            cout << "Enter new image name to save (e.g., output.jpg):\n";
            cin >> filename;

            if (img1.saveImage(filename)) {
                cout << "Image Saved Successfully as " << filename << "\n";
            }
            else {
                cout << "Failed to save the image!\n";
            }
        }
        else if (savechoice == 4) {
            cout << "BYE!\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}