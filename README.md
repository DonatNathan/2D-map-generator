# 2D Map Generator

This is a simple map generator using procedural generation.

## Prerequises

Linux :
```
sudo pacman -Sy sdl2
```

## Compilation

Linux :
```
git clone git@github.com:DonatNathan/2D-map-generator.git
cd 2D-map-generator
make
```

## Launch the game

Linux :
```
./map_generator <width> <height>
```

### Arguments
Arg | Description
--- | -----------
width | Represent the width of the map
height | Represent the height of the map

## Ingame inputs

Input | Action
----- | ------
I | Display/Hide informations
A | Display/Hide colors
Left Arrow | Go to the previous iteration
Right Arrow | Go to the next iteration
Upper Arrow | Increase noise percentage
Lower Arrow | Decrease noise percentage
Enter | Save map on map.txt

## Examples of render

### Original
![map](https://github.com/DonatNathan/2D-map-generator/assets/91681379/494d7433-be77-457c-adeb-717f76ed0971)


### Colorful
![map_coloful](https://github.com/DonatNathan/2D-map-generator/assets/91681379/7b615d56-e1ed-4b60-8377-f5ef74980492)

