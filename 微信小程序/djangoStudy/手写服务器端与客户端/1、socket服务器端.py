import socket
# 创建socket对象
sk = socket.socket()

# 绑定ip 和端口
sk.bind(("127.0.0.1",8000))

# 监听
sk.listen()

# 等待连接
while True:
    # 建立连接
    conn,addr = sk.accept()
    # 接收数据
    data = conn.recv(2048)
    print(data)
    # 返回数据
    conn.send(b'HTTP/1.1 200 OK \r\n\r\n123')
    # 断开连接
    conn.close()