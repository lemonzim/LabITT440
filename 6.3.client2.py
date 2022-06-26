import socket

ClientSocket = socket.socket()
host = '192.168.56.105'
port = 8888

print('Waiting for connection')
try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

while True:
    #send number to set operation
    Input1 = input('a= Expo, b=Square root, c= log(e)\n')
    ClientSocket.send(str.encode(Input1))
    
    #send number to square root
    Input2 = input('Send a number\n')
    ClientSocket.send(str.encode(Input2))
    Response2 = ClientSocket.recv(1024)
    print(Response2.decode('utf-8'))

ClientSocket.close()
