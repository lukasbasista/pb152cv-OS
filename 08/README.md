# 08

 1. Write a program, ‹echo.c›, which:
    1. connects to the TCP port 2222 of ‹localhost›
    2. reads a message of up to 20 bytes from the connected socket
    3. sends back the string "you said <message>" over the socket
    4. closes the connection and exits with status 0
    
 2. The IP address of ‹localhost› is ‹127.0.0.1›
 3. Write a shell script ‹echo.sh›, which:
    1. compiles the program from point 1 into ‹a.out›
    2. listens on port 2222 using ‹nc›
    3. starts ‹a.out› from point 3.1
    4. sends message ‹ping› to ‹a.out› from 3.3, using the
       listening ‹nc› instance started in 3.2
    5. prints the message from ‹a.out› onto ‹stdout›
    6. waits until ‹nc› from point 3.2 terminates
