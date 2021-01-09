from django.http import HttpResponse
from django.shortcuts import render

from .models import *

# Create your views here.

def toLogin_view(request):
    return render(request,'login.html')

def Login_view(request):
    user = request.POST.get("user",'')
    pwd = request.POST.get("pwd",'')

    if user and pwd:
        c = PollsStudentinfo.objects.filter(stu_name=user,stu_psw=pwd).count()
        if c>=1:
            return HttpResponse("登录成功")
        else:
            return HttpResponse("账号密码错误")
    else:
        return HttpResponse("请输入正确的账号和密码")


def Register_view(request):
    user = request.POST.get("user", '')
    pwd = request.POST.get("pwd", '')

    if user and pwd:
        stu = PollsStudentinfo(stu_name=user, stu_psw=pwd)
        stu.save()
        return HttpResponse("注册成功")

    else:
        return HttpResponse("请输入完整的账号和密码")

def toRegister_view(request):
    # 渲染一个页面
    return render(request,"register.html")

