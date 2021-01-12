from django.shortcuts import render,HttpResponse
from django.views import View

# Create your views here.

def template_test(request):
    num = 1
    string = 'alex is dsb'
    name_list = ['天然','老毕','老王']
    dic = {'name':'alex','age':'73'}
    tup = ('天然','老毕','老王')
    name_set = {'天然','老毕','老王'}

    class Person:
        def __init__(self,name,age):
            self.name = name
            self.age = age

        def talk(self):
            return "加油，打工人~"

        def __str__(self):
            return "<Person Object {} {}>".format(self.name,self.age)

    alex = Person('alex',73)


    return render(request,"template_test.html",{
        'num':num,
        'string': string,
        'name_list': name_list,
        'dic': dic,
        'tup': tup,
        'name_set': name_set,
        'alex': alex,
    })

class Upload(View):

    def get(self,request):
        return render(request,'upload.html')

    def post(self,request):
        # 获取文件对象
        file = request.FILES.get('f1')
        with open(file.name,'wb') as f:
            for i in file:
                f.write(i)
        return HttpResponse("ok")


