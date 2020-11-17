all:scm sim main
scm:echo1
	make -C $@
echo1:
	@echo scm
sim:echo2
	make -C $@
echo2:
	@echo sim
main:main.c
	gcc -o main main.c sim/libst.a scm/libco.a `pkg-config --cflags --libs gtk+-3.0`
.PHONY:clean
clean:
	make clean -C scm
	make clean -C sim
