CC = gcc
CFLAGS = -Wall -fPIC

SLIBOBJECTS1 = advancedClassificationLoop.o basicClassification.o
SLIBOBJECTS2 = advancedClassificationRecursion.o basicClassification.o

all: loops recursives loopd recursived mains maindloop maindrec

libclassloops.a: ${SLIBOBJECTS1}
	ar rcu libclassloops.a ${SLIBOBJECTS1}
	ranlib libclassloops.a

libclassrec.a: ${SLIBOBJECTS2}
	ar rcu libclassrec.a ${SLIBOBJECTS2}
	ranlib libclassrec.a

libclassloops.so: ${SLIBOBJECTS1}
	${CC} -shared -o libclassloops.so ${SLIBOBJECTS1}

libclassrec.so: ${SLIBOBJECTS2}
	${CC} -shared -o libclassrec.so ${SLIBOBJECTS2}

loops: main.o libclassloops.a
	${CC} ${CFLAGS} main.o -L. -lclassloops -o loops

recursives: main.o libclassrec.a
	${CC} ${CFLAGS} main.o -L. -lclassrec -o recursives

loopd: main.o libclassloops.so
	${CC} ${CFLAGS} main.o -L. -lclassloops -o loopd

recursived: main.o libclassrec.so
	${CC} ${CFLAGS} main.o -L. -lclassrec -o recursived

mains: main.o libclassrec.a
	${CC} ${CFLAGS} main.o -L. -lclassrec -o mains

maindloop: main.o libclassloops.so
	${CC} ${CFLAGS} main.o -L. -lclassloops -o maindloop

maindrec: main.o libclassrec.so
	${CC} ${CFLAGS} main.o -L. -lclassrec -o maindrec

main.o: main.c NumClass.h
	${CC} -c main.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	${CC} -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	${CC} -c advancedClassificationRecursion.c

basicClassification.o: basicClassification.c NumClass.h
	${CC} -c basicClassification.c

clean:
	rm -f *.o *.a *.so loops recursives loopd recursived mains maindloop maindrec

