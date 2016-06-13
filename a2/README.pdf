		      Taks 1

('**********', '/u/csc369h/fall/pub/a2-traces/simpleloop', '**********')
('Number of unique code pages:', 64)
('Number of unique data pages:', 2574)
('Number of memory accesses before and after the markers:', 210337)
('Number of memory accesses in algorithm component of the program:', 172651)

The memory access for simpleloop is 64 pages are needed to run the program, 
and 2574 pages are used to store the data for the program and make 
modifications and manipulated to its data. 
The number of data pages is this big, because its storing 10000 floats.


('**********', '/u/csc369h/fall/pub/a2-traces/matmul-100', '**********')
('Number of unique code pages:', 74)
('Number of unique data pages:', 1017)
('Number of memory accesses before and after the markers:', 211727)
('Number of memory accesses in algorithm component of the program:', 62973520)

The memory access for the matmul-100 program 
requires 74 pages for its algorithm,
and needs 1017 pages of data(ints). This progam needs more code pages because
it does more work than simpleloop but about half the data pages, because it
stores ints and not floats. 


('**********', '/u/csc369h/fall/pub/a2-traces/blocked-100-25', '**********')
('Number of unique code pages:', 77)
('Number of unique data pages:', 1018)
('Number of memory accesses before and after the markers:', 212191)
('Number of memory accesses in algorithm component of the program:', 67664111)

The memory access of blocked-100-25 is similar to matmul-100, its uses 77 
code pages because it partitios the matrix whcich requires more code, but
it uses about the same number of data pages(1018) because is still using
the same amount of data as matmul.


('**********', './makeTrace', '**********')
('Number of unique code pages:', 97)
('Number of unique data pages:', 85)
('Number of memory accesses before and after the markers: ignored')
('Number of memory accesses in algorithm component of the program ignored')

The memory access of make uses 97 code pages 
because its setting up the executables
as well as compiling the programs specefied in it, 
but it needs very few resources(data pages) 
because it does not store too many things.


('**********', './spTrace', '**********')
('Number of unique code pages:', 69)
('Number of unique data pages:', 74)
('Number of memory accesses before and after the markers:', 223269)
('Number of memory accesses in algorithm component of the program:', 5055)

The memory access for my simple writing reading through pipes between forked
process uses 69 code pages because its simply implemented, as well it does
not require a lot of data pages beacuse there is not much data being 
modefied or transfered.


			Task 2
Based in the comparison of the various heuristics accross the four 
algorithms, the trade offs between ease of implementation and 
performance become apperant. The table below shows that as memory 
size increases the miss rate decreases, as memory size doubles the
average ratio in miss rates decrease on average 1.272, therfore
doubleing memory size improves the miss rate by 27% on average 
accross all algorithms. Also as the implementation complexity increases
the performance increases, from fifo to clock(1.583), 
from clock to lru(0.789), from lru to opt(1.381) so on average performance
improves 1.251 per level of complexity.

blocked-100-25	   memesize 50	memsize 100	ratio

1) FIFO Miss rate:  0.0095	0.0064		1.484
2) CLOCK Miss rate: 0.0060	0.0060		1.000
3) LRU Miss rate:   0.0076	0.0056		1.357
4) OPTMiss rate:    0.0055	0.0044		1.250  

block-100-25 with a memsize of 50 was used to show the implementation vs
performance trade offs, because the trace is very large which provides
and extensive test for performance and memesize 50 was choosen, because
its enought to check the improvement by the level of complexity across
algorithms.

The LRU algorithm miss rates improves significantly as the size of
memory increases with an average of 0.705 improvement in miss rate
per doubleing memory (from 50 to 100 is 0.712, 
from 100 to 150 is 0.698, from 150 to 200 is 0.698). The greatest 
improvement happens from memory size from 50 to 100, its because
it keeps the pages that are most used and most frequently, therfore
its very likely that the pages needed in a program running will be 
mostly kept and the threshole/average pages used by a program 
is around 100 since there is not much improvement after 100 pages.



===============================FIFO==========================================
simpleloop ---------50		100		150 		200

Hit count: 	   380013	380240		380280		380288
Miss count: 	   2977		2750		2710		2702
Total references : 382990		382990		382990		382990
Hit rate: 	   99.2227	99.2820		99.2924		99.2945
Miss rate: 	   0.7773	0.7180		0.7076		0.7055

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

matmul-100 --------50		100		150 		200

Hit count: 	   62055545	62101279		63150843		63151365
Miss count: 	   1129703	1083969		34405		33883
Total references : 63185248	63185248		63185248		63185248
Hit rate: 	   98.2121	98.2845		99.9455		99.9464
Miss rate: 	   1.7879	1.7155		0.0545		0.0536

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

