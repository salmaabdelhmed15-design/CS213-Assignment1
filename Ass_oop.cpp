/*salma
    */
#include "image_Class.h"
#include <bits/stdc++.h>
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
void filter_12(Image& image, int radius) {
	int w = image.width;
	int h = image.height;
	Image result = image;
	for (int c = 0; c < 3; c++) {
		vector<vector<long long>> sum(h + 1, vector<long long>(w + 1, 0));
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				sum[y][x] = image(x - 1, y - 1, c)
						  + sum[y - 1][x]
						  + sum[y][x - 1]
						  - sum[y - 1][x - 1];
			}
		}
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int left   = max(0, x - radius);
				int right  = min(w - 1, x + radius);
				int top    = max(0, y - radius);
				int bottom = min(h - 1, y + radius);
				long long total = sum[bottom + 1][right + 1]
								- sum[top][right + 1]
								- sum[bottom + 1][left]
								+ sum[top][left];
				int count = (right - left + 1) * (bottom - top + 1);
				result(x, y, c) = total / count;
			}
		}
	}
	image = result;}
void filter_16(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; k++) {
                avg += image(i,j,k);
            }
            avg = avg/3;
            image(i,j,0) = 255;
            image(i,j,1) = avg;
            image(i,j,2) = avg;
        }
    }
}
int main() {
    cin >> z;
    if (z==4) {
        int choice;
                cout << "1. Simple Frame\n";
                cout << "2. Fancy Frame\n";
                cout << "3. Both\n";
                cout << "Enter choice: ";
                cin >> choice;
                if (choice == 1) {
                    filter_4(img1);
                }else if (choice == 2) {
                    filter_4_2(img1);
                }else {
                    filter_4(img1);
                    filter_4_2(img1);
                }
            }
    }
    else if (z==8) {
        Image image;
        image.loadNewImage("Wano 2.jpg.jpg");
        Image resized = filter_8(image);
        resized.saveImage("Wano 2.jpg.png");
        return 0;
    }else if (z==12){
        int radius;
				cout << "Enter Blur Level: ";
				cin >> radius;
				filter_12(img1, radius);
    }else if(z==16){
        filter_16(img1);
    }
}
