# Docker setup

Considering a Windows 10 host.

Install and run [Xming](https://sourceforge.net/projects/xming/).

Install and run [Docker](https://www.docker.com/docker-windows). 

> Note
> 
> For a linux host you don't need Xming and X configurations on docker commands. Also, just install docker engine normally (In your distro section as: https://docs.docker.com/install/linux/docker-ce/ubuntu/).

## Image and container

Build docker image

```sh
docker build -t opengl-glut:1 -f Dockerfile .
```

Create container. (Change your host IP address.)

```sh
set-variable -name DISPLAY -value 192.168.15.89:0.0

docker create -it --privileged --name opengl-glut --hostname kagami --env DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11.unix opengl-glut:1

```

## Run container

```sh

docker start opengl-glut

docker attach opengl-glut

# Press enter

```