#! /usr/bin/python
# filename : scandir.py
# author : Jesse
# update : 2011/08/15 10:16

import sys,os,re

def check(obj):
	print('========')
	print('File : {}'.format(obj))
	print('========')
	codefile = open(obj,'r')
	dep_sys_list=[]
	dep_dir_list=[]
	for i in codefile.readlines():
		if re.match(r'[\t\n\r\v]*#include[/s/S]*',i):
			dep_sys_list.extend([j[1:-1] for j in re.findall(r'\<[^\<\>]+\>',i)])
			dep_dir_list.extend([j[1:-1] for j in re.findall(r'\"[^\<\>]+\"',i)])
	if dep_sys_list:print('system dependences : {}'.format(dep_sys_list))
	if dep_dir_list:print('directory dependences : {}'.format(dep_dir_list))
	codefile.close()
	print()
	print()

def scandir(startdir) :
	os.chdir(startdir)
	for obj in os.listdir(os.curdir) :
		if re.match(r'[\s\S]+(.cpp)$|[\s\S]+(.h)$',obj):
			check(startdir+'/'+obj)
		if os.path.isdir(obj) :
			scandir(startdir+'/'+obj)
			os.chdir(os.pardir) 

def getdir():
	path = sys.path[0]
	if os.path.isdir(path):
		return path
	elif os.path.isfile(path):
		return os.path.dirname(path)

print('dependences anylise')
print('========')
print()
print()
startdir = getdir()
scandir(startdir)