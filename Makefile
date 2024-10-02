all:
	for number in 4 7 8 ; do \
		g++ bil_$$number.cpp -o out/bil_$$number ; \
	done