# Why am I making a voxel engine?
I'm making a voxel engine at the reccomendation of a friend of mine who encouraged me to use OpenGL to create the game from. This is mainly going to be used by me to create a game using OpenGL and learn the maths surrounding it.

# How to compile and use
### Ensure you have GLFW installed and (at the moment) are on a Linux-based system
#
### To install the GLFW dependency:
## On the main Debian operating systems:

Run:
```
sudo apt install glfw
```
or on Fedora:
```
sudo dnf install glfw
```
#
If you are on Arch Linux, run:
```
sudo pacman -S glfw
```
#
## Now that GLFW is installed the code can be compiled and executed.
### Open terminal and cd into the folder
An example command would be:
```
cd /home/<user>/Downloads/VoxelTest
```
#
Now that you are in the folder, you can use the makefile by running:
```
make run
```
And as long as you have GCC and G++ installed, the code will compile and run automatically.
#
## Any further use of the program can be executed without compiling by simply double clicking on the executeable file called "play"
