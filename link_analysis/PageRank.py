# Implementation of PageRank Algorithm

web_size = 4

web = [
	[0,1,0,0],
	[1,0,1,0],
	[1,0,0,0],
	[1,1,1,1]
	]
init_pagerank = 1/web_size
web_pagerank = [init_pagerank for i in range(web_size)]

#damping factor
d = 0.85
print('WEB : ',web)
print('init_pagerank : ',web_pagerank)
print('damping factor : ',d)

def lookbound_links(web,node):
	link_count = 0
	for i,n in enumerate(web[node]):
		if n is 1 and i is not node :	
			link_count+=1
	return link_count

#testing lookbounds
#print(lookbound_links(web,0))

def PageRank(web,node,prev_pagerank,d=0.85,N=4):
	other_nodes = [ n for i,n in enumerate(web) if i is not node ]
	#print(other_nodes)
	pagerank = 0
	for i,n in enumerate(web):
		if i is not node:
			l = lookbound_links(web,i)
			pagerank += prev_pagerank[i]/l
	return (1-d)/N + d*pagerank

for i in range(2):
	print('iteratation : ',i+1)
	current_ranks = []
	for j in range(4):
		pr = PageRank(web,j,web_pagerank,d,web_size)
		current_ranks.append(pr)
		print('PageRank of : ',j+1,' is ',pr)
	print(current_ranks)
	web_pagerank = current_ranks
