import socket
import sys
import time
import errno
import math
from multiprocessing import Process
def process_start(s_sock):
    while True:
        data = s_sock.recv(2048)
        print(data)
        
        if data.decode('utf-8')=='a':
            #receive number to expo
            data1 = s_sock.recv(2048)
            print(data1.decode('utf-8'))
            numb=int(data1)
            numb =numb*numb
            s_sock.sendall(str.encode(str(numb)))
            
        elif data.decode('utf-8')=='b':
            #receive number to square root
            data2 = s_sock.recv(2048)
            print(data2.decode('utf-8'))
            numb2=int(data2)
            numb2=math.sqrt(numb2)
            s_sock.sendall(str.encode(str(numb2)))
        elif data.decode('utf-8')=='c':
            #receive number to log(e)
            print('success3')
            data3 = s_sock.recv(2048)
            print(data3.decode('utf-8'))
            numb3=int(data3)
            numb3=math.log(numb3)
            s_sock.sendall(str.encode(str(numb3)))
        elif data.decode('utf-8')=='exit':
            message='Bye-bye'
            s_sock.sendall(str.encode(message))
            s.close()
        else:
            print('fail')
    s_sock.close()


if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(("",8888))
    print("listening...")
    s.listen(3)
    try:
        while True:
            try:
                s_sock, s_addr = s.accept()
                print('Connected to: ' + s_addr[0] + ':' + str(s_addr[1]))
                p = Process(target=process_start, args=(s_sock,))
                p.start()

            except socket.error:

                print('got a socket error')

    except Exception as e:        
        print('an exception occurred!')
        print(e)
        sys.exit(1)
    finally:
     	   s.close()
