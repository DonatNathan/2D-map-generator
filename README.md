# 2D Map Generator

This is a simple map generator using procedural generation.

## Prerequises

Linux :
```
sudo pacman -Sy sfml
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

## Examples of render

### Original
![image](https://github.com/DonatNathan/Map-Generator-2D/assets/91681379/9c1344c6-28c3-4c64-a0eb-7cde0307d9f5)

### Colorful
