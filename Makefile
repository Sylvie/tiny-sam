all:
	+$(MAKE) -C src/
	+$(MAKE) -C manual/

clean:
	rm -fr build/