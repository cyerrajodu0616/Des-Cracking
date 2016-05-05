#bin/bash
g++ server1.cpp -pthread -o server
nohup bash -c "./server > server.log &"
ps -e | grep server

ssh -i ISARedhat.pem ubuntu@52.10.82.1 << 'ubuntu4'
ifconfig
g++ clientcout_1.cpp -pthread -o clientcout_1
g++ clientcout_1.cpp -pthread -o clientcout_2
g++ clientcout_1.cpp -pthread -o clientcout_3
g++ clientcout_1.cpp -pthread -o clientcout_4
g++ clientcout_1.cpp -pthread -o clientcout_5

sleep 5
ps -e | grep clientcout_

nohup bash -c "./clientcout_1 16 > clientcout_1.log &"
nohup bash -c "./clientcout_2 16 > clientcout_2.log &"
nohup bash -c "./clientcout_3 16 > clientcout_3.log &"
nohup bash -c "./clientcout_4 16 > clientcout_4.log &"
nohup bash -c "./clientcout_5 16 > clientcout_5.log &"

ps -e | grep clientcout_
exit

ubuntu4

ssh -i ISARedhat.pem ubuntu@52.25.16.105 << 'ubuntu5'
ifconfig
g++ clientcout_1.cpp -pthread -o clientcout_1
g++ clientcout_1.cpp -pthread -o clientcout_2
g++ clientcout_1.cpp -pthread -o clientcout_3
g++ clientcout_1.cpp -pthread -o clientcout_4
g++ clientcout_1.cpp -pthread -o clientcout_5

sleep 5
ps -e | grep clientcout_

nohup bash -c "./clientcout_1 16 > clientcout_1.log &"
nohup bash -c "./clientcout_2 16 > clientcout_2.log &"
nohup bash -c "./clientcout_3 16 > clientcout_3.log &"
nohup bash -c "./clientcout_4 16 > clientcout_4.log &"
nohup bash -c "./clientcout_5 16 > clientcout_5.log &"

ps -e | grep clientcout_
exit

ubuntu5

ssh -i ISARedhat.pem ubuntu@52.25.138.33 << 'ubuntu6'
ifconfig
g++ clientcout_1.cpp -pthread -o clientcout_1
g++ clientcout_1.cpp -pthread -o clientcout_2
g++ clientcout_1.cpp -pthread -o clientcout_3
g++ clientcout_1.cpp -pthread -o clientcout_4
g++ clientcout_1.cpp -pthread -o clientcout_5

sleep 5
ps -e | grep clientcout_

nohup bash -c "./clientcout_1 16 > clientcout_1.log &"
nohup bash -c "./clientcout_2 16 > clientcout_2.log &"
nohup bash -c "./clientcout_3 16 > clientcout_3.log &"
nohup bash -c "./clientcout_4 16 > clientcout_4.log &"
nohup bash -c "./clientcout_5 16 > clientcout_5.log &"

ps -e | grep clientcout_
exit

ubuntu6

ssh -i ISARedhat.pem ubuntu@52.11.144.122 << 'ubuntu7'
ifconfig
g++ clientcout_1.cpp -pthread -o clientcout_1
g++ clientcout_1.cpp -pthread -o clientcout_2
g++ clientcout_1.cpp -pthread -o clientcout_3
g++ clientcout_1.cpp -pthread -o clientcout_4
g++ clientcout_1.cpp -pthread -o clientcout_5

sleep 5
ps -e | grep clientcout_

nohup bash -c "./clientcout_1 16 > clientcout_1.log &"
nohup bash -c "./clientcout_2 16 > clientcout_2.log &"
nohup bash -c "./clientcout_3 16 > clientcout_3.log &"
nohup bash -c "./clientcout_4 16 > clientcout_4.log &"
nohup bash -c "./clientcout_5 16 > clientcout_5.log &"

ps -e | grep clientcout_
exit

ubuntu7

ssh -i ISARedhat.pem ubuntu@52.24.253.112 << 'ubuntu8'
ifconfig
g++ clientcout_1.cpp -pthread -o clientcout_1
g++ clientcout_1.cpp -pthread -o clientcout_2
g++ clientcout_1.cpp -pthread -o clientcout_3
g++ clientcout_1.cpp -pthread -o clientcout_4
g++ clientcout_1.cpp -pthread -o clientcout_5

sleep 5
ps -e | grep clientcout_

nohup bash -c "./clientcout_1 16 > clientcout_1.log &"
nohup bash -c "./clientcout_2 16 > clientcout_2.log &"
nohup bash -c "./clientcout_3 16 > clientcout_3.log &"
nohup bash -c "./clientcout_4 16 > clientcout_4.log &"
nohup bash -c "./clientcout_5 16 > clientcout_5.log &"

ps -e | grep clientcout_
exit

ubuntu8

ssh -i ISARedhat.pem ubuntu@52.25.111.209 << 'ubuntu9'
ifconfig
g++ clientcout_1.cpp -pthread -o clientcout_1
g++ clientcout_1.cpp -pthread -o clientcout_2
g++ clientcout_1.cpp -pthread -o clientcout_3
g++ clientcout_1.cpp -pthread -o clientcout_4
g++ clientcout_1.cpp -pthread -o clientcout_5

sleep 5
ps -e | grep clientcout_

nohup bash -c "./clientcout_1 16 > clientcout_1.log &"
nohup bash -c "./clientcout_2 16 > clientcout_2.log &"
nohup bash -c "./clientcout_3 16 > clientcout_3.log &"
nohup bash -c "./clientcout_4 16 > clientcout_4.log &"
nohup bash -c "./clientcout_5 16 > clientcout_5.log &"

ps -e | grep clientcout_
exit

ubuntu9
 ps -e | grep server


