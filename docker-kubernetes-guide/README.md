# Docker Useful commands

- List all the running docker container
        
        docker ps  
- List all the running docker container ID
        
        docker ps -aq
- List all the images 

        docker images ls
- List all the containers

        docker container ls
- Run docker container in a detached mode 

        docker run -d [image]:version/tag   
        docker run -d ngnix:latest
- Running docker container in a detached mode with exposing port

        docker run -d -p host_port:contianer_port [image]:version/tag   
        docker run -d -p 8080:80 ngnix:latest
- Stopping running docker container

        docker stop [container_id]
- Running docker container in a detached mode with exposing multiple ports

        docker run -d -p host_port:contianer_port -p host_port:contianer_port [image]:version/tag   
        docker run -d -p 8080:80 -p 3000:80 ngnix:latest
- Removing docker container

        docker rm [container_id]
    Note : docker rm will not remove running container, To stop running instance try with flag -f(force),

        docker rm -f [container_id]
        docker rm -f $(docker ps -aq)

        Second command will remove all the existing docker container by filtering container_ids
- Creating a docker container with custom name

        docker run --name custom_name -d host_port:contianer_port [image]:version/tag  

        docker run --name website -d 8080:80 ngnix:latest

- Displaying results with formatted style(docker-ps-vertical)
    
        export FORMAT="ID\t{{.ID}}\nNAME\t{{.Names}}\nIMAGE\t{{.Image}}\nPORTS\t{{.Ports}}\nCOMMAND\t{{.Command}}\nCREATED\t{{.CreatedAt}}\nSTATUS\t{{.Status}}\n"

        docker ps --format = $FORMAT
- Pushing our custom html file directly to nginx server

        docker run --name custom_containername -v Source_html_path:Destination_HTML_path:mode -p host_port:contianer_port [image]:version/tag 

        docker run --name website -v $(pwd):/usr/share/nginx/html:ro -p 8080:80 ngnix:latest

        mode = ro
        ro - only read

- Executing in a interaction mode in bash

        docker exec -it container-name bash
        docker exec -it website bash
- Exitting from bash interaction mode 

        exit

- Creating a new container from the mounted volume

        docker run --name container_name --voulme-from container_name -d  -p host_port:contianer_port [image]:version/tag 
- Login in to external docker container
    
        docker login servername
- Inspecting container id 

        docker inspect container_id 

- Logging container_id

        docker logs container_id

- creating dockerfile

        touch Dockerfile

- Building custom docker image 

        docker build --tag website:latest
- Pulling docker image of node-alpine

        docker pull node:alpine 
- Setting up the tag for our cusotm build image from present to future tag, which overwrite container name

        docker tag [tag_name_present]:version [tag_name_future]:version
- Removing one or more images of docker

        docker rmi [option] image:tag
---
# Docker Explanation

![1](https://user-images.githubusercontent.com/49576526/127447464-6d92caad-6be7-4603-b130-bef159954187.jpg)

![2](https://user-images.githubusercontent.com/49576526/127447546-48a3b2fc-0b94-4e4b-a956-bdba606082a7.jpg)

![3](https://user-images.githubusercontent.com/49576526/127447611-14a62cbe-ca97-4e7e-9303-6ce69f2e116f.jpg)

---

# Kubernates Useful commands

 To run kubernates, we need minikube and kubectl

- Running minikube

        minikube start hypervisor --hypervisor
        minikube start docker --docker

- Getting all nodes
    
        kubectl get nodes
- Getting all pds
    
        kubectl get pod
- Getting all serivices
    
        kubectl get services
- Getting all deployments
    
        kubectl get deployments
- Creating component(a deployment(abstraction ober pods) of pod)
      
        kubectl create -f file.(yaml)
                (or)
        kubectl apply -f file.(yaml)
- Getting log of pod

        kubectl logs podname
- Describing pods
        
        kubectl describe pod pod_name
- Executing interactive pod with bash
        
        kubectl exec -it pod_name -- bin/bash
- Deleting config file

        kubectl delete -f filename
- Get all pods

        kubectl get all
- Get pod with IP

        kubectl get pod -o wide
 
--- 

# Kubernates Explanation

![k-1](https://user-images.githubusercontent.com/49576526/127452376-f3151142-b21a-4601-966a-a3cb698fba11.jpg)

![k-2](https://user-images.githubusercontent.com/49576526/127452391-dc38c45b-0d98-419f-bc9b-718033e14683.jpg)

![k-3](https://user-images.githubusercontent.com/49576526/127452401-2c443b2d-99c1-4be4-a15c-295d07a41b40.jpg)

![k-4](https://user-images.githubusercontent.com/49576526/127452413-3d88f3d6-5059-4587-8b78-4a5ea8b2f06a.jpg)

![k-5](https://user-images.githubusercontent.com/49576526/127452422-d1f2e95f-71c2-40a1-ad44-e05496fe9d0f.jpg)


        


