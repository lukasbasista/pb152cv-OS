# 06

 1. Write a C program, ‹listen.c›, which listens on a Unix socket:
    
    - the name of the socket should be ‹./socket›
    - repeatedly accept connections from clients
    - each client will send a single null-terminated path
    - the server will execute this program in a new process
    - the path buffer should be at least 200 bytes

 2. As a test client, you can use ‹client.c›.
