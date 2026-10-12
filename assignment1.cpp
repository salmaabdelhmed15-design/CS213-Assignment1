/*
 * Ahmed Mohamed Saad Azzam    20250053   filter --> 1,5,9,13
 * Ammar Weal Ezzat            20250414   filter --> 2,6,10,14
 * Karim Mohamed Kamel         20250491   filter --> 3,7,11,15
 * Salma Abdelhameed Ibrahim   20251193   filter --> 4,8,12,16
   NUMsec 9,10
*/
#define _CRT_SECURE_NO_WARNINGS
#include "image_Class.h"
#include <bits/stdc++.h>
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
	cout << "Enter design value: ";
	cin >> design;
	int arm = design / 3;
	for (int i = 0; i < design; i++) {
		for (int j = 0; j < design; j++) {
			bool first = i < 2 || j < 2 || (i >= design - 2 && j < arm) || (j >= design - 2 && i < arm);
			bool second = (i >= 4 && i < 6 && j < design - 4) || (j >= 4 && j < 6 && i < design - 4);
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
	}
	int dot = 4;
	for (int i = 0; i < dot; i++) {
		for (int j = 0; j < dot; j++) {
			for (int k = 0; k < 3; k++) {
				image(j, i, k) = 255;
			}
		}
	}
	for (int i = 0; i < design; i++) {
		for (int j = image.width - design; j < image.width; j++) {
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
	}
	for (int i = 0; i < dot; i++) {
		for (int j = image.width - dot; j < image.width; j++) {
			for (int k = 0; k < 3; k++) {
				image(j, i, k) = 255;
			}
		}
	}
	for (int i = image.height - design; i < image.height; i++) {
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
	}
	for (int i = image.height - dot; i < image.height; i++) {
		for (int j = 0; j < dot; j++) {
			for (int k = 0; k < 3; k++) {
				image(j, i, k) = 255;
			}
		}
	}
	for (int i = image.height - design; i < image.height; i++) {
		for (int j = image.width - design; j < image.width; j++) {
			bool first = i >= image.height - 2 || j >= image.width - 2 || (i < image.height - design + 2 && j >= image.width - arm) || (j < image.width - design + 2 && i >= image.height - arm);
			bool second = (i >= image.height - 6 && i < image.height - 4 && j >= image.width - design + 4) || (j >= image.width - 6 && j < image.width - 4 && i >= image.height - design + 4);
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
	}
	for (int i = image.height - dot; i < image.height; i++) {
		for (int j = image.width - dot; j < image.width; j++) {
			for (int k = 0; k < 3; k++) {
				image(j, i, k) = 255;
			}
		}
	}
	lines(image, design);
}
void filter_4(Image& image) {
	int thickness;
	cout << "Enter frame thickness: ";
	cin >> thickness;
	for (int i = 0; i < image.height; i++) {
		for (int j = 0; j < image.width; j++) {
			if (i < thickness || i >= image.height - thickness || j < thickness || j >= image.width - thickness) {
				for (int k = 0; k < 3; k++) {
					if (k == 0) {
						image(j, i, k) = 0;
					}
					else if (k == 1) {
						image(j, i, k) = 0;
					}
					else {
						image(j, i, k) = 255;
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
	cout << "Enter new width: ";
	cin >> newWidth;
	cout << "Enter new height: ";
	cin >> newHeight;
	Image result(newWidth, newHeight);
	double scale1 = (double)oldWidth / newWidth;
	double scale2 = (double)oldHeight / newHeight;
	for (int i = 0; i < newWidth; i++) {
		for (int j = 0; j < newHeight; j++) {
			int x = (int)(i * scale1);
			int y = (int)(j * scale2);
			for (int k = 0; k < 3; k++) {
				result.setPixel(i, j, k, image.getPixel(x, y, k));
			}
		}
	}
	return result;
}
Image resizeForMerge(Image& image, int newWidth, int newHeight){
	int oldWidth = image.width;
	int oldHeight = image.height;
	Image resized(newWidth, newHeight);
	double scaleX = (double)oldWidth / newWidth;
	double scaleY = (double)oldHeight / newHeight;
	for (int x = 0; x < newWidth; x++){
		for (int y = 0; y < newHeight; y++){
			int oldX = (int)(x * scaleX);
			int oldY = (int)(y * scaleY);
			for (int k = 0; k < 3; k++){
				resized.setPixel(x, y, k,image.getPixel(oldX, oldY, k));
			}
		}
	}
	return resized;
}
Image mergeImages(Image& img1, Image& img2){
	int width = img1.width;
	int height = img1.height;
	Image result(width, height);
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			for (int k = 0; k < 3; k++){
				int pixel1 = img1.getPixel(x, y, k);
				int pixel2 = img2.getPixel(x, y, k);
				int average = (pixel1 + pixel2) / 2;
				result.setPixel(x, y, k, average);
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
	image = result;
}
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
void filter_18(Image& image, int radius) {
    int width = image.width;
    int height = image.height;
    if (radius < 1) {
        cout << "Radius must be at least 1\n";
        return;
    }
    Image result(width, height);
    const int levels = 40;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int histogram[levels] = {};
            int sumR[levels] = {};
            int sumG[levels] = {};
            int sumB[levels] = {};
            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                        continue;
                    }
                    int r = image(nx, ny, 0);
                    int g = image(nx, ny, 1);
                    int b = image(nx, ny, 2);

                    int intensity = (r + g + b) / 3;
                    int bin = intensity * levels / 256;

                    histogram[bin]++;
                    sumR[bin] += r;
                    sumG[bin] += g;
                    sumB[bin] += b;
                }
            }
            int bestBin = 0;
            for (int i = 1; i < levels; i++) {
                if (histogram[i] > histogram[bestBin]) {
                    bestBin = i;
                }
            }
            int count = histogram[bestBin];
            if (count > 0) {
                result(x, y, 0) = sumR[bestBin] / count;
                result(x, y, 1) = sumG[bestBin] / count;
                result(x, y, 2) = sumB[bestBin] / count;
            }
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int k = 0; k < 3; k++) {
                image(x, y, k) = result(x, y, k);
            }
        }
    }
    cout << "Oil painting filter applied successfully!\n";
}
Image filter_13(Image& image){
	int width = image.width;
	int height = image.height;
	Image result(width, height);
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			int r = image.getPixel(i, j, 0);
			int g = image.getPixel(i, j, 1);
			int b = image.getPixel(i, j, 2);
			r = min(255, r + 40);
			g = min(255, g + 35);
			b = max(0, b - 15);
			result.setPixel(i, j, 0, r);
			result.setPixel(i, j, 1, g);
			result.setPixel(i, j, 2, b);
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
			cout << "9. Merge Images\n";
			cout << "10.Detect Image Edges\n";
			cout << "11. Crop Images\n";
			cout << "12. Blur Images\n";
			cout << "13. Sunlight / Brightness Filter\n";
			cout << "14. Television / Scanlines Filter\n";
			cout << "15. Purple Tint Filter\n";
			cout << "16. Infrared Photography Filter\n";
			cout << "17. Image Skewing Filter\n";
			cout << "18. Oil Painting Effect Filter\n";
			cout << "Enter choice: ";
			if (!(cin >> filter)) {
				cout << "Invalid filter choice!\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (filter == 1) {
				for (int i = 0; i < img1.width; ++i) {
					for (int j = 0; j < img1.height; ++j) {
						unsigned int avg = (img1(i, j, 0) + img1(i, j, 1) + img1(i, j, 2)) / 3;
						img1(i, j, 0) = avg;
						img1(i, j, 1) = avg;
						img1(i, j, 2) = avg;
					}
				}
				cout << "Grayscale Filter Applied Successfully!\n";
			}
			else if (filter == 2) {
				for (int i = 0; i < img1.width; ++i) {
					for (int j = 0; j < img1.height; ++j) {
						unsigned int avg = 0;
						for (int k = 0; k < img1.channels; ++k) {
							avg += img1(i, j, k);
						}
						avg = avg / 3;
						if (avg >= 128) {
							avg = 255;
						}
						else {
							avg = 0;
						}
						for (int k = 0; k < img1.channels; ++k) {
							img1(i, j, k) = avg;
						}
					}
				}
				cout << "Black and White Filter Applied Successfully!\n";
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
			else if (filter == 4) {
				int choice;
				cout << "1. Simple Frame\n";
				cout << "2. Fancy Frame\n";
				cout << "3. Both\n";
				cout << "Enter choice: ";
				cin >> choice;
				if (choice == 1) {
					filter_4(img1);
				}
				else if (choice == 2) {
					filter_4_2(img1);
				}
				else {
					filter_4(img1);
					filter_4_2(img1);
				}
				cout << "Frame Applied Successfully!\n";
			}
			else if (filter == 5) {
				int type;
				cout << "1. Horizontal Flip\n2. Vertical Flip\nEnter choice: ";
				cin >> type;
				if (type == 1) {
					for (int i = 0; i < img1.height; ++i) {
						for (int j = 0; j < img1.width / 2; ++j) {
							for (int k = 0; k < 3; ++k) {
								swap(img1(j, i, k), img1(img1.width - 1 - j, i, k));
							}
						}
					}
				}
				else if (type == 2) {
					for (int i = 0; i < img1.height / 2; ++i) {
						for (int j = 0; j < img1.width; ++j) {
							for (int k = 0; k < 3; ++k) {
								swap(img1(j, i, k), img1(j, img1.height - 1 - i, k));
							}
						}
					}
				}
				cout << "Flip Filter Applied Successfully!\n";
			}
			else if (filter == 6) {
				int angle;
				cout << "Enter Your angle (90, 180, 270): ";
				cin >> angle;
				if (angle == 90) {
					Image image_rotated_90(img1.height, img1.width);
					for (int x = 0; x < img1.width; ++x) {
						for (int y = 0; y < img1.height; ++y) {
							for (int z = 0; z < img1.channels; ++z) {
								image_rotated_90(img1.height - 1 - y, x, z) = img1(x, y, z);
							}
						}
					}
					img1 = image_rotated_90;
					cout << "Rotated 90 Degrees Successfully!\n";
				}
				else if (angle == 180) {
					Image image_rotated180(img1.width, img1.height);
					for (int x = 0; x < img1.width; ++x) {
						for (int y = 0; y < img1.height; ++y) {
							for (int z = 0; z < img1.channels; ++z) {
								image_rotated180(img1.width - 1 - x, img1.height - 1 - y, z) = img1(x, y, z);
							}
						}
					}
					img1 = image_rotated180;
					cout << "Rotated 180 Degrees Successfully!\n";
				}
				else if (angle == 270) {
					Image image_rotated_270(img1.height, img1.width);
					for (int x = 0; x < img1.width; ++x) {
						for (int y = 0; y < img1.height; ++y) {
							for (int z = 0; z < img1.channels; ++z) {
								image_rotated_270(y, img1.width - 1 - x, z) = img1(x, y, z);
							}
						}
					}
					img1 = image_rotated_270;
					cout << "Rotated 270 Degrees Successfully!\n";
				}
				else {
					cout << "Invalid angle! Please enter 90 , 180 , 270 " << endl;
				}
			}
			else if (filter == 7) {
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
			}
			else if (filter == 8) {
				img1 = filter_8(img1);
				cout << "Image Resized Successfully!\n";
			}else if (filter == 9) {
				if (img1.width <= 0 || img1.height <= 0) {
					cout << "Please load the first image first!\n";
					continue;
				}
				string filename2;
				Image img2;
				cout << "Enter filename2: ";
				cin >> filename2 ;
				if (!img2.loadNewImage(filename2)) {
					cout << "Failed to load second image!\n";
					continue;
				}
				if (img2.width <= 0 || img2.height <= 0) {
					cout << "Invalid second image!\n";
					continue;
				}
				if (img1.width != img2.width ||img1.height != img2.height) {
					img2 = resizeForMerge(img2, img1.width, img1.height);
				}
				img1 = mergeImages(img1, img2);
				cout << "Image merged successfully!\n";
			}else if (filter == 10) {
				for(int i = 0 ; i < img1.width-1; ++i){
					for(int j = 0 ; j < img1.height; ++j ){
						unsigned int avg = 0 ;
						unsigned int avg_next = 0 ;
						unsigned int diff = 0 ;
						for(int k = 0 ; k < img1.channels; ++k){
							avg += img1(i,j,k);
							avg_next += img1(i+1,j,k);}
						avg = avg/3 ;
						avg_next = avg_next/3 ;
						diff = abs((int)avg_next - (int)avg) ;
						if( diff >= 30){
							diff = 0 ;}
						else{
							diff = 255 ;
						}
						for(int k =0 ; k < img1.channels ; ++k){
							img1(i,j,k)= diff ;
						}
					}
				}
				cout << "Detect Image Edges successfully!\n";
			}else if (filter == 11) {
				int x, y, w, h;
				cout << "Enter Start Point ";
				cin >> x >> y;
				cout << "Enter Dimension ";
				cin >> w >> h;
				if (x >= 0 && y >= 0 && w > 0 && h > 0 && (x + w <= img1.width) && (y + h <= img1.height)) {
					Image croppedimage(w, h);
					for (int i = 0; i < w; ++i) {
						for (int j = 0; j < h; ++j) {
							for (int k = 0; k < 3; ++k) {
								croppedimage(i, j, k) = img1(i + x, j + y, k);
							}
						}
					}
					img1 = croppedimage;
					cout << "Crop Image Applied Successfully!\n";
				}
				else {
					cout << "Invalid dimensions!\n";
				}
			}else if (filter == 12) {
				int radius;
				cout << "Enter Blur Level: ";
				cin >> radius;
				filter_12(img1, radius);
				cout << "Blur Image Successfully!\n";
			}else if (filter == 13) {
				img1 = filter_13(img1);
				cout << "Sunlight Filter Applied Successfully!\n";
			}else if (filter == 14) {
				for (int y = 0; y < img1.height; ++y) {
					if (y % 2 == 0) {
						for (int x = 0; x < img1.width; ++x) {
							for (int z = 0; z < img1.channels; ++z) {
								img1.setPixel(x, y, z, 0);
							}
						}
					}
				}
				cout << "Television Filter Applied Successfully!\n";
			}else if (filter == 15) {
				for (int i = 0; i < img1.width; ++i) {
					for (int j = 0; j < img1.height; ++j) {
						int r = img1(i, j, 0) * 1.1;
						int g = img1(i, j, 1) * 0.7;
						int b = img1(i, j, 2) * 1.1;
						img1(i, j, 0) = min(255, r);
						img1(i, j, 1) = min(255, g);
						img1(i, j, 2) = min(255, b);
					}
				}
				cout << "Purple Tint Filter Applied Successfully!\n";
			}else if (filter == 16) {
				filter_16(img1);
				cout << "Infrared Photography Filter Successfully!\n";
			}else if (filter == 17) {
			}else if (filter == 18) {
				int radius = 3;
				filter_18(img1, radius);
				cout <<"Oil Painting Effect Filter successfully!\n";
			}else {
				cout << "Filter under development or invalid choice!\n";
			}
		}else if (savechoice == 3) {
			cout << "Enter new image name to save:\n";
			cin >> filename;

			if (img1.saveImage(filename)) {
				cout << "Image Saved Successfully as " << filename << "\n";
			}
			else {
				cout << "Failed to save the image!\n";
			}
		}else if (savechoice == 4) {
			cout << "BYE!\n";
			break;
		}else {
			cout << "Invalid choice!\n";
		}
	}
	return 0;
}