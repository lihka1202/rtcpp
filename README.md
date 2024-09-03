# rtcpp

A Ray tracing in C++ (Demo).
A lot of this is from the `Ray Tracing in one weekend` Course. I'll be experimenting randomly to see if things are the way I expect them to be, or if I understand things to be what they need to be.

# Outputting a basic image
The basic image is done by creating a plain text ppm (Portable PixMap).
Here is a good descriptipon of this picked from [here](https://paulbourke.net/dataformats/ppm/).
>A PPM file consists of two parts, a header and the image data. The header consists of at least three parts normally delineated by carriage returns and/or linefeeds but the PPM specification only requires white space. The first "line" is a magic PPM identifier, it can be "P3" or "P6" (not including the double quotes!). The next line consists of the width and height of the image as ASCII numbers. The last part of the header gives the maximum value of the colour components for the pixels, this allows the format to describe more than single byte (0..255) colour values. In addition to the above required lines, a comment can be placed anywhere with a "#" character, the comment extends to the end of the line.

For any file, P3 usually mean that this is in text.
Each line is following a new line character
```
P3 3 2
255
255 0 0     0 255 0     0 0 255
255 255 0   255 255 255     0 0 0
```
