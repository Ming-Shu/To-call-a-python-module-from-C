import socket
import sys
import os
def createTCP_listener(host,port):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except socket.error, msg:
        sys.stderr.write("[ERROR] %s\n" % msg[1])
        sys.exit(1)

    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind((host,port))
    sock.listen(5)
    #sock.settimeout(10)
    #print "sock.fileno():",sock.fileno()
    return sock


def msgTCP_handle(tcp_fd):
    #print "msgTCP_handle(tcp_fd):",tcp_fd
    csock = socket.fromfd(tcp_fd,socket.AF_INET, socket.SOCK_STREAM)
    print "\ncsock: ",csock	
    #(csock, adr) = sock.accept()
    msg = csock.recv(256)
    print "\nReceive a msg: ",msg	
    if not msg:
        pass
    else:
        csock.send("Hello I'm Server.\r\n")

