default:
	gcc makefifo.c -o makefifo
	g++ getl.cpp -o getl
install:
	gcc makefifo.c -o makefifo
	sudo cp ./makefifo /bin/
	rm ./makefifo
	g++ getl.cpp -o getl
	sudo cp ./getl /bin/
	rm ./getl
fifo:
	gcc makefifo.c -o makefifo
clean:
	rm -f ./makefifo
	rm -f ./getl
uninstall:
	sudo rm /bin/makefifo
	sudo rm -f /bin/getl
