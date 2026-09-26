#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <limits>
#include "Image_Class.h"

using namespace std;

int main() {
    Image img1;
    string filename;
    int savechoice;

    while (true) {
        cout << "\n=== Karim al F7l ===\n";
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

            if (filter == 3) {
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