all:out cfile 

out:file.c
	gcc $^ -o $@
cfile:cfile.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm out cfile
