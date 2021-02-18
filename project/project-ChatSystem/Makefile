cc=g++
server=ChatServer 
client-=ChatClient 

.PHONY:all
	all:$(server) $(client)

$(server):ChatServer.cc 
	$(cc) -o $@ $^

$(client):ChatClient.cc 
	$(cc) -o $@ $^

.PHONY:clean
clean:
	rm -f $(server) $(client)
