
SRC=cpm.cpp dd.cpp dmk.cpp jv1.cpp jv3.cpp md.cpp nd.cpp \
	osi.cpp rd.cpp td1.cpp td3.cpp td4.cpp vdi.cpp p80.cpp

CFLAGS = -g -fpermissive

all:	p80

p80:	$(SRC)
	g++ ${CFLAGS} -o p80 $(SRC)

install:	p80
	install -s p80 /usr/local/bin/p80

clean:
	rm -f p80 


#
