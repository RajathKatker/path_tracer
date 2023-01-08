#include<iostream>

int ppm_image_gen(int width, int height)
{
  std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = 0; j < height; j++) 
    {
        for (int i = 0; i < width; i++)
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