import os
import pathlib

path1 = '/Users/devmbandhiya/Desktop/AUV_Day-3/Images'
files1 = os.listdir(path1)

f1=[]
for file in files1:
    f_name, f_extension = os.path.splitext(file)
    f1.append(f_name)


path2 = '/Users/devmbandhiya/Desktop/AUV_Day-3/Labels'
files2 = os.listdir(path2)

f2=[]
for file in files2:
    f_name, f_extension = os.path.splitext(file)
    f2.append(f_name)

del_f = set(f2) - set(f1)
print(del_f)

f = set(f2)

for f in del_f:
    path = os.path.join(path2, f"{f}.txt")
    if os.path.exists(path):
        os.remove(path)
        print(f"Deleted: {path}")
    else:
        print(f"File not found: {path}")
       
    


