#!/bin/bash
# Script whitch copies .ssh from host to container

CONTAINER_NAME=opengl-glut

docker start $CONTAINER_NAME
docker cp ~/.ssh $CONTAINER_NAME:/home/suika/.ssh
docker exec $CONTAINER_NAME sh -xc 'sudo chown -R suika /home/suika/.ssh/'
docker exec $CONTAINER_NAME sh -xc 'sudo chmod -R 600 /home/suika/.ssh/*'
docker exec $CONTAINER_NAME sh -xc 'sudo chmod -R 644 /home/suika/.ssh/*.pub'
docker stop $CONTAINER_NAME