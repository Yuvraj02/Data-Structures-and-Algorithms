import socket

if __name__ == "__main__":
    ip = "127.0.0.1"
    port = 4041

    server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.bind((ip,port))
    server.listen(5)

    while True:
        client, address = server.accept()
        print("Connection Established")
        string = client.recv(1024)
        string = string.decode
