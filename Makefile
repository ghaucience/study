ROOTDIR=$(shell pwd)
WORKDIR=$(ROOTDIR)/build

all:
	mkdir -p $(WORKDIR)
	(cd $(WORKDIR);  cmake ..; make VERBOSE=1; make install; ctest; cd -)
	#(cd $(WORKDIR);  cmake -G"Visual Studio 15 2017 Win64" ..; make ; cd -)

run: 
	$(WORKDIR)/main 1

clean:
	rm -rf $(WORKDIR)



