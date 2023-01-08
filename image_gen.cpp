#include<iostream>
#include<cmath>

int ppm_image_gen(int width, int height)
{
  std::cout << "P3\n" << width << ' ' << height << "\n255\n";

  int x_repeat = (width/256);
  int y_repeat = (height/256);

  if (x_repeat <= 1 && y_repeat <= 1) 
    {
      for (int i = 0; i < height; i++) 
        {
          for (int j = 0; j < width; j++)
            {
              auto r = double(i) / (width - 1);
              auto g = double(j) / (height - 1);
              auto b = 0.25;

              int red = static_cast<int>(255.999 * r);
              int green = static_cast<int>(255.999 * g);
              int blue = static_cast<int>(255.999 * b);

              std::cout << red << ' ' << green << ' ' << blue << '\n';
            }
        }
    }    
    else 
    {
      x_repeat = round(x_repeat);
      y_repeat = round(y_repeat);
      int red, green, blue;
      
      for (int i = 0; i < height; i + y_repeat) 
        {
          for (int j = 0; j < width; j + x_repeat)
            {
              auto r = double(i) / (width - 1);
              auto g = double(j) / (height - 1);
              auto b = 0.25;

              red = static_cast<int>(255.999 * r);
              green = static_cast<int>(255.999 * g);
              blue = static_cast<int>(255.999 * b);

              for(int k = 0; k < x_repeat; k++)
                {
                  std::cout << red << ' ' << green << ' ' << blue << '\n';
                }
            }
          for(int l = 0; l < y_repeat; l++)
            {
              std::cout << red << ' ' << green << ' ' << blue << '\n';
            }
        }
    }

  return 0;  
} 

int main()
{
  int width, height;

  std::cout << "Width : ";
  std::cin >> width;
  std::cout << "Height : ";
  std::cin >> height;

  ppm_image_gen(width,height);
    
  return 0;
}