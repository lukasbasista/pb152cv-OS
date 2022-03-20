echo $$ > file1.txt
while [ ! -f file2.txt ]; do sleep 1; done
sleep 1
if cmp -s "file1.txt" "file2.txt"
then
   exit 0
else 
   exit 1
fi