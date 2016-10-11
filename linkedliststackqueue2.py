class LinkedList:
	class __Node:
		def __init__(self,item,next=None):
			self.item = item
			self.next = next

		def getItem(self):
			return self.item

		def getNext(self):
			return self.next

		def setItem(self, item):
			self.item = item

		def setNext(self,next):
			self.next = next

	def __init__(self):
		self.first = LinkedList.__Node(None,None)
		self.last = self.first
		self.numItems = 0

	def append(self,item):  # enqueue
		node = LinkedList.__Node(item)
		self.last.setNext(node)
		self.last = node
		self.numItems += 1

	def isEmpty(self):
		return self.numItems == 0

	def insert(self,item):  # push
		self.first.setNext(LinkedList.__Node(item, self.first.getNext()))
		self.numItems += 1

	def remove(self):  # pop and dequeue
		node = self.first.getNext()
		self.first.setNext(node.getNext())
		self.numItems -= 1
		if self.isEmpty():
			self.last = self.first
		return node.getItem()

	def getFirst(self):  
		return self.first.getNext().getItem()

class Queue:
	def __init__(self):
		self.queue = LinkedList()

	def isEmpty(self):
		return self.queue.isEmpty()

	def enqueue(self, item):
		self.queue.append(item)

	def dequeue(self):
		return self.queue.remove()

class Stack:
	def __init__(self):
		self.stack = LinkedList()

	def isEmpty(self):
		return self.stack.isEmpty()

	def push(self,item):
		self.stack.insert(item)

	def pop(self):
		return self.stack.remove()

	def top(self):
		return self.stack.getFirst()