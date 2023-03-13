## wsl 설치
https://learn.microsoft.com/ko-kr/windows/wsl/install-manual#step-4---download-the-linux-kernel-update-package

1. docker run -it -d --name myubuntu ubuntu
ubuntu라는 이미지를 실행
2. docker exec -it myubuntu bash
myubuntu 의 bash 실행
3. docker ps
실행되고 있는 도커
4. docker stop myubuntu
5. docker rm myubuntu


docker run
이미지 파일 다운, container생성 = docker pull -> docker start -> docker stop

docker run -it -d -p 8000:8000 --name=nodejs_ node

docker cp app.js nodejs_:/app.js

docker exec -it nodejs_ bash

![result](https://user-images.githubusercontent.com/85085375/223600213-050eac06-ed92-408c-be06-4dbdcb59ea40.png)


docker run -it -d -p 3000:3000 --name=expressjs_ node