import networkx as nx

G = nx.DiGraph()

G.add_node(1)
G.add_nodes_from([2, 3, 4, "Mike"])

G.add_edge(1, 2)
G.add_edges_from([(1, 3), (3, "Mike"), (4, 2), ("Mike", 1)])
