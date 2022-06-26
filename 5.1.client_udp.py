import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

port = 8888
data = s.recvfrom(1024)
s.sendto(b'Hi, saya client. Terima Kasih!');
print (data)
s.close()