blocked-100-25------50		100		150 		200

Hit count: 	  67869846	67871968		67872062		67873126
Miss count: 	  6458		4336		4242		3178
Total references :67876304	67876304		67876304		67876304
Hit rate: 	  99.9905	99.9936		99.9938		99.9953
Miss rate: 	  0.0095		0.0064		0.0062		0.0047


===============================LRU==========================================

simpleloop --------50		100		150 		200

Hit count: 	  380213		380312		380314		380314
Miss count: 	  2777		2678		2676		2676
Total references :382990		382990		382990		382990
Hit rate: 	  99.2749	99.3008		99.3013		99.3013
Miss rate: 	  0.7251		0.6992		0.6987		0.6987

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

matmul-100 --------50		100		150 		200

Hit count: 	  62144028	62178803		63152370		63152381
Miss count: 	  1041220	1006445		32878		32867
Total references :63185248	63185248		63185248		63185248
Hit rate: 	  98.3521	98.4072		99.9480		99.9480
Miss rate: 	  1.6479		1.5928		0.0520		0.0520


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

blocked-100-25 --50		100		150 		200

Hit count: 	  67871123	67872494		67872509		67872612
Miss count: 	  5181		3810		3795		3692
Total references :67876304	67876304		67876304		67876304
Hit rate: 	  99.9924	99.9944		99.9944		99.9946
Miss rate: 	  0.0076		0.0056		0.0056		0.0054


===============================CLOCK======================================

simpleloop --------50		100		150 		200

Hit count: 	  380201		380312		380312		380313
Miss count:	  2789		2678		2678		2677 
Total references :382990		382990		382990		382990
Hit rate: 	  99.2718	99.3008		99.3008		99.3010
Miss rate: 	  0.7282		0.6992		0.6992		0.6990


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

matmul-100 --------50		100		150 		200

Hit count: 	  62144008	62144231		63152046		63152355
Miss count: 	  1041240	1041017		33202		32893
Total references :63185248	63185248		63185248		63185248
Hit rate: 	  98.3521	98.3524		99.9475		99.9479
Miss rate: 	  1.6479		1.6476		0.0525		0.0521

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

blocked-100-25 -----50		100		150 		200

Hit count: 	  67872256	67872256		67872341		67873083
Miss count:	  4048		4048		3963		3221
Total references:  67876304	67876304		67876304		67876304
Hit rate: 	  99.9940	99.9940		99.9942		99.9953
Miss rate: 	  0.0060		0.0060		0.0058		0.0047

===============================OPT===============

simpleloop --------50		100

Hit count: 	  380323		380357
Miss count: 	  2667		2633 
Total references:   382990	382990
Hit rate: 	  99.3036 	99.3125
Miss rate: 	  0.6964		0.6875


++++++++++++++++++++++++++++++++++++++++++++

matmul-100 --------50		100

Hit count: 	  62597795	63092458
Miss count: 	  587453		92790	
Total references:63185248		63185248
Hit rate: 	  99.0703	99.8531	
Miss rate: 	  0.9297		0.1469	

+++++++++++++++++++++++++++++++++++++++++++++

blocked-100-25 --------50		100

Hit count: 	  67872583	67873287
Miss count: 	  3721		3017 	
Total references: 67876304	67876304 
Hit rate: 	  99.9945	99.9956 	
Miss rate: 	  0.0055		0.0044	




			Task 3

Small is when the memsize 20.
Big is when the memsize 21.
First when the table stores 21 new pages the "small" table loses
its zero value, but the "big" table stores all unique pages.
Then when 18 already seen pages are requested in order, the "small"
table will miss in all the pages being added,
the "big" will hit all the pages being added.
Then when a new unique page never seen before is requested, the "small"
table will store it as lastly seen plus all the 18 pages most recently used.
Where as the "big" table will store all the pages minus the 0th/1st page
added. Finally when all 21 pages seen are requested sequentially in order
of appearence, the "small" table will contain most of the pages, where as
the "big" table will be exactly off by one so it will evict the page that
will be used right after. The interference created by the extra slot leads
to the dominos effect of evicting the page that will be used right after.


g3aristi@b2200-10:~/Desktop/csc369/a2$ ./sim -f ./Beladys -m 20 -a fifo
Hit count: 21   
Miss count: 43
Total references : 64
Hit rate: 32.8125
Miss rate: 67.1875

g3aristi@b2200-10:~/Desktop/csc369/a2$ ./sim -f ./Beladys -m 21 -a fifo
Hit count: 20
Miss count: 44
Total references : 64
Hit rate: 31.2500
Miss rate: 68.7500