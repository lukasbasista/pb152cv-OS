./04 | sort -t" " -k2 -n | (IFS=" " 
while read char inode links size name all
do
    if test $char = "f" ; then
        echo $name
    fi
done)