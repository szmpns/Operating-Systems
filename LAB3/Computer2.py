import socket

def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('192.168.1.113', 12345))

    while True:
        message = input("Wprowadź wiadomość: ")
        client.send(message.encode('utf-8'))

        response = client.recv(1024).decode('utf-8')
        print(f"Potwierdzenie: {response}")
    
    client.close()

if __name__ == "__main__":
    main()