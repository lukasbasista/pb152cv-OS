#!/bin/sh

mkdir ~/pb152/01/scratch
cd ~/pb152/01/scratch
cp ~/pb152/01/*.sh ~/pb152/01/scratch
cp ~/pb152/01/oslist.csv ~/pb152/01/scratch
echo "OS count by Apple:"
cat oslist.csv | grep -c Apple
echo "OS count by Google:"
cat oslist.csv | grep -c Google
echo "OS count by Microsoft:"
cat oslist.csv | grep -c Microsoft
echo "Latest operating system by:"
cat oslist.csv | sort -r | cut -d ',' -f 2 | head -n 1
echo "Number of different vendors:"
cat oslist.csv | cut -d ',' -f 2 | sort | uniq | wc -l
cd ../
rm -r scratch
