# paint_c

This program is a very simplified version of paint, implemented in C using SDL. It's my first program using any rendering software, and implements mainly the SDL_FillRect functions.

The main reasons why I decided to take this project on was to learn the basics of working with SDL, as well as actually designing something that isn't strictly within the terminal

The user can select between 8 different colours, and can draw on a grid of 24x24, as well as save their drawing to a .bmp file.

## Download and Use

***Make sure you have SDL installed on your computer***

+ Simply clone the repository and compile and you're all set!
+ After running, the window will open automatically, and you can get drawing away

As of right now, the pink box in the top right of the program is the "Save" button

## Keyboard Bindings

There is only two types of input being tracked:
1. Esc - To exit and end the program
2. Left-Click - To select clours and draw squares

## Future Additions / Considerations

+ Be able to name files
+ Load files from memory and edit them
+ Change the size of the screen and grid
+ Change brush size
+ Draw straight lines by holding shift while dragging
