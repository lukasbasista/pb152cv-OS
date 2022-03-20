# 05

 1. Write a C program ‹sync.c› and a shell script ‹sync.sh›.
 2. The C program should ‹fork()› & the child should then ‹exec()›
    the script.
 3. The parent process:
    
    - waits until ‹file1.txt› appears
    - when it does, it copies its content into ‹file2.txt›
    - waits for the script to finish and prints its exit code
    - use POSIX ‹read()› and ‹write()› above
    
 4. The shell script:
    
    - prints its own pid (found in ‹$$›) into ‹file1.txt›
    - waits until ‹file2.txt› appears
    - waits a second to make sure the content is written
    - reads ‹file2.txt› and checks that its content matches
    - if it matches, ends with exit code 0, otherwise 1
    - the shell built-in ‹exit 0› and ‹exit 1› can be used for (e)