from django.conf.urls import url
from django.contrib import admin

# redirect 重定向
from django.shortcuts import HttpResponse,render,redirect

def index(request):
    # 业务逻辑

    # 返回结果
    ## 返回一个字符串
    ## return HttpResponse("index.html")
    ## 返回一个HTML界面
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

        if user=="root" and pwd=="123":
            # return redirect("http://www.baidu.com")
            return redirect("/index/")
        else:
            return render(request,'login.html')

