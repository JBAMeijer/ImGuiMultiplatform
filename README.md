# Dev-1
This branch has some changes that are not yet part of the main branch.\
These changes are:
* Windowhints. In this case GLFW specific ones.

# ImGuiMultiplatform

`git clone --recursive git@github.com:JBAMeijer/ImGuiMultiplatform.git`

# Setup
## Windows
## ubuntu 22.04
### glfw
Glfw is included in this project.
Requires x11 dependencies to work.\
`sudo apt install xorg-dev`
### Vulkan
Install from:\
https://vulkan.lunarg.com/sdk/home#linux\
Follow instructions from:\
https://vulkan.lunarg.com/doc/sdk/1.3.211.0/linux/getting_started.html
## Fedora
### OpenGL
`sudo dnf install mesa-libGL-devel`
### glfw
Glfw is included in this project.
### Vulkan
Same as ubuntu