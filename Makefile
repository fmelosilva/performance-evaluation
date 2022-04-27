
.PHONY: all q3 q7

FLAGS := -Wall -std=c99
BINDIR := bin
RESULTDIR := result

all: q3 q7

setup:
	mkdir -p $(BINDIR) $(RESULTDIR)

q3: Q3BINDIR:=$(BINDIR)/q3
q3: Q3RESULTDIR:=$(RESULTDIR)/q3
q3: clean_q3 setup
	mkdir -p $(Q3BINDIR) $(Q3RESULTDIR)
	gcc q3.c $(FLAGS) -lm -o $(Q3BINDIR)/q3.out
	bash q3.sh > $(Q3RESULTDIR)/time.csv

q7: Q7BINDIR:=$(BINDIR)/q7
q7: Q7RESULTDIR:=$(RESULTDIR)/q7
q7: clean_q7 setup
	mkdir -p $(Q7BINDIR) $(Q7RESULTDIR)
	gcc $(FLAGS) -pg -o $(Q7BINDIR)/q7.out q7.c
	cd $(Q7BINDIR) && \
	  ./q7.out > /dev/null
	gprof $(Q7BINDIR)/q7.out $(Q7BINDIR)/gmon.out > $(Q7RESULTDIR)/q7.stats
	gprof2dot --node-thres=0 --edge-thres=0 $(Q7RESULTDIR)/q7.stats > $(Q7RESULTDIR)/q7.dot
	dot -Tps  $(Q7RESULTDIR)/q7.dot > $(Q7RESULTDIR)/q7.eps
	dot -Tpng $(Q7RESULTDIR)/q7.dot > $(Q7RESULTDIR)/q7.png

clean_q3:
	rm -rf $(Q3BINDIR) $(Q3RESULTDIR)

clean_q7:
	rm -rf $(Q7BINDIR) $(Q7RESULTDIR)