from django.conf.urls import url
from django.contrib import admin

# redirect 重定向
from django.shortcuts import HttpResponse,render,redirect
from app01 import models

def index(request):
    # 业务逻辑
    # 返回结果
    ## 返回一个字符串
    ## return HttpResponse("index.html")
    ## 返回一个HTML界面


    # orm的测试
    # from app01 import models
    # ret = models.User.objects.all()  # QuerySet 对象列表

    # 获取指定名字和密码的数据
    # # get 方法特点，只能获取一条数据  0 或多条数据对象都会报错
    # ret = models.User.objects.get(username='root',password='123')
    # # fitter 可以获取多条数据对象
    # ret = model.User.objects.fitter(password='123')
    return render(request,'index.html')

def login(request):
    # 业务逻辑

    # 返回结果
    ## 返回一个字符串
    ## return HttpResponse("index.html")
    ## 返回一个HTML界面
    if request.method == 'GET':
        return render(request,'login.html')
    elif request.method == 'POST':
        # 处理POST 逻辑
        # 获取用户提交的用户名和密码
        # 进行校验
        # 校验失败 返回登录界面
        ## user = request.POST['user']
        ## pwd = request.POST['pwd']
        ##
        ## print(user,pwd)
        ## return HttpResponse("123")

        user = request.POST.get('user')
        pwd = request.POST.get('pwd')

        ret = models.User.objects.filter(username=user,password=pwd).count()
        if ret>0:
            # return redirect("http://www.baidu.com")
            return redirect("/index/")
        else:
            return render(request,'login.html')

