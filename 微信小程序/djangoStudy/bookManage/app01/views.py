from django.shortcuts import render, redirect
from app01 import models
# Create your views here.

# 出版社信息
def publisher_list(request):
    # 逻辑
    # 获取所有出版社信息
    all_publishers = models.Publisher.objects.all().order_by('id')  # 对象列表   按照id进行排序
    # 返回一个界面，页面中包含所有出版社的信息

    return render(request,"publisher_list.html",context={"all_publishers":all_publishers})

def publisher_add(request):
    """
    post 请求
    获取用户提交的数据
    将数据新增到数据库中
    返回一个重定向到展示出版社的页面
    """
    if request.method=='POST':
        pub_name = request.POST.get('pub_name')
        if not pub_name:
            return render(request,'publisher_add.html',{'error':'出版社名称不能为空'})

        # 是否有重复
        if models.Publisher.objects.filter(name=pub_name):
            # 数据库中有重复的名字
            return render(request,'publisher_add.html',{'error':'出版社已经存在'})
        # 将数据新增到数据库中
        ret = models.Publisher.objects.create(name=pub_name)
        print(ret)
        # 返回一个重定向到展示出版社的页面
        return redirect("/publisher_list/")

    return render(request, "publisher_add.html")

def publisher_del(request):
    # 获取要删除数据的pk
    pk = request.GET.get('pk')
    # 查询到一个对象，删除该对象
    models.Publisher.objects.get(id=pk).delete()
    # 返回重定向到展示出版社的列表
    return redirect("/publisher_list/")

def publisher_edit(request):
    # 获取要删除数据的pk
    pk = request.GET.get('pk')
    # 查询到一个对象，编辑该对象
    pub_obj = models.Publisher.objects.get(id=pk)

    if request.method=='GET':
        # 返回一个页面 页面包含form 表单  input有原始的数据
        return render(request,'publisher_edit.html',{'pub_obj':pub_obj})
    else:
        # post
        # 获取用户提交出版社的名称
        pub_name = request.POST.get('pub_name')
        # 修改数据库中对应的数据
        pub_obj.name=pub_name # 只是在内存中修改了
        pub_obj.save()  # 将修改操作提交到数据库
        # 返回重定向到展示出版社的列表
        return redirect("/publisher_list/")
