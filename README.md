# randwall
Wallpaper ramdomizer for windows 3.x. Runs on any processor in any windows mode.

Rotates through numbered wallpaper files by editing WIN.INI. Name all wallpapers you want rotated nnnnnnnnnxxx.BMP where n is the name (the same for every paper in the rotation set) and x is the number 1-255. E.g.:

paper1.bmp
paper2.bmp
paper3.bmp
...
paper199.bmp

Invoked with exactly one argument - the number of wallpapers (199 in the above example). I recommend adding it to the startup program group with the command line: randwall 199

Wallpaper will not change until next boot, all it does is change the number in WIN.INI.
