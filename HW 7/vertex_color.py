class node:
	def __init__(self):
		self.colored = False

	def isColored(self):
		return self.colored

	def setColored(self):
		self.colored = True

A, B, C, D, E, F = node(), node(), node(), node(), node(), node()

graph = {
	A : {B, C},
	B : {A, C, D},
	C : {A, E},
	D : {B, E, F},
	E : {C, D},
	F : {D}
}

for node in graph:
	print(node.isColored())

for node in graph:
	for edge in graph[node]:
		if node.isColored() or edge.isColored():
			pass
		else:
			edge.setColored()

for node in graph:
	print(node.isColored())