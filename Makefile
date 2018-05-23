default:
	gcc utils/makefifo.c -o makefifo
	gcc detect_internet.c -o detect_internet
	g++ utils/getl.cpp -o getl
install:
	gcc utils/makefifo.c -o makefifo
	cp ./makefifo /bin/
	rm ./makefifo
	g++ utils/getl.cpp -o getl
	cp ./getl /bin/
	rm ./getl
	gcc detect_internet.c -o detect_internet
	cp ./detect_internet /bin/
	rm ./detect_internet
	cp ./files.h /usr/include
	cp ./cpulib.h /usr/include
	cp ./detect_internet.h /usr/include
fifo:
	gcc utils/makefifo.c -o makefifo
getl:
	g++ utils/getl.c[[ -o getl
detect_internet:
	gcc detect_internet.c -o detect_internet
clean:
	rm -f ./makefifo
	rm -f ./getl
	rm ./detect_internet
uninstall:
	rm -f /bin/makefifo
	rm -f /bin/getl
	rm -f /bin/detect_internet
	rm -f /usr/include/detect_internet.h
	rm -f /usr/include/files.h
	rm -f /usr/include/cpulib.h
