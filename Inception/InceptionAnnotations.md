# Incepetion

## Glossary

| Concept                                         | Explanation                                                                                                                                                                                                                                    |
|-------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Docker                                          | Docker is a program that manages container inside a pc(system), it will initialize, run and stop the containers.                                                                                                                               |
| Dockerfile                                      | Dockerfile is a file that holds a set of instructions for the creation of the image and used in the container                                                                                                                                  |
| Docker Image                                    | Is the output from building from the dockerfile, image are composed in it's name of "name:tag" and saved in a container, this is what will ensure that in every system the service run it will be consistent.                                  |
| Container                                       | Is an isolated environment where it has all the components required to run whatever is inside it (code, libraries and apps).                                                                                                                   |
| Docker Compose                                  | Is the tool used to managed and run multiple containers in one application                                                                                                                                                                     |
| .yml file                                       | File used to set up things to be used by the docker compose, it will describe its dependencies and service. It will also easy the setup in different system, since you will only need to use command and it will set up everything to be used. |
| Service                                         | A service is the image for a microservice. Is the sum of tasks inside a swarm.                                                                                                                                                                 |
| Tasks                                           | Carries a Docker container and the commands to run inside the container                                                                                                                                                                        |
| Scheduling                                      | Is the management of task and their lifecycle(inside composed docker). if one fail, in order to maintain the wanted usage (output), it will remove the task then it will rebuild it to a new container and try to run it.                      |
| Swarm                                           |                                                                                                                                                                                                                                                |
| Docker Network (connections between containers) |                                                                                                                                                                                                                                                |
| NGINX                                           | It's a webserver, load balancer and reverse proxy.                                                                                                                                                                                             |
| Webserver                                       | Server designed to handle multiple connections and interactions.                                                                                                                                                                               |
| Load Balancer                                   | Distributes incoming traffic across multiple servers,**** preventing any single server from being overloaded.                                                                                                                                      |
| Reverse Proxy                                   | Connect clients and backend servers (receive requests, execute the wanted server/task and return the given output).                                                                                                                            |
| MariaDB                                         |                                                                                                                                                                                                                                                |
| WordPress                                       |                                                                                                                                                                                                                                                |

 
### Container x DockerImage

#### 1- Life cycle: 

    DockerImage:
        1- Creation – the creation stage is where you build a Docker image instance from a Dockerfile.
        2- Tagging and versioning – developers label each Docker image to determine which container it builds and its iteration.
        3- Pruning – developers will delete old Docker images and replace them with new ones from a fresh Dockerfile
    
    Container:
        1- Creation – the developers build the container from a Docker image.
        2- Running – the container starts and actively executes its process.
        3- Paused/unpaused – the administrators halt or resume the container operation. 
        4- Stopped – the container stops after completing its process, and you can restart it later. 
        5- Deleted – the container no longer exists, meaning you must recreate it from the image.

#### 2- Portability:
    The container cannot be moved from system, in order to move container, you will needd to move its image and,
    re-build the image in the new system.

## Dockerfile most important instructions:

| Instruction | What it do?                                                     |
|-------------|-----------------------------------------------------------------|
| FROM        | Sets the base image (e.g., FROM ubuntu;20.04)                   |    
| RUN         | Executes shell commands during build time                       | 
| CMD         | Provides default command to run at container start              | 
| ENTRYPOINT  | Defines a fixed command, often combined with CMD for args COPY/ |       
| ADD         | Copies files into the image (ADD supports URLs and archives)    |z
| ENV         | Sets environment variables                                      |
| EXPOSE      | Documents which ports the container will listen on              |
| WORKDIR     | Sets the working directory for following instructions           |
| VOLUME      | Declares mount points for persistent or shared data             |
| ARG         | Defines build-time variables, usable during RUN                 |


## Dockerfile and image commands:

| Command          | What it do?                                                             |
|------------------|-------------------------------------------------------------------------|
| ===========      | ======================================================================= |
| DOCKER IMAGE     |                                                                         |
| docker build     | Take the dockerfile and build a container with the image to be executed |    
| docker run       | Execute the image inside a container                                    | 
| docker pull      | downloads an image from a Docker registry.                              |
| docker push      | uploads a local image to a registry.                                    |
| docker images    | lists all locally available images.                                     |
| docker rmi       | removes an image from the local system.                                 |
| docker tag       | adds a new tag to an image for versioning.                              |
| ===========      | ======================================================================= |
| DOCKER CONTAINER |                                                                         |
| docker run       | creates and starts a container from an image.                           |
| docker ps        | lists all running containers.                                           |
| docker exec      | runs a command inside a running container.                              |
| docker stop      | stops a running container.                                              |
| docker start     | starts a stopped container.                                             |
| docker rm        | removes a stopped container.                                            |
| docker logs      | prints logs from a running or stopped container.                        |



## Reading:

- Recommended to Study:
PID 1, Best practices to write Dockerfiles

Docker is a program that manages container inside a pc(system), it will initialize, run and stop the containers.

Containerization is close that what virtualization does, it will separate a quantity of resources to run its task, this task and 
container they cannot contact the rest of the system, guaranteeing isolation from all the other resources and files .

DockerFile and directory, is the rules and executions that will be used to generate an image(immutable, if you want to change it you will need 
to change the docker file and create another image out of it ) 
