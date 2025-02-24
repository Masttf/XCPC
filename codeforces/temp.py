import os
import shutil
ph=".\\"
li=["A","B","C","D","E","F","G"]
for i in range(1800,1882):
	for s in li:
		file="CF"+str(i)+s+".cpp"
		print(file)
		nw="CF"+str(i)
		if not os.path.isfile(file):break
		shutil.move(file,nw)
		print(file+"YES")
