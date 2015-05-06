from PIL import Image
img=Image.open("img.jpg")
img_array=img.load()
for i in range(img.size[0]):
	for j in range(img.size[1]):
		print("{} {} {}".format(img_array[i,j][0],img_array[i,j][1],img_array[i,j][2]))
