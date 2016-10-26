def swapbyte(num):
	return ((num>>8) + (num<<8)%(2**16))

num = 0xAABB
print ("hex")
print ("swapped")
print swapbyte(num)
