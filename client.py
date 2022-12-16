# echo-client.py

import socket

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 4041  # The port used by the server

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.connect((HOST,PORT))

print(f"Working")