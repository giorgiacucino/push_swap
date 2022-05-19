import random

l = []
with open("o.txt", "w") as f:
	string = ""
	for x in range(0, 100):
		v = random.choice([y for y in range(-101, 101)])
		while (v in l):
			v = random.choice([y for y in range(-101, 101)])
		l.append(v)
		string += f"{v} "
	f.write(string)