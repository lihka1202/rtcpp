#include <iostream>

int main()
{
    // Image choices
    int image_width = 256;
    int image_height = 256;

    // Render
    std::cout << "P3\n"
              << image_width << " " << image_height << "\n255\n";
    
    for (int i = 0; i < image_height; i +=1) {
        for(int j = 0; j < image_width; j+= 1) {
            // Create the gradient

            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * g);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';

        }
    }
}