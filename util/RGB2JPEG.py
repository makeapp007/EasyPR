from PIL import Image
img=Image.new('RGB',(640,480),(0,0,0))
img_array=img.load()
for i in range(img.size[0]):
	for j in range(img.size[1]):
		line=input().split()
		try:
			r,g,b=float(line[0]),float(line[1]),float(line[2])
			r,g,b=int(r//1),int(g//1),int(b//1)
		except:
			r,g,b=int(1),int(1),int(1)
		img.putpixel([i,j],(r,g,b))
# img.save("t.jpg")
img.show()