#@/bin/bash

echo "Downloading all needed packages"

OS_NAME=$(grep '^NAME' /etc/os-release)

if [[ $OS_NAME == 'NAME="Ubuntu"' ]]
then
	sudo apt install xorg-dev libglu1-mesa-dev libglfw3-dev -y
fi

# TODO: Download file for other distro