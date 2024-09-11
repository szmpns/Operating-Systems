import socket
import threading

def handle_client(client_socket):
    while True:
        data = client_socket.recv(1024).decode('utf-8')
        if not data:
            break
        print(f"Otrzymano wiadomość: {data}")

        message = input("Wprowadź wiadomość: ")
        client_socket.send(message.encode('utf-8'))
    client_socket.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    port = '12345'
    server.bind(('192.168.1.113', 12345))
    server.listen(5)

    print(f"[INFO] Serwer nasłuchuje na porcie {port}...")

    while True:
        client, addr = server.accept()
        print(f"[INFO] Połączono z {addr[0]}:{addr[1]}")

        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

if __name__ == "__main__":
    main()