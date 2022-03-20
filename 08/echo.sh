set -x
port=2136
gcc echo.c

nc -l $port > file.txt &
./a.out

echo "ping" | nc localhost $port
wait
cat file.txt
rm file.txt