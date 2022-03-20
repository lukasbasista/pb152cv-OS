# 04

 1. Implement ‹list.c›, which prints the contents of the working directory.

 2. Each entry goes on a single line. The format is as follows (each
    column is separated from the next by a single space):
    
    - one character, ‹f› for files, ‹d› for directories, ‹l› for
       symlinks
    - the inode number
    - the number of links
    - the size of the file (0 if not applicable)
    - the file name
    - if the file is a symlink, ‹... target› (otherwise nothing)