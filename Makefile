.PHONY   : all rebuild clean run
all      : main run succ
  
rebuild  : clean all
  
main     :  main.c libmykmp.so
	gcc -std=c99 -o $@ main.c -L. -lmykmp
  
libmykmp.so : kmp.c kmp.h
	gcc -c  -shared -fPIC -std=c99 -o $@  kmp.c 
  
run      : main
	@echo "have a show :"
	LD_LIBRARY_PATH=. ./main
	@echo ""
	@echo ""
  
succ     :
	@echo "Complete !"
  
clean    :
	-rm -f main libmykmp.so
	-rm -f *~
	-rm -f *.swp

