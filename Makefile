LIB=-lm
OBJS=hello.o thanks.o 
APP_NAME=main
main:${OBJS}
	gcc -o ${APP_NAME} ${OBJS} ${LIBS}
clean:
	rm -f ${APP_NMAE} ${OBJS}
