 # 01
 
 1. The exercise is to write a shell script (save it as ‹hw.sh›).
    The script should do the following:
    
    - create a directory called ‹scratch›
    - change into the directory
    - make a copy of all shell scripts from ‹~/pb152/01› (files
      ending ‹.sh›)
    - make a copy of ‹oslist.csv› from ‹~/pb152/01›
    - count operating systems by Apple, Google and Microsoft
    - print the vendor of the most recent operating system
    - count the number of different vendors (‹man uniq›)
    - change back to the original directory
    - erase everything in ‹scratch› and the directory itself

 2. The script will «not» be running in ‹~/pb152/01›. Use the entire
    path to refer to that directory, using ‹~› or ‹$HOME›. Do not
    use your login in the path!

 3. The expected output would be:
    
        OS count by Apple:
        3
        OS count by Google:
        2
        OS count by Microsoft:
        3
        Latest operating system by:
        Google
        Number of different vendors:
        7
    
    Please follow the above output format exactly.