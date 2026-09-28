#include"Image_Class.h"
#include<iostream>
using namespace std ;
int main()
{
 Image image("building.jpg");
 for(int i = 0 ; i < image.width; ++i)
 {
    for(int j = 0 ; j < image.height; ++j )
    {
        unsigned int avg = 0 ;
        
        for(int k = 0 ; k < image.channels; ++k )
        {
            avg += image(i,j,k);
        }
        avg = avg/3 ;
        if( avg >= 128)
        {
            avg = 255 ;
        }
        else
        {
            avg = 0 ;
        }
        for(int k =0 ; k < image.channels ; ++k)
        {
            image(i,j,k)= avg ;
        }
    }
 }
 int angle;
    cout << "Enter Your angle (90, 180, 270): ";
    cin >> angle;
    Image image2("BlueCar.jpg");
Image image_rotated90(image2.height, image2.width); // for  angle = 90 
Image image_rotated180(image2.width, image2.height); // for angle =  180 
Image image_rotated270(image2.height, image2.width); // for angle =  270 
if (angle == 90)
{
    for (int x = 0; x < image2.width; ++x)
    {
        for (int y = 0; y < image2.height; ++y)
        {
            for (int z = 0; z < image2.channels; ++z)
            {
                image_rotated90(image2.height - 1 - y, x, z) = image2(x, y, z);
            }
        }
    }
    image_rotated90.saveImage("BlueCar_Rotated90.png");
}
else if (angle==180)
{
     for (int x = 0; x < image2.width; ++x)
    {
        for (int y = 0; y < image2.height; ++y)
        {
            for (int z = 0; z < image2.channels; ++z)
            {
                image_rotated180(image2.width - 1 - x, image2.height - 1 - y, z) = image2(x, y, z);
            }
        }
    }
    image_rotated180.saveImage("BlueCar_Rotated180.png");
}
else if ( angle == 270 )
{
     for (int x = 0; x < image2.width; ++x)
    {
        for (int y = 0; y < image2.height; ++y)
        {
            for (int z = 0; z < image2.channels; ++z)
            {
                image_rotated270(y, image2.width - 1 - x , z) = image2(x, y, z);
            }
        }
    }
    image_rotated270.saveImage("BlueCar_Rotated270.png");
}
else 
{
 cout <<"Invalid angle! Please enter 90 , 180 , 270 "<<endl ;
}

image2.saveImage("BlueCar.jpg");
image.saveImage("building.png");
return 0;
}
