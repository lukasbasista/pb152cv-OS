# 02

 1. There will be two parts.
    
    - Write a C program, ‹write.c›.
    - Write a shell script, ‹test.sh›.

 2. From this point on, use «relative» paths unless directed
    otherwise. The script should do its work in the directory in
    which it is executed. This will also apply to future
    assignments. Do not assume existence of files, outside of those
    submitted, that you did not create.

 3. The C program will work as follows:
    
    - It will read (at most) one kilobyte of data from its standard
       input.
    - It will (create) and write this data into a file that is
       given to it as the first argument.
    - It will complain using ‹stderr› if something fails, and
       return a non-zero exit code.

 4. A hint: to create and write into a file, you will want to use
    these flags to ‹open›: ‹O_RDWR | O_CREAT›. This is the second
    parameter. You also must pass a third argument to ‹open› for
    this to work. This will be ‹0666› (a number) and will be
    explained later.

 5. Now for the shell script:
    
    - compile ‹write.c› into ‹a.out› in the 4 stages
    - the files ‹write.i›, ‹write.s› and ‹write.o› should exist
    - use ‹a.out› to make a copy of ‹write.c› under ‹copy.c›
    - show that ‹a.out› prints an error when writing fails (try to
      write into a directory instead of a file, or to create a file
      in a directory that does not exist, or somewhere where you
      don't have the permission to create files, say ‹/bin›)
